function [T, p, stat] = f_solveT_fit(T, Ys, u, Ms, asA, asB)

rho    = u(1,:);
e      = u(4,:)   ./rho;
veloxy = u(2:3, :)./rho;
vsqr = veloxy(1,:).^2 + veloxy(2,:).^2;
ustaticC = e - 0.5 * vsqr;

% options = optimoptions('fsolve');
% options.MaxFunctionEvaluations = 200;
% options.Display = 'off';
% options.Algorithm = 'trust-region';
% options.JacobianMultiplyFcn;
% [sol,fval,exitflag] = fsolve(@(x) fustatic(x) - ustaticC, T, options);
% T = sol;
% stat.exitflag = exitflag;

fdustaticdT = @(Tc) f_Cp_fit(rho,Tc,Ys,Ms,asA,asB) - f_DaltonPressureSum(rho, Ys, Ms, Tc)./rho./Tc;


for iter = 1:100
    dT = (ustaticC-fustatic(T))./fdustaticdT(T);
    dTnorm = norm(dT,inf);
    T = T + dT;
    if(iter == 1)
        dTnorm0 = dTnorm;
    end
    if(dTnorm <= dTnorm0 * 1e-3 || norm(dT,inf) < 1e-3)
        break;
    end
end
if (iter > 10)
    fprintf("f_solveT iters: %d\n", iter);
end
if(iter >= 100 && norm(dT,inf) > 1)
    error('did not converge');
end

stat = iter;


p = f_DaltonPressureSum(rho, Ys, Ms, T);

    function ustatic = fustatic(Tc)
        ustatic =  f_ustatic_fit(rho, Tc, Ys, Ms, asA, asB);
    end

end




