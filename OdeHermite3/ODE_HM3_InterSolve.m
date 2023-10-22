function u1 = ODE_HM3_InterSolve(u0, fRHS, fJacobian, fdTau, dt, alpha)

thres = 1e-8;

coefs = [2*alpha^3 - 3*alpha^2 + 1,...
    - 2*alpha^3 + 3*alpha^2,...
    alpha^3 - 2*alpha^2 + alpha,...
    alpha^3 - alpha^2];
N = numel(u0);


weights = [1/2 - 1/(6*alpha), -1/(6*alpha*(alpha - 1)), 1/(6*(alpha - 1)) + 1/2];


f0 = fRHS(u0);

um = u0;
u1 = u0;

for iter = 1:10000
    dTau = fdTau(u1);
    
    R1 = weights(1) * f0 + weights(2) * fRHS(um) + weights(3) * fRHS(u1) + ...
        (u0 - u1) / dt;
    JR1 = spdiags(1./dTau,0,N,N) + speye(N) / dt - weights(3) * fJacobian(u1); % == -dR1/u1
    du1 = JR1 \ R1;
    u1 = u1 + du1;

    RM = um / dt - u0 * coefs(1)/dt - u1 * coefs(2)/dt + ...
        (coefs(4)*weights(1)/weights(3) - coefs(3)) * f0 + ...
        (coefs(4)*weights(2)/weights(3)) * fRHS(um) + ...
         coefs(4) / weights(3) / dt * (u0 - u1);
    JRM = spdiags(1./dTau,0,N,N) + speye(N) / dt + ...
        (coefs(4)*weights(2)/weights(3)) * fJacobian(um); % == dRm/um
    dum = -JRM \ RM;
    um = um + dum;

    res1 = norm(R1,1);
    resM = norm(RM,1);
    fprintf("HM3Iter %d === R1=%.3e RM=%.3e\n ", iter, res1, resM);
    if(iter == 1)
        res1Base = res1 + 1e-300;
        resMBase = resM + 1e-300;
    end
    if(res1 < thres * res1Base || resM < thres * resMBase)
        fprintf("HM3 Converged\n ");
        return;
    end


end
fprintf("HM3 Not Convergent\n ");
warning("HM3 Not Convergent")