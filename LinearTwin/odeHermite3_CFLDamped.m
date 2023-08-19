function unew = ...
    odeHermite3_CFLDamped(u, frhs, fdTau, fjacobian, dt, alpha, masked, jacobianScheme)
if nargin <= 6
    masked = 0;   
end
if nargin <= 7
    jacobianScheme = 0;
end


usize = size(u);
u = u(:);
N = numel(u);
maxiter= 100;
innerTh = 1e-3;

block_size = usize(1);

weights = [ 1/2 - 1/(6*alpha), -1/(6*alpha*(alpha - 1)), 1/(6*(alpha - 1)) + 1/2];

switch masked
    case 0
        coefs = [ 2*alpha^3 - 3*alpha^2 + 1, ...
            - 2*alpha^3 + 3*alpha^2,...
            (alpha^3 - 2*alpha^2 + alpha) * dt, ...
            (alpha^3 - alpha^2) * dt];
    case 1
        coefs = [ 0, 1, -dt*(alpha^2/2 - alpha + 1/2), dt*(alpha^2/2 - 1/2)]; % mask1
    case 2
        coefs = [ alpha^2 - 2*alpha + 1, - alpha^2 + 2*alpha, 0, -dt*(- alpha^2 + alpha)]; %mask3
    otherwise
        error("no such mask");
end


uc = u;
rhs0 = reshape(frhs(reshape(u,usize)),[],1);
for iter = 1:maxiter
    dtau = reshape(fdTau(reshape(uc,usize)),[],1);
    [rhs, u_mid] = f_RHS(u, uc, rhs0);
    rhs = (u - uc) / dt + rhs;
    
    
    
    
    J = fjacobian(reshape(uc,usize));
    J_mid = fjacobian(reshape(u_mid,usize));
    [A_L,A_U,A_D] = bLUD(J,block_size);
    dtauIFix = full(sum(abs(A_L+A_U+2*A_D),2)) * 0;
    %     % ! approx:
    mat = -J* 1 + spdiags(1./dtau(:) + dtauIFix, 0,N,N) + speye(N,N)*(1/dt);
    % ! approx 2:
    % ! note the damping position!!
    if jacobianScheme == -1
        mat = -(J) *J + spdiags(1./dtau(:) + dtauIFix, 0,N,N) + speye(N,N)*(1/dt);
    end
    if jacobianScheme > 0
        dampingFact = double(jacobianScheme == 2);
        zero2nd     = double(jacobianScheme == 3);
        J_A = J * weights(3) + ...
            (J_mid - spdiags(1./dtau(:) + dtauIFix, 0,N,N) * dampingFact)* (...
            (J -     spdiags(1./dtau(:) + dtauIFix, 0,N,N) * 0          )...
            * coefs(4) * (1-zero2nd) + speye(N,N) * coefs(2)) * weights(2) ;
        
        % numeric
        %     frhsFullCall = @(uc) f_RHS(u, uc, rhs0);
        %     J_A_N = fdiffCenter( frhsFullCall, uc,1e-5);
        %     J_A = J_A_N;
        % numeric end
        mat = -J_A* 1 + spdiags(1./dtau(:) + dtauIFix, 0,N,N)* weights(3) + speye(N,N)*(1/dt);
    end
    
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
    fprintf("   === odeH3 resrInner %d: %.3e\n", iter, resr);
    if(resr < innerTh || norm(rhs,inf)/norm(rhs,inf) * dt < 1e-16)
        break;
    end
end




unew = uc;

unew = reshape(unew,usize);

    function [rhs, u_mid] = f_RHS(u, uc, rhs0)
        rhsc = reshape(frhs(reshape(uc,usize)),[],1);
        u_mid = u * coefs(1) + uc * coefs(2) + rhs0 * coefs(3) + rhsc * coefs(4);
        rhs_mid = reshape(frhs(reshape(u_mid,usize)),[],1);
        rhs = rhs0 * weights(1) + rhsc * weights(3) + rhs_mid * weights(2);
        
        
    end





end