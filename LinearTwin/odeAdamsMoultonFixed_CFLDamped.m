function [unew, dtPrev, rhsPrev] = ...
    odeAdamsMoultonFixed_CFLDamped(u, frhs, fdTau, fjacobian, dt,...
    rhsPrev, dtPrev, nprev)
% warning, rhsPrev, dtPrev are right-shifted to fill new values at the end
usize = size(u);
u = u(:);
N = numel(u);
maxiter= 100;
innerTh = 1e-3;

for ip = 1:nprev
   assert(dtPrev(ip) == dt);
end


coefAM4 = [9,19,-5,1]/24;
coefAM3 = [5,8,-1]/12;
coefAM2 = [1,1]/2;
coefAM1 = [1];

coefs = {coefAM1,coefAM2,coefAM3,coefAM4};

uc = u;
for iter = 1:maxiter
    dtau = reshape(fdTau(reshape(uc,usize)),[],1);
    rhsc = reshape(frhs(reshape(uc,usize)),[],1);
    rhs = (u - uc) / dt + rhsc * coefs{nprev+1}(1);
    for ip = 1:nprev
        rhs = rhs + rhsPrev{ip} * coefs{nprev+1}(1+ip);
    end
    
    J = fjacobian(reshape(uc,usize));
    mat = J* coefs{nprev+1}(1) + spdiags(1./dtau(:), 0,N,N) + speye(N,N)*(1/dt);
%     condest(mat)
%     max(eigs(J))
    %         du = mat\rhs;
    [matL,matU,matP,matQ] = lu(mat);
    duS = matL\(matP*rhs);
    du = matQ*(matU\duS);
    
    uc = uc + du;
    res = sum(abs(du(:)));
    
    if(iter == 1)
        res0 = res;
    end
    resr = res/res0;
    fprintf("   === odeAM4 resrInner %d: %.3e\n", iter, resr);
    if(resr < innerTh)
        break;
    end
end
dtPrev = circshift(dtPrev,1);
dtPrev(1) = dt;
rhsPrev = circshift(rhsPrev,1);
rhsPrev{1} = rhsc;




unew = uc;

unew = reshape(unew,usize);





