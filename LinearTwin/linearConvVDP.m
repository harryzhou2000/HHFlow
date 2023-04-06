clear;

mylines = getFileLines('linearConvVDP.m');
%1-D linear convection with osciliations

a = 1;


h = 1;
% omega =  2 * pi * 3;
% % mu = 1;Tmax = 0.35;
% % mu = 4;Tmax = 0.5437;

Tmax = 1;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% omega =  2 * pi * 1.05; mu = 1;

y0 = [2.000000e+00, 3.221859e+00];
omega=10.2035; mu=4;

% y0 = [2.000000e+00, 2.662297e+00];
% omega=162.837; mu=100;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
%0=backEuler, 1=sdirk4, 2=rk2, 3=AM4, 4=BDF
odeMethod = 11;
see = 10;
CFL = 0.5 * 1e-0;
CFLin = 100;
Tin = 0.1;

N = 25 * 4;

AMOrder = 2;
BDFOrder = 3;
SDIRKTYPE = 2;






% van der pol equation:
% dydt = [y(2); omega*(mu*(1-y(1)^2)*y(2)-y(1))];


%%


xs = linspace(0,1,N+1);
xc = (xs(1:end-1) + xs(2:end)) * 0.5;
hc = xs(2:end) - xs(1:end-1);

ithis = 1:N;
ileft = circshift(ithis,1);
iright = circshift(ithis,-1);

hleft = hc(ileft);
hright = hc(iright);

field.hleft  = hleft ;
field.hright = hright;
field.ileft  = ileft ;
field.iright = iright;
field.hc     = hc    ;
field.omega  = omega ;
field.a      = a     ;
field.mu     = mu    ;
field.h      = h    ;
field.fsource =  @(t,u)  [u(2); - omega^2*u(1) + omega * mu * (1-(u(1)/h)^2) * u(2)];

%%

% u0F1 = @(xc) 2*sin(xc*2*pi);
% u0F2 = @(xc) 0 * xc;
% u0 = [u0F1(xc); u0F2(xc)];
options = odeset('InitialStep',1/a * 1e-3,'RelTol',1e-8);
solAA = ode15s(field.fsource,[0,1/a],y0',options);
u0 = deval(solAA,1/a-xc / a);

% uanaF = @(u0F1,u0F2,t) ...
%     [cos(omega*t).*u0F1(xc-a*t)+1/omega*sin(omega*t).*u0F2(xc-a*t);...
%     -omega*sin(omega*t).*u0F1(xc-a*t)+cos(omega*t).*u0F2(xc-a*t)];

% uana = uanaF(u0F1,u0F2,Tmax);
size_u = size(u0);


us = u0;
rhs0 = fdudt(xc,us,field);

dt = CFL * max(hc)/abs(a)
dtInternal = 2*pi/omega * Tin
t = 0;

Apre = fjacobian(xc,us,field);
ApreNosource = fjacobianNosource(xc,us,field);
ApreDiagSource = fjacobianDiagSource(xc,us,field);
ApreOnlySource = fjacobianOnlysource(xc,us,field);

fEnergy = @(u) sum((u(1,:).^2 +double(omega>0)* u(2,:).^2 / (omega^2 + 1e-100)) * 0.5,'all');

energy0 = fEnergy(u0);

iterEnd = round(Tmax/dt);

rhsPrevAM = cell(1,3);
uPrevAM = cell(1,3);

uPrevAM{1} = u0; %actual
uPrevAM{2} = u0; %virtual
uPrevAM{3} = u0; %virtual



rhsPrevAM{1} = rhs0(:);
rhsPrevAM{2} = rhs0(:);
rhsPrevAM{3} = rhs0(:);
dtPrevAM = [nan, nan, nan];

uPrevBDF = cell(1,4);
uPrevBDF{1} = u0(:); %actual
uPrevBDF{2} = u0(:); %virtual
uPrevBDF{3} = u0(:); %virtual
uPrevBDF{4} = u0(:); %virtual
dtPrevBDF = nan(4,1);

for iter = 1:iterEnd
    
    switch odeMethod
        case 0
            %BackEuler
            usnew = CFLNewtonSolve(us,hc,a,...
                dt,1e10, 1,...
                @(uc) Apre, ...
                @(uc) fdudt(xc,uc,field) + (us - uc)/dt...
                );
            %BackEuler
        case -1
            %BackEuler
            usStarNew = [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
                -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            usStarIntNew = [us(1,:) * sin(omega*dt)/omega - us(2,:)/omega^2*cos(omega*dt);...
                us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt)];
            usStarInt0 = [ - us(2,:)/omega^2;...
                us(1,:) ];
            usStarAV = (usStarIntNew - usStarInt0)/dt;
            
            fluxDiffUstarNew = fdudtNosource(xc,usStarNew,field);
            fluxDiffUstar = fdudtNosource(xc,us,field);
            fluxDiffUstarAV = fdudtNosource(xc,usStarAV,field);
            sstarNew = fdudtOnlysource(xc,usStarNew,field);
            sstar = fdudtOnlysource(xc,us,field);
            
            vsnew = CFLNewtonSolve(us * 0,hc,a,...
                dt,1e3, 1,...
                @(uc) ApreNosource, ...
                @(uc) fdudtNosource(xc,uc,field) +...
                fdudtOnlysource(xc,uc*0+usStarNew,field)*0-sstarNew*0+...
                (- uc)/dt + ...
                (fluxDiffUstarNew *1 + fluxDiffUstar *0 + fluxDiffUstarAV*0)...
                );
            usnew = vsnew + usStarNew;
            %BackEuler
        case -2
            %Back2
            usStarF = @(us,dt) [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
                -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            usStarNew = usStarF(us,dt);
            usStarIntF = @(us,dt) [us(1,:) * sin(omega*dt)/omega - us(2,:)/omega^2*cos(omega*dt);...
                us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt)];
            usStarIntNew = usStarIntF(us,dt);
            usStarInt0 = usStarIntF(us,0);
            usStarAV = (usStarIntNew - usStarInt0)/dt;
            
            fluxDiffUstarNew = fdudtNosource(xc,usStarNew,field);
            fluxDiffUstar = fdudtNosource(xc,us,field);
            fluxDiffUstarAV = fdudtNosource(xc,usStarAV,field);
            vsnew = CFLNewtonSolve(us * 0,hc,a,...
                dt,1e3, 1,...
                @(uc) Apre * 0.5, ...
                @(uc) fdudtNosource(xc,uc,field)*0.5 + (- uc)/dt + ...
                fdudtNosource(xc,usStarAV,field)+...
                fdudtOnlysource(xc,uc,field)*0.5...
                );
            usnew = vsnew + usStarNew;
            %Back2
        case -21
            %Back3
            usStarF = @(us,dt) [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
                -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            usStarNew = usStarF(us,dt);
            usStarNewp2 = usStarF(us,-dt);
            usStarIntNew = [us(1,:) * sin(omega*dt)/omega - us(2,:)/omega^2*cos(omega*dt);...
                us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt)];
            usStarInt0 = [ - us(2,:)/omega^2;...
                us(1,:) ];
            vp2 = uPrevAM{2} - usStarNewp2 ;
            usStarAV = (usStarIntNew - usStarInt0)/dt;
            fluxDiffUstarNew = fdudtNosource(xc,usStarNew,field);
            fluxDiffUstar = fdudtNosource(xc,us,field);
            fluxDiffUstarAV = fdudtNosource(xc,usStarAV,field);
            vsnew = CFLNewtonSolve(us * 0,hc,a,...
                dt,1e3, 1,...
                @(uc) ApreNosource * 5/12, ...
                @(uc) fdudtNosource(xc,uc,field)*5/12 + (- uc)/dt + ...
                (fluxDiffUstarNew) + ...
                fdudtNosource(xc,vp2,field)*(-1/12) ...
                );
            usnew = vsnew + usStarNew;
            uPrevAM = circshift(uPrevAM,1);
            uPrevAM{1} = usnew;
            %Back3
        case -22
            %Back3 A
            usStarF = @(us,dt) [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
                -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            usStarNew = usStarF( uPrevAM{2},dt * 2);
            usStarNewp1 = usStarF( uPrevAM{2}, dt);
            vp1 = us - usStarNewp1 ;
%             vp2 = 0;
            
            
            fluxDiffUstarNew = fdudtNosource(xc,usStarNew,field);
            fluxDiffUstar = fdudtNosource(xc,usStarNewp1,field);
            
            vsnew = CFLNewtonSolve(vp1,hc,a,...
                dt,1e3, 1,...
                @(uc) ApreNosource * 5/12, ...
                @(uc) fdudtNosource(xc,uc,field)*5/12 + (vp1- uc)/dt + ...
                (fluxDiffUstarNew) + ...
                fdudtNosource(xc,vp1,field)*(8/12) ...
                );
            usnew = vsnew + usStarNew;
            uPrevAM = circshift(uPrevAM,1);
            uPrevAM{1} = usnew;
            %Back3
        case 1
            % SDIRK4
            usStarNew = [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
                -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            usnew =  ...
                odeSDIRK4_CFLDamped(us,...
                @(u, tnode) fdudt(xc,u,field),...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) fjacobian(xc,u,field), ...
                dt,...
                SDIRKTYPE);
            %
        case 11
            % SDIRK4 precon
            dPrecon = ones(size(us));
            dPrecon(2,:) = 1/omega;
            ndof = numel(us);
            usnew =  ...
                odeSDIRK4_CFLDamped(us.*dPrecon,...
                @(u, tnode) fdudt(xc,u./dPrecon,field).*dPrecon,...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) spdiags(dPrecon(:),0,ndof,ndof)*...
                fjacobian(xc,u./dPrecon,field)...
                *spdiags(1./dPrecon(:),0,ndof,ndof), ...
                dt,...
                SDIRKTYPE)...
                ./dPrecon;
            %
        case 12
            % SDIRK4 precon split
            dPrecon = ones(size(us));
            dPrecon(2,:) = 1/omega;
            ndof = numel(us);
%             usStarF no good for VDP!
% % % %             usStarF = @(us,dt) [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
% % % %                 -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            usStarNew = split_solve_source(xc, us, field, dt);
            
            
% % % %             usnew =  ...
% % % %                 odeSDIRK4_CFLDamped(us.*dPrecon * 0,...
% % % %                 @(u, tnode) fdudt(xc,u./dPrecon+us,field).*dPrecon...
% % % %                 -fdudtOnlysource(xc,usStarF(us,dt * tnode),field).*dPrecon,...
% % % %                 @(u) CFLin * [hc;hc]/abs(a), ...
% % % %                 @(u) spdiags(dPrecon(:),0,ndof,ndof)*...
% % % %                 fjacobian(xc,u./dPrecon,field)...
% % % %                 *spdiags(1./dPrecon(:),0,ndof,ndof), ...
% % % %                 dt,...
% % % %                 SDIRKTYPE)...
% % % %                 ./dPrecon + usStarNew;
            % simpliy godunov split
            usnew =  ...
                odeSDIRK4_CFLDamped(usStarNew.*dPrecon,...
                @(u, tnode) fdudtNosource(xc,u./dPrecon,field).*dPrecon, ...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) spdiags(dPrecon(:),0,ndof,ndof)*...
                fjacobianNosource(xc,u./dPrecon,field)...
                *spdiags(1./dPrecon(:),0,ndof,ndof), ...
                dt,...
                SDIRKTYPE)...
                ./dPrecon;
            %
        
        case -4
            % SDIRK4
            usStarF = @(dt) [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
                -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            usStarIntF = @(dt) [us(1,:) * sin(omega*dt)/omega - us(2,:)/omega^2*cos(omega*dt);...
                us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt)];
            usStarAV = (usStarIntF(dt) - usStarIntF(0))/dt;
            
            vsnew =  ...
                odeSDIRK4_CFLDamped(us*0,...
                @(u, tnode) fdudtNosource(xc,u,field) + ...
                fdudtNosource(xc,usStarF(dt),field),...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) fjacobianNosource(xc,u,field), ...
                dt);
            usnew = vsnew + usStarF(dt);
            %
        case -4000
            % SDIRK4
            usStarF = @(us,dt) [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
                -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            
            vsnew =  ...
                odeSDIRK4_CFLDamped(us*0,...
                @(u, tnode) fdudtNosource(xc,u,field) + ...
                fdudtNosource(xc,usStarF(us,0),field),...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) fjacobianNosource(xc,u,field), ...
                dt);
            usnew = vsnew + usStarF(us,0);
            usnew = usStarF(usnew,dt);
            %
        case 3
            % AM
            [usnew, dtPrevAM, rhsPrevAM] =  ...
                odeAdamsMoultonFixed_CFLDamped(us,...
                @(u) fdudt(xc,u,field),...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) fjacobian(xc,u,field), ...
                dt,rhsPrevAM,dtPrevAM, min(iter, AMOrder-1));
        case -3
            % AM
            usStarF = @(us,dt) [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
                -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            usStarNew = usStarF(us,dt);
            fluxDiffUstarNew = fdudtNosource(xc,usStarNew,field);
            nprevs = min(iter-1, 1);
            for i = 1:nprevs
               rhsPrevAM{i} = fdudtNosource(xc,usStarF(us,dt*(1-i)),field)...
                   + fdudtNosource(xc,uPrevAM{i} - usStarF(us,dt*(1-i)),field);
               rhsPrevAM{i} = reshape(rhsPrevAM{i},[],1);
            end
            
            [vsnew, dtPrevAM, rhsPrevAM] =  ...
                odeAdamsMoultonFixed_CFLDamped_SPLIT(us*0,...
                @(u) fdudtNosource(xc,u,field) + 1*fluxDiffUstarNew ,...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) fjacobianNosource(xc,u,field), ...
                dt,rhsPrevAM,dtPrevAM, nprevs,...
                0*fluxDiffUstarNew);    
            
            usnew = vsnew + usStarNew;
            uPrevAM = circshift(uPrevAM,1);
            uPrevAM{1} = usnew;
            
            rhsPrevAM{1} = rhsPrevAM{1} +1* reshape(...
                fdudtOnlysource(xc,usStarNew,field),[],1);
        case 2
            %RK2
            dudt0 = fdudt(xc,us,field);
            us1 = us + dt * dudt0;
            dudt1 = fdudt(xc,us1,field);
            usnew = 0.5 * us + 0.5 * us1 + 0.5 * dt * dudt1;
            %RK2
        case 27
            %RK2 Iterative
            usStarF = @(us,dt) [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
                -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            
            dudt0 = fdudtNosource(xc,us,field);
            us1 = us + dt * dudt0;
            dudt1 = fdudtNosource(xc,us1,field);
            usnew = 0.5 * us + 0.5 * us1 + 0.5 * dt * dudt1;
            %RK2
        case 4
            % BDF
            [usnew, dtPrevBDF, uPrevBDF] =  ...
                odeBDFFixed_CFLDamped(us,...
                @(u) fdudt(xc,u,field),...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) fjacobian(xc,u,field), ...
                dt,uPrevBDF,dtPrevBDF, min(iter, BDFOrder));
        case 41
            % BDF2 with precon
            usStarF = @(us,dt) [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
                -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            
            dPrecon = ones(size(us));
            dPrecon(2,:) = 1/omega;
            if(iter == 1)
               for i = 1:numel(uPrevBDF)
                  uPrevBDF{i} = uPrevBDF{i} .* dPrecon(:); 
               end
            end
            [usnew, dtPrevBDF, uPrevBDF] =  ...
                odeBDFFixed_CFLDamped(us.*dPrecon,...
                @(u) fdudt(xc,u./dPrecon,field).*dPrecon,...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) diag(dPrecon(:))*...
                    fjacobian(xc,u./dPrecon,field)*diag(1./dPrecon(:)), ...
                dt,uPrevBDF,dtPrevBDF, min(iter, BDFOrder));
            usnew = usnew ./ dPrecon;
         case 42
            % BDF2 with precon, and use u v splitting
            nprev = min(iter, BDFOrder);
            usStarF = @(us,dt) [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
                -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            usStarIntF = @(us,dt) [us(1,:) * sin(omega*dt)/omega - us(2,:)/omega^2*cos(omega*dt);...
                us(1,:) * cos(omega*dt) + us(2,:)*sin(omega*dt)/omega];
            
            
            dPrecon = ones(size(us));
            dPrecon(2,:) = 1/omega;
            if(iter == 1)
               for i = 1:numel(uPrevBDF)
                  uPrevBDF{i} = uPrevBDF{i} .* dPrecon(:); 
               end
            end
            ubase = reshape(uPrevBDF{nprev},size(us)) ./ dPrecon;
            for i = 1:numel(uPrevBDF) % convert u to v
                uPrevBDF{i} = uPrevBDF{i} - reshape(usStarF(ubase,(nprev-i) * dt),[],1) .* dPrecon(:);
            end
            uStarNew = usStarF(ubase,(nprev-0) * dt);
            usStarMean = (usStarIntF(ubase, (nprev-0) * dt)-usStarIntF(ubase, (nprev-1) * dt))/dt;
            [usnew, dtPrevBDF, uPrevBDF] =  ...
                odeBDFFixed_CFLDamped(reshape(uPrevBDF{1},size(us)),...
                @(u) fdudt(xc,u./dPrecon+usStarMean,field).*dPrecon -0* ...
                     fdudtOnlysource(xc,uStarNew,field).*dPrecon -1* ...
                     (uStarNew - usStarF(ubase,(nprev-1) * dt)).*dPrecon/dt,...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) diag(dPrecon(:))*...
                    fjacobian(xc,u./dPrecon+uStarNew,field)*diag(1./dPrecon(:)), ...
                dt,uPrevBDF,dtPrevBDF, nprev);
            usnew = usnew ./ dPrecon + uStarNew;
            for i = 1:numel(uPrevBDF) % convert v to u
                uPrevBDF{i} = uPrevBDF{i} + reshape(usStarF(ubase,(nprev-i+1) * dt),[],1) .* dPrecon(:);
            end
        otherwise
            error('nosuchcode');
    end
    
    t = t + dt;
    us = usnew;
    energy = fEnergy(us);
    fprintf('Energy Err: %.3e\n', 1-energy/ energy0);
    if(mod(iter,see) == 0 || iter == iterEnd || iter == 1)
        
        figure(111);
        plot(xc,us(1,:),xc,us(2,:)/omega);
        ylim([-2,2]);
        drawnow;
        if(iter == 1)
            figure(111);
            plot(xc,u0(1,:),xc,u0(2,:)/omega);
            ylim([-2,2]);
            drawnow;
        end
    end
    if(energy/ energy0 > 5)
        %         warning("divergence! \n");
%         break;
    end
end



% fprintf('Err: %.3e\n', sum(hc.*abs(uana(1,:)-us(1,:))));

figure(111);
% hold on;plot(xc, uana(1,:));hold off;
% legend('u1','u2','u1_{ana}');

hold on;plot(xc, u0(1,:));hold off;
legend('u1','u2','u1_{0}');


%%
function dudt = fdudtNosource(xc,us,field)
hleft = field.hleft ;
hright= field.hright;
ileft = field.ileft ;
iright= field.iright;
hc    = field.hc    ;
a     = field.a;

recF = 1-0e-3;
dleft = (us - us(:,ileft)) ./hleft;
dright = (us(:,iright) - us) ./hright;
% dcenter= 0.5 * (dleft + dright);
dcenter = F_TVD_Slope(dleft,dright);
uleft = -dcenter .* hc * 0.5 * recF+ us;
uright = dcenter .* hc * 0.5 * recF+ us;



% % 3rd:
% uLD = us(:,ileft) - us;
% uRD = us(:,iright) - us;
% aR = -(uLD + uRD)/24;
% bR = (uRD - uLD)/2./hc;
% cR = (uRD + uLD)./(2*hc.^2);
% uleft = us + aR + bR .* (-hc/2) + cR.*(-hc/2).^2;
% uright = us + aR + bR .* (hc/2) + cR.*(hc/2).^2;
% %

% % 0th rec
% uleft = us; 
% uright = us;
% %

fleft_uleft = uright(:,ileft);
fleft_uright = uleft;

fleft_f = 0.5 * ((a*fleft_uleft + a*fleft_uright) - ...
    abs(a)*(fleft_uright - fleft_uleft));
dudt = (fleft_f - fleft_f(:,iright)) ./hc;

if( sum(isnan(dudt)))
   error("BAD rhs!"); 
end
end

function dudt = fdudtOnlysource(xc,us,field)


omega = field.omega ;
mu    = field.mu;
h     = field.h;
hc    = field.hc    ;
% van der pol equation:
% dydt = [y(2); omega^2*(mu*(1-y(1)^2)*y(2)-y(1))];

source = [us(2,:);-omega^2 * us(1,:) + mu*omega* (1-(us(1,:)/h).^2).*us(2,:) ] * 1;

dudt = source;

if( sum(isnan(dudt)))
   error("BAD rhs!"); 
end
end

function dudt = fdudt(xc,us,field)


nosource =fdudtNosource(xc,us,field);
source =fdudtOnlysource(xc,us,field);

dudt = source + nosource;
end

function A = fjacobian(xc,us,field)

hleft = field.hleft ;
hright= field.hright;
ileft = field.ileft ;
iright= field.iright;
hc    = field.hc    ;
omega = field.omega ;
a     = field.a     ;
h     = field.h     ;
mu    = field.mu    ;

N = size(xc,2);
% % % A = sparse(N*2,N*2);
iss = nan(N*3*4,1);
jss = nan(N*3*4,1);
vss = nan(N*3*4,1);
for i = 1:N
    iL = ileft(i);
    iR = iright(i);
    JL = -0.5 * ( - eye(2) * a - eye(2) * a) / hc(i);
    JR = -0.5 * ( - eye(2) * a + eye(2) * a) / hc(i);
    JC = ([0 1; ...
        -omega^2 - 2*mu*omega * us(2,i) * us(1,i)/h^2 , ...
        mu*omega* (1-(us(1,i)/h).^2)]...
        * hc(i) - (0.5 * a + 0.5 * a) *eye(2)) / hc(i);
    imL = repmat(2*i-1:2*i  ,2,1)';
    jmL = repmat(2*iL-1:2*iL,2,1);
    jmR = repmat(2*iR-1:2*iR,2,1);
    jmC = imL'; % mind that 
    
    ssstart = (i-1)*3*4;
    iss( ssstart + 1: ssstart + 4) = imL(:);
    jss( ssstart + 1: ssstart + 4) = jmL(:);
    vss( ssstart + 1: ssstart + 4) = JL(:);
    iss( ssstart + 5: ssstart + 8) = imL(:);
    jss( ssstart + 5: ssstart + 8) = jmR(:);
    vss( ssstart + 5: ssstart + 8) = JR(:);
    iss( ssstart + 9: ssstart + 12) = imL(:);
    jss( ssstart + 9: ssstart + 12) = jmC(:); 
    vss( ssstart + 9: ssstart + 12) = JC(:);
    

% % %     A(2*i-1:2*i,2*iL-1:2*iL) = JL;
% % %     A(2*i-1:2*i,2*iR-1:2*iR) = JR;
% % %     A(2*i-1:2*i,2*i -1:2*i ) = JC;
    
end
A = sparse(iss,jss,vss,N*2,N*2);

if( sum(isnan(A)))
   error("BAD jacobian"); 
end

end

function A = fjacobianDiagSource(xc,us,field)

hleft = field.hleft ;
hright= field.hright;
ileft = field.ileft ;
iright= field.iright;
hc    = field.hc    ;
omega = field.omega ;
mu    = field.mu    ;
a     = field.a     ;
h     = field.h     ;

N = size(xc,2);
A = sparse(N*2,N*2);
for i = 1:N
    iL = ileft(i);
    iR = iright(i);
    JL = -0.5 * ( - eye(2) * a - eye(2) * a) / hc(i);
    JR = -0.5 * ( - eye(2) * a + eye(2) * a) / hc(i);
    %[0 1; -omega^2, 0]
    JC = ([0 1; ...
        -omega^2 - 2*mu*omega * us(2,i) * us(1,i)/h^2 , ...
        mu*omega* (1-(us(1,i)/h).^2)]...
        * hc(i)) / hc(i);
    
    A(2*i-1:2*i,2*iL-1:2*iL) = JL;
    A(2*i-1:2*i,2*iR-1:2*iR) = JR;
    A(2*i-1:2*i,2*i -1:2*i ) = JC;
    
end

end

function A = fjacobianNosource(xc,us,field)

hleft = field.hleft ;
hright= field.hright;
ileft = field.ileft ;
iright= field.iright;
hc    = field.hc    ;
omega = field.omega ;
a     = field.a     ;
h     = field.h     ;
mu    = field.mu    ;

N = size(xc,2);
% % % A = sparse(N*2,N*2);
iss = nan(N*3*4,1);
jss = nan(N*3*4,1);
vss = nan(N*3*4,1);
for i = 1:N
    iL = ileft(i);
    iR = iright(i);
    JL = -0.5 * ( - eye(2) * a - eye(2) * a) / hc(i);
    JR = -0.5 * ( - eye(2) * a + eye(2) * a) / hc(i);
    JC = -(0.5 * a + 0.5 * a) *eye(2) / hc(i);
    
    imL = repmat(2*i-1:2*i  ,2,1)';
    jmL = repmat(2*iL-1:2*iL,2,1);
    jmR = repmat(2*iR-1:2*iR,2,1);
    
    ssstart = (i-1)*3*4;
    iss( ssstart + 1: ssstart + 4) = imL(:);
    jss( ssstart + 1: ssstart + 4) = jmL(:);
    vss( ssstart + 1: ssstart + 4) = JL(:);
    iss( ssstart + 5: ssstart + 8) = imL(:);
    jss( ssstart + 5: ssstart + 8) = jmR(:);
    vss( ssstart + 5: ssstart + 8) = JR(:);
    iss( ssstart + 9: ssstart + 12) = imL(:);
    jss( ssstart + 9: ssstart + 12) = imL(:);
    vss( ssstart + 9: ssstart + 12) = JC(:);
    
% % %     A(2*i-1:2*i,2*iL-1:2*iL) = JL;
% % %     A(2*i-1:2*i,2*iR-1:2*iR) = JR;
% % %     A(2*i-1:2*i,2*i -1:2*i ) = JC;
    
end
A = sparse(iss,jss,vss,N*2,N*2);

end

function A = fjacobianOnlysource(xc,us,field)

% van der pol equation:
% dydt = [y(2); omega*(mu*(1-y(1)^2)*y(2)-y(1))];

omega = field.omega ;
h     = field.h     ;
mu    = field.mu    ;
hc    = field.hc    ;

N = size(xc,2);
A = sparse(N*2,N*2);
for i = 1:N
    JC = ([0 1; ...
        -omega^2 - 2*mu*omega * us(2,i) * us(1,i)/h^2 , ...
        mu*omega* (1-(us(1,i)/h).^2)]...
        * hc(i))/hc(i);
    A(2*i-1:2*i,2*i -1:2*i ) = JC;
end

end

function uNew = CFLNewtonSolve(us,hc,a,...
    dt,CFLin, alphaDiag,...
    getJacobi, getRHS)

N = size(us,2);
dtau = CFLin * hc/abs(a);
dtau = [dtau;dtau];
innerMax = 10000000;
innerTh = 1e-3;
uNew = us;

fprintf("\ninnerSolve: \n");
for iter = 1:innerMax
    A = getJacobi(uNew);
    mat = -A * alphaDiag + spdiags(1./dtau(:), 0,N*2,N*2) + speye(N*2,N*2)*(1/dt);
    rhs = getRHS(uNew);
    du = reshape(mat\rhs(:),size(uNew));
    uNew = uNew + du;
    
    res = max(abs(du(:)));
    if(iter == 1)
        res0 = res;
    end
    resr = res/res0;
    fprintf("resrInner %d: %.3e\n", iter, resr);
    if(resr < innerTh)
        break;
    end
    
end





end

function uNew = CFLNewtonSolveSplit(us,hc,a,...
    dt,CFLin, alphaDiag,...
    getJacobi,getJacobiSource,...
    getRHS, getRH)

N = size(us,2);
dtau = CFLin * hc/abs(a);
dtau = [dtau;dtau];
innerMax = 10000000;
innerTh = 1e-3;
uNew = us;

fprintf("\ninnerSolve: \n");
for iter = 1:innerMax
    Asource = getJacobiSource(uNew);
    A = getJacobi(uNew);
    matSource = Asource * alphaDiag + spdiags(1./dtau(:), 0,N*2,N*2) + speye(N*2,N*2)*(1/dt);
    mat = A * alphaDiag + spdiags(1./dtau(:), 0,N*2,N*2) + speye(N*2,N*2)*(1/dt);
    rhs = getRHS(uNew);
    
    
    du = mat\(matSource\rhs(:));
    
    
    du = reshape(du,size(uNew));
    uNew = uNew + du;
    
    res = max(abs(du(:)));
    if(iter == 1)
        res0 = res;
    end
    resr = res/res0;
    fprintf("resrInner %d: %.3e\n", iter, resr);
    if(resr < innerTh)
        break;
    end
end

end


function usStarNew = split_solve_source(xc, us, field, dt)
omega = field.omega ;
a     = field.a     ;
h     = field.h     ;
mu    = field.mu    ;
fsource = field.fsource;


usStarNew = us;
options = odeset('InitialStep',dt*0.001,'RelTol',1e-4);
for i = 1:size(us,2)
     sol = ode15s(fsource,[0,dt],usStarNew(:,i),options);
     usStarNew(:,i) = sol.y(:,end);
end


end



