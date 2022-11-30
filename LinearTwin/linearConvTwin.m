clear;

%1-D linear convection with osciliations
a = 1;
omega = 2*pi * 20;


N = 128 * 1;
xs = linspace(0,1,N+1);
xc = (xs(1:end-1) + xs(2:end)) * 0.5;
hc = xs(2:end) - xs(1:end-1);

ithis = 1:N;
ileft = circshift(ithis,1);
iright = circshift(ithis,-1);

hleft = hc(ileft);
hright = hc(iright);

u0 = [sin(xc*2*pi); 0 * xc];

us = u0;
CFL = 0.5;
Tin = 0.1;
dt = CFL * max(hc)/abs(a)
dtInternal = 2*pi/omega * Tin
t = 0;
see = 8;
Apre = fjacobian(xc,us,hleft,hright,ileft,iright,hc,omega,a);


iterEnd = round(1/dt);
for iter = 1:iterEnd
    %BackEuler
    usnew = CFLNewtonSolve(us,hc,a,...
        dt,1e2, 1,...
        @(uc) Apre, ...
        @(uc) fdudt(xc,uc,hleft,hright,ileft,iright,hc,omega,a) + (us - uc)/dt...
        );
    %BackEuler
    
    %RK2
%         dudt0 = fdudt(xc,us,hleft,hright,ileft,iright,hc,omega,a);
%         us1 = us + dt * dudt0;
%         dudt1 = fdudt(xc,us1,hleft,hright,ileft,iright,hc,omega,a);
%         usnew = 0.5 * us + 0.5 * us1 + 0.5 * dt * dudt1;
    %RK2
    
    t = t + dt;
    us = usnew;
    if(mod(iter,see) == 0 || iter == iterEnd)
        figure(111);
        plot(xc,us(1,:));
        ylim([-1,1]);
        drawnow;
    end
end




function dudt = fdudt(xc,us,hleft,hright,ileft,iright,hc,omega,a)
dleft = (us - us(:,ileft)) ./hleft;
dright = (us(:,iright) - us) ./hright;
uleft = -dleft .* hc * 0.5 + us;
uright = dright .* hc * 0.5 + us;

fleft_uleft = uright(:,ileft);
fleft_uright = uleft;

fleft_f = 0.5 * ((a*fleft_uleft + a*fleft_uright) - ...
    abs(a)*(fleft_uright - fleft_uleft));

source = [us(2,:);-omega^2 * us(1,:)] * 1;

dudt = source + (fleft_f - fleft_f(:,iright)) ./hc;
end

function A = fjacobian(xc,us,hleft,hright,ileft,iright,hc,omega,a)
N = size(xc,2);
A = sparse(N*2,N*2);
for i = 1:N
    iL = ileft(i);
    iR = iright(i);
    JL = 0.5 * ( - eye(2) * a - eye(2) * a) / hc(i);
    JR = 0.5 * ( - eye(2) * a + eye(2) * a) / hc(i);
    JC = ([0 1; -omega^2, 0] * hc(i) + (0.5 * a + 0.5 * a) *eye(2)) / hc(i);
    
    A(2*i-1:2*i,2*iL-1:2*iL) = JL;
    A(2*i-1:2*i,2*iR-1:2*iR) = JR;
    A(2*i-1:2*i,2*i -1:2*i ) = JC;
    
end

end

function uNew = CFLNewtonSolve(us,hc,a,...
    dt,CFLin, alphaDiag,...
    getJacobi, getRHS)

N = size(us,2);
dtau = CFLin * hc/abs(a);
dtau = [dtau;dtau];
innerMax = 1000;
innerTh = 1e-3;
uNew = us;

fprintf("innerSolve: \n");
for iter = 1:innerMax
    A = getJacobi(uNew);
    mat = A * alphaDiag + spdiags(1./dtau(:), 0,N*2,N*2) + speye(N*2,N*2)*(1/dt);
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




