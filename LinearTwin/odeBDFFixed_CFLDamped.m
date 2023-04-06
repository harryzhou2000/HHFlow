function [unew, dtPrev, uPrev] = ...
    odeBDFFixed_CFLDamped(u, frhs, fdTau, fjacobian, dt,...
    uPrev, dtPrev, nprev)
% warning, rhsPrev, dtPrev are right-shifted to fill new values at the end
usize = size(u);
u = u(:);
N = numel(u);
maxiter= 100;
innerTh = 1e-3;

block_size = usize(1);

for ip = 1:(nprev-1)
   assert(dtPrev(ip) == dt);
end


coefBDF4 = [12, 48, -36, 16, -3]/25;
coefBDF3 = [6, 18, -9, 2]/11;
coefBDF2 = [2, 4,-1]/3;
coefBDF1 = [1, 1];

coefs = {coefBDF1,coefBDF2,coefBDF3,coefBDF4};

uc = u;
for iter = 1:maxiter
    dtau = reshape(fdTau(reshape(uc,usize)),[],1);
    rhsc = reshape(frhs(reshape(uc,usize)),[],1);
    rhs = (0 - uc) / dt + rhsc * coefs{nprev}(1);
    for ip = 1:nprev
        rhs = rhs + uPrev{ip} * (coefs{nprev}(1+ip)/dt);
    end
    
    J = fjacobian(reshape(uc,usize));
    [A_L,A_U,A_D] = bLUD(J,block_size);
    dtauIFix = full(sum(abs(A_L+A_U+2*A_D),2))* coefs{nprev}(1) *0;
%     dtauIFix = 2 * abs(rhsc./1); % used in linearConvRelaxationT2, with 1 as scale
%     max(dtauIFix) %print
%     dtauIFix = repmat(max(reshape(dtauIFix,usize),[],1),block_size,1) ;
%     dtauIFix = dtauIFix(:);
    
    mat = -J* coefs{nprev}(1) + spdiags(1./dtau(:)+dtauIFix, 0,N,N) + speye(N,N)*(1/dt);
%     condest(mat)
%     max(eigs(J))
%             du = mat\rhs;
    du = bLUSGS_naive(mat,rhs,block_size);
%     [matL,matU,matP,matQ] = lu(mat);
%     duS = matL\(matP*rhs);
%     du = matQ*(matU\duS);
    
    uc = uc + du;
    res = sum(abs(du(:)));
    
    if(iter == 1)
        res0 = res;
    end
    resr = res/res0;
    fprintf("   === odeBDF%d resrInner %d: %.3e\n",nprev, iter, resr);
    if(resr < innerTh || norm(rhs,inf)/norm(rhs,inf) * dt < 1e-16)
        break;
    end
end
dtPrev = circshift(dtPrev,1);
dtPrev(1) = dt;
uPrev = circshift(uPrev,1);
uPrev{1} = uc;




unew = uc;

unew = reshape(unew,usize);





