clear;

%1-D linear convection with relaxation
a = 1;
omega = 500;

tmax = 1;
    
%0=backEuler, 1=sdirk4, 2=rk2, 3=AM4
odeMethod = 0;
see = 10;
CFL = 0.5;
CFLin = 1e200;
Tin = 0.1;
N = 25 * 2;

AMOrder = 1;


%%


xs = linspace(0,1,N+1);
xc = (xs(1:end-1) + xs(2:end)) * 0.5;
hc = xs(2:end) - xs(1:end-1);

ithis = 1:N;
ileft = circshift(ithis,1);
iright = circshift(ithis,-1);

hleft = hc(ileft);
hright = hc(iright);

u0 = [0 * xc;sin(xc*2*pi)];
ua = u0;
ua(1,:) = (ua(1,:) - ua(2,:)) * exp(-omega*tmax) + ua(2,:);

size_u = size(u0);
us = u0;

dt = CFL * max(hc)/abs(a)
dtInternal = 2*pi/omega * Tin
t = 0;

Apre = fjacobian(xc,us,hleft,hright,ileft,iright,hc,omega,a);
ApreNosource = fjacobianNosource(xc,us,hleft,hright,ileft,iright,hc,omega,a);
ApreOnlySource = fjacobianOnlysource(xc,us,hleft,hright,ileft,iright,hc,omega,a);
ApreDiagSource = fjacobianDiagSource(xc,us,hleft,hright,ileft,iright,hc,omega,a);

fEnergy = @(u) sum((u(1,:).^2 + u(2,:).^2 / (omega^2 + 1e-100)) * 0.5,'all');

energy0 = fEnergy(u0);

iterEnd = round(tmax/dt);

rhsPrevAM = cell(1,3);
uPrevAM = cell(1,3);
uPrevAM{1} = u0; %actual
uPrevAM{2} = u0; %virtual
uPrevAM{3} = u0; %virtual
dtPrevAM = [nan, nan, nan];

for iter = 1:iterEnd
    
    switch odeMethod
        case 0
            %BackEuler
            usnew = CFLNewtonSolve(us,hc,a,...
                dt,1e1, 1,...
                @(uc) Apre, ...
                @(uc) fdudt(xc,uc,hleft,hright,ileft,iright,hc,omega,a) + (us - uc)/dt...
                );
%             usnew = CFLNewtonSolve_Split(us,hc,a,...
%                 dt,0.1, 1,...
%                 @(uc) ApreNosource, ...
%                 @(uc) ApreOnlySource, ...
%                 @(uc) fdudtNosource(xc,uc,hleft,hright,ileft,iright,hc,omega,a) + (us - uc)/dt * 1,...
%                 @(uc) fdudtOnlysource(xc,uc,hleft,hright,ileft,iright,hc,omega,a) + (us - uc)/dt * 0 ...
%                 );
            %BackEuler
        case -1
            %BackEuler
            usStarF = @(us,dt) [us(2,:) + (us(1,:) - us(2,:)) * exp(-dt*omega);...
                us(2,:)];
            usStarNew = usStarF(us,dt);
            
            fluxDiffUstarNew = fdudtNosource(xc,usStarNew,hleft,hright,ileft,iright,hc,omega,a);
            fluxDiffUstar = fdudtNosource(xc,us,hleft,hright,ileft,iright,hc,omega,a);
            fluxDiffUstarAV = fdudtNosource(xc,usStarAV,hleft,hright,ileft,iright,hc,omega,a);
            sstarNew = fdudtOnlysource(xc,usStarNew,hleft,hright,ileft,iright,hc,omega,a);
            sstar = fdudtOnlysource(xc,us,hleft,hright,ileft,iright,hc,omega,a);
            
            vsnew = CFLNewtonSolve(us * 0,hc,a,...
                dt,1e3, 1,...
                @(uc) ApreNosource, ...
                @(uc) fdudtNosource(xc,uc,hleft,hright,ileft,iright,hc,omega,a) +...
                fdudtOnlysource(xc,uc*0+usStarNew,hleft,hright,ileft,iright,hc,omega,a)*0-sstarNew*0+...
                (- uc)/dt + ...
                (fluxDiffUstarNew *1 + fluxDiffUstar *0 + fluxDiffUstarAV*0)...
                );
            usnew = vsnew + usStarNew;
            %BackEuler
        case -2
            %Back2
            usStarF = @(us,dt) [us(2,:) + (us(1,:) - us(2,:)) * exp(-dt*omega);...
                us(2,:)];
            usStarNew = usStarF(us,dt);
            fluxDiffUstarNew = fdudtNosource(xc,usStarNew,hleft,hright,ileft,iright,hc,omega,a);
            
            
            vsnew = CFLNewtonSolve(us * 0,hc,a,...
                dt,1e3, 1,...
                @(uc) ApreNosource * 0.5, ...
                @(uc) fdudtNosource(xc,uc + usStarNew,hleft,hright,ileft,iright,hc,omega,a)*0.5 + (- uc)/dt + ...
                fdudtNosource(xc,usStarNew,hleft,hright,ileft,iright,hc,omega,a)*0.5+...
                fdudtOnlysource(xc,uc*1+usStarNew,hleft,hright,ileft,iright,hc,omega,a)*0.5+...
                fdudtOnlysource(xc,us,hleft,hright,ileft,iright,hc,omega,a)*(+0.5)+...
                (us - usStarNew)/dt * 1+...
                (fluxDiffUstarNew * 0)...
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
            fluxDiffUstarNew = fdudtNosource(xc,usStarNew,hleft,hright,ileft,iright,hc,omega,a);
            fluxDiffUstar = fdudtNosource(xc,us,hleft,hright,ileft,iright,hc,omega,a);
            fluxDiffUstarAV = fdudtNosource(xc,usStarAV,hleft,hright,ileft,iright,hc,omega,a);
            vsnew = CFLNewtonSolve(us * 0,hc,a,...
                dt,1e3, 1,...
                @(uc) ApreNosource * 5/12, ...
                @(uc) fdudtNosource(xc,uc,hleft,hright,ileft,iright,hc,omega,a)*5/12 + (- uc)/dt + ...
                (fluxDiffUstarNew) + ...
                fdudtNosource(xc,vp2,hleft,hright,ileft,iright,hc,omega,a)*(-1/12) ...
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
            
            
            fluxDiffUstarNew = fdudtNosource(xc,usStarNew,hleft,hright,ileft,iright,hc,omega,a);
            fluxDiffUstar = fdudtNosource(xc,usStarNewp1,hleft,hright,ileft,iright,hc,omega,a);
            
            vsnew = CFLNewtonSolve(vp1,hc,a,...
                dt,1e3, 1,...
                @(uc) ApreNosource * 5/12, ...
                @(uc) fdudtNosource(xc,uc,hleft,hright,ileft,iright,hc,omega,a)*5/12 + (vp1- uc)/dt + ...
                (fluxDiffUstarNew) + ...
                fdudtNosource(xc,vp1,hleft,hright,ileft,iright,hc,omega,a)*(8/12) ...
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
                @(u, tnode) fdudt(xc,u,hleft,hright,ileft,iright,hc,omega,a),...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) fjacobian(xc,u,hleft,hright,ileft,iright,hc,omega,a), ...
                dt);
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
                @(u, tnode) fdudtNosource(xc,u,hleft,hright,ileft,iright,hc,omega,a) + ...
                fdudtNosource(xc,usStarF(dt),hleft,hright,ileft,iright,hc,omega,a),...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) fjacobianNosource(xc,u,hleft,hright,ileft,iright,hc,omega,a), ...
                dt);
            usnew = vsnew + usStarF(dt);
            %
        case -4000
            % SDIRK4
            usStarF = @(us,dt) [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
                -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            
            vsnew =  ...
                odeSDIRK4_CFLDamped(us*0,...
                @(u, tnode) fdudtNosource(xc,u,hleft,hright,ileft,iright,hc,omega,a) + ...
                fdudtNosource(xc,usStarF(us,0),hleft,hright,ileft,iright,hc,omega,a),...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) fjacobianNosource(xc,u,hleft,hright,ileft,iright,hc,omega,a), ...
                dt);
            usnew = vsnew + usStarF(us,0);
            usnew = usStarF(usnew,dt);
            %
        case 3
            % AM
            [usnew, dtPrevAM, rhsPrevAM] =  ...
                odeAdamsMoultonFixed_CFLDamped(us,...
                @(u) fdudt(xc,u,hleft,hright,ileft,iright,hc,omega,a),...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) fjacobian(xc,u,hleft,hright,ileft,iright,hc,omega,a), ...
                dt,rhsPrevAM,dtPrevAM, min(iter-1, AMOrder-1));
        case -3
            % AM
            usStarF = @(us,dt) [us(1,:) * cos(omega*dt) + us(2,:)/omega*sin(omega*dt);...
                -omega*us(1,:) * sin(omega*dt) + us(2,:)*cos(omega*dt)];
            usStarNew = usStarF(us,dt);
            fluxDiffUstarNew = fdudtNosource(xc,usStarNew,hleft,hright,ileft,iright,hc,omega,a);
            nprevs = min(iter-1, 1);
            for i = 1:nprevs
               rhsPrevAM{i} = fdudtNosource(xc,usStarF(us,dt*(1-i)),hleft,hright,ileft,iright,hc,omega,a)...
                   + fdudtNosource(xc,uPrevAM{i} - usStarF(us,dt*(1-i)),hleft,hright,ileft,iright,hc,omega,a);
               rhsPrevAM{i} = reshape(rhsPrevAM{i},[],1);
            end
            
            [vsnew, dtPrevAM, rhsPrevAM] =  ...
                odeAdamsMoultonFixed_CFLDamped_SPLIT(us*0,...
                @(u) fdudtNosource(xc,u,hleft,hright,ileft,iright,hc,omega,a) + 1*fluxDiffUstarNew ,...
                @(u) CFLin * [hc;hc]/abs(a), ...
                @(u) fjacobianNosource(xc,u,hleft,hright,ileft,iright,hc,omega,a), ...
                dt,rhsPrevAM,dtPrevAM, nprevs,...
                0*fluxDiffUstarNew);    
            
            usnew = vsnew + usStarNew;
            uPrevAM = circshift(uPrevAM,1);
            uPrevAM{1} = usnew;
            
            rhsPrevAM{1} = rhsPrevAM{1} +1* reshape(...
                fdudtOnlysource(xc,usStarNew,hleft,hright,ileft,iright,hc,omega,a),[],1);
        case 2
            %RK2
            dudt0 = fdudt(xc,us,hleft,hright,ileft,iright,hc,omega,a);
            us1 = us + dt * dudt0;
            dudt1 = fdudt(xc,us1,hleft,hright,ileft,iright,hc,omega,a);
            usnew = 0.5 * us + 0.5 * us1 + 0.5 * dt * dudt1;
            %RK2
        otherwise
            error('nosuchcode');
    end
    
    t = t + dt;
    us = usnew;
%     energy = fEnergy(us);
%     fprintf('Energy Err: %.3e\n', 1-energy/ energy0);
    if(mod(iter,see) == 0 || iter == iterEnd)
        figure(111);
        plot(xc,us(1,:));
        ylim([-1,1]);
        drawnow;
    end
%     if(energy/ energy0 > 5)
%         warning("divergence!");
%         break;
%     end
end

fprintf('Err: %.3e\n', sum(hc.*abs(ua(1,:)-us(1,:))));

%%
function dudt = fdudtNosource(xc,us,hleft,hright,ileft,iright,hc,omega,a)
% recF = 1-0e-3;
% dleft = (us - us(:,ileft)) ./hleft;
% dright = (us(:,iright) - us) ./hright;
% dcenter= 0.5 * (dleft + dright);
% uleft = -dcenter .* hc * 0.5 * recF+ us;
% uright = dcenter .* hc * 0.5 * recF+ us;

% 3rd:
uLD = us(:,ileft) - us;
uRD = us(:,iright) - us;
aR = -(uLD + uRD)/24;
bR = (uRD - uLD)/2./hc;
cR = (uRD + uLD)./(2*hc.^2);
uleft = us + aR + bR .* (-hc/2) + cR.*(-hc/2).^2;
uright = us + aR + bR .* (hc/2) + cR.*(hc/2).^2;
%

% 0th
% uleft = us;
% uright = us;

fleft_uleft = uright(:,ileft);
fleft_uright = uleft;

fleft_f = 0.5 * ((a*fleft_uleft + a*fleft_uright) - ...
    abs(a)*(fleft_uright - fleft_uleft));
dudt = (fleft_f - fleft_f(:,iright)) ./hc;
end

function dudt = fdudtOnlysource(xc,us,hleft,hright,ileft,iright,hc,omega,a)


source = [-omega * (us(1,:) - us(2,:));zeros(size(us(1,:)))] * 1;

dudt = source;
end

function dudt = fdudt(xc,us,hleft,hright,ileft,iright,hc,omega,a)

nosource =fdudtNosource(xc,us,hleft,hright,ileft,iright,hc,omega,a);
source =fdudtOnlysource(xc,us,hleft,hright,ileft,iright,hc,omega,a);

dudt = source + nosource;
end

function A = fjacobian(xc,us,hleft,hright,ileft,iright,hc,omega,a)
N = size(xc,2);
A = sparse(N*2,N*2);
for i = 1:N
    iL = ileft(i);
    iR = iright(i);
    JL = -0.5 * ( - eye(2) * a - eye(2) * a) / hc(i);
    JR = 0.5 * ( - eye(2) * a + eye(2) * a) / hc(i);
    JC = ([-omega, omega;0, 0] * hc(i) + -(0.5 * a + 0.5 * a) *eye(2)) / hc(i);
    
    A(2*i-1:2*i,2*iL-1:2*iL) = JL;
    A(2*i-1:2*i,2*iR-1:2*iR) = JR;
    A(2*i-1:2*i,2*i -1:2*i ) = JC;
    
end

end

function A = fjacobianDiagSource(xc,us,hleft,hright,ileft,iright,hc,omega,a)
N = size(xc,2);
A = sparse(N*2,N*2);
for i = 1:N
    iL = ileft(i);
    iR = iright(i);
    JL = -0.5 * ( - eye(2) * a - eye(2) * a) / hc(i);
    JR = -0.5 * ( - eye(2) * a + eye(2) * a) / hc(i);
    JC = ([-omega, omega;0, 0] * hc(i) + -(0.5 * a + 0.5 * a) *eye(2)) / hc(i);
    
    A(2*i-1:2*i,2*iL-1:2*iL) = JL;
    A(2*i-1:2*i,2*iR-1:2*iR) = JR;
    A(2*i-1:2*i,2*i -1:2*i ) = JC;
    
end

end

function A = fjacobianNosource(xc,us,hleft,hright,ileft,iright,hc,omega,a)
N = size(xc,2);
A = sparse(N*2,N*2);
for i = 1:N
    iL = ileft(i);
    iR = iright(i);
    JL = -0.5 * ( - eye(2) * a - eye(2) * a) / hc(i);
    JR = -0.5 * ( - eye(2) * a + eye(2) * a) / hc(i);
    JC = -(0.5 * a + 0.5 * a) *eye(2) / hc(i);
    
    A(2*i-1:2*i,2*iL-1:2*iL) = JL;
    A(2*i-1:2*i,2*iR-1:2*iR) = JR;
    A(2*i-1:2*i,2*i -1:2*i ) = JC;
    
end

end

function A = fjacobianOnlysource(xc,us,hleft,hright,ileft,iright,hc,omega,a)
N = size(xc,2);
A = sparse(N*2,N*2);
for i = 1:N
    JC = ([-omega, omega;0, 0]);
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

function uNew = CFLNewtonSolve_Split(us,hc,a,...
    dt,CFLin, alphaDiag,...
    getJacobi, getJacobiSource, getRHS, getRHSSource)

N = size(us,2);
dtau = CFLin * hc/abs(a);
dtau = [dtau;dtau];
innerMax = 10000000;
innerTh = 1e-3;
uNew = us;

fprintf("\ninnerSolve: \n");
for iter = 1:innerMax
    A = getJacobi(uNew);
    Asource = getJacobiSource(uNew);
    mat = A * alphaDiag + spdiags(1./dtau(:), 0,N*2,N*2) + speye(N*2,N*2)*(1/dt) * 1;
    matsource = Asource * alphaDiag + spdiags(1./dtau(:), 0,N*2,N*2) + speye(N*2,N*2)*(1/dt) * 0;
    rhs = getRHS(uNew);
    du1 = reshape(mat\rhs(:),size(uNew));
    uNew = uNew + du1;
    
    rhs = getRHSSource(uNew);
    du2 = reshape(matsource\rhs(:),size(uNew));
    uNew = uNew + du2;
    
    du = du1 + du2;
    res = max(abs(du(:)));
    if(iter == 1)
        res0 = res;
    end
    resr = res/res0;
    fprintf("resrInner %d: %.3e\n", iter, resr);
    if(resr < innerTh)
        break;
    end
    if(resr > 10)
       error('divergence'); 
    end
    
end


end




