function [unew, dtPrev, rhsPrev] = ...
    odeAdamsMoultonFixed_CFLDamped(u, frhs, fdTau, fjacobian, dt,...
    rhsPrev, dtPrev, nprev)
% warning, rhsPrev, dtPrev are right-shifted to fill new values at the end
usize = size(u);
u = u(:);
N = numel(u);
maxiter= 100;
innerTh = 1e-3;

block_size = usize(1);

for ip = 1:(nprev-2)
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
    [A_L,A_U,A_D] = bLUD(J,block_size);
    dtauIFix = full(sum(abs(A_L+A_U+2*A_D),2))* coefs{nprev+1}(1) * 0;
    mat = -J* coefs{nprev+1}(1) + spdiags(1./dtau(:) + dtauIFix, 0,N,N) + speye(N,N)*(1/dt);
%     condest(mat)
%     max(eigs(J))
            du = mat\rhs;
%     [matL,matU,matP,matQ] = lu(mat);
%     duS = matL\(matP*rhs);
%     du = matQ*(matU\duS);
    
    uc = uc + du;
    res = sum(abs(du(:)));
    
    if(iter == 1)
        res0 = res;
    end
    resr = res/res0;
    fprintf("   === odeAM%d resrInner %d: %.3e\n",nprev+1, iter, resr);
    if(resr < innerTh || norm(rhs,inf)/norm(rhs,inf) * dt < 1e-16)
        break;
    end
end
dtPrev = circshift(dtPrev,1);
dtPrev(1) = dt;
rhsPrev = circshift(rhsPrev,1);
rhsPrev{1} = rhsc;




unew = uc;

unew = reshape(unew,usize);





