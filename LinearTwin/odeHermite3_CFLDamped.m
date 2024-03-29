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
maxiter= 10000;
innerTh = 1e-4;

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

if jacobianScheme == 6
switch masked
    case 0
        coefs = [ 2*alpha^3 - 3*alpha^2 + 1, ...
            - 2*alpha^3 + 3*alpha^2,...
            (alpha^3 - 2*alpha^2 + alpha), ...
            (alpha^3 - alpha^2) ];
    case 1
        coefs = [ 0, 1, -(alpha^2/2 - alpha + 1/2), (alpha^2/2 - 1/2)]; % mask1
    case 2
        coefs = [ alpha^2 - 2*alpha + 1, - alpha^2 + 2*alpha, 0, -(- alpha^2 + alpha)]; %mask3
    otherwise
        error("no such mask");
end

end


uc = u;
um = u;
% [u --- um --- uc]
rhs0 = reshape(frhs(reshape(u,usize),0),[],1);
for iter = 1:maxiter
    dtau = reshape(fdTau(reshape(uc,usize)),[],1);
    if jacobianScheme == 6
        thetaA = -coefs(4) / weights(3);
%         thetaA = 50;
        

        RM = -um / dt + u * (coefs(1) + thetaA)/dt + uc * (coefs(2) - thetaA)/dt + ...
        (coefs(3) + thetaA * weights(1)) * rhs0(:) + ...
        (thetaA * weights(2)) * reshape(frhs(reshape(um,usize),alpha),[],1) + ...
         (coefs(4) + thetaA * weights(3)) * reshape(frhs(reshape(uc, usize),1),[],1);

        JRM = -spdiags(1./dtau(:),0,N,N) - speye(N) / dt + ...
        (thetaA * weights(2)) * fjacobian(reshape(um,usize)); % == dRm/um

        dum = -JRM \ RM;
        um = um + dum;

        R1 = weights(1) * rhs0(:) + weights(2) * reshape(frhs(reshape(um,usize),alpha),[],1) + ...
            weights(3) * reshape(frhs(reshape(uc, usize),1),[],1) + ...
        (u - uc) / dt;
        JR1 = -spdiags(1./dtau(:),0,N,N) - speye(N) / dt + weights(3) * fjacobian(reshape(uc,usize)); % == -dR1/u1
        duc = -JR1 \ R1;
        uc = uc + duc;

        
        

        res1 = norm(R1,1);
        resM = norm(RM,1);
        res = res1 + resM;
    else
        
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
        if jacobianScheme > 0 && jacobianScheme <= 4
            dampingFact = double(jacobianScheme == 2);
            zero2nd     = double(jacobianScheme == 3);
            zeroOut     = double(jacobianScheme == 4);
            J_A = (J   - spdiags(1./dtau(:) + dtauIFix, 0,N,N) * 1 )* weights(3)* (1 - zeroOut) + ...
                (J_mid - spdiags(1./dtau(:) + dtauIFix, 0,N,N) * 0)* (...
                (J -     spdiags(1./dtau(:) + dtauIFix, 0,N,N) * 0)...
                * coefs(4) * (1-zero2nd) + speye(N,N) * coefs(2)) * weights(2) ;

            % numeric
            %     frhsFullCall = @(uc) f_RHS(u, uc, rhs0);
            %     J_A_N = fdiffCenter( frhsFullCall, uc,1e-5);
            %     J_A = J_A_N;
            % numeric end
            mat = -J_A + speye(N,N)*(1/dt);
        end
        if jacobianScheme ==5
            % this jacobian scheme only works for alpha near 0.5
            J_A = 2 * coefs(4) * weights(2) * ... % 2 for more damping
                (J     + coefs(2)  / coefs(4) * dt               * (speye(N,N)*(1/dt) + spdiags(1./dtau(:) + dtauIFix, 0,N,N)*1) ) *...
                (J_mid + weights(3)/(coefs(4) * weights(2)) * dt * (speye(N,N)*(1/dt) + spdiags(1./dtau(:) + dtauIFix, 0,N,N)*0) );
            mat = -J_A;
        end

        %     condest(mat)
        %     max(eigs(J))
        du = mat\rhs;
        %     [matL,matU,matP,matQ] = lu(mat);
        %     duS = matL\(matP*rhs);
        %     du = matQ*(matU\duS);

        uc = uc + du;
        res = sum(abs(du(:)));

    end

    if(iter == 1)
        res0 = res;
    end
    resr = res/res0;
    fprintf("   === odeH3 resrInner %d: %.3e\n", iter, resr);
    if(resr < innerTh)
        break;
    end
end

if(iter == maxiter)
   warning("   === odeH3 not convergent");  
end


unew = uc;

unew = reshape(unew,usize);

    function [rhs, u_mid] = f_RHS(u, uc, rhs0)
        rhsc = reshape(frhs(reshape(uc,usize),1),[],1);
        u_mid = u * coefs(1) + uc * coefs(2) + rhs0 * coefs(3) + rhsc * coefs(4);
        rhs_mid = reshape(frhs(reshape(u_mid,usize),alpha),[],1);
        rhs = rhs0 * weights(1) + rhsc * weights(3) + rhs_mid * weights(2);


    end





end