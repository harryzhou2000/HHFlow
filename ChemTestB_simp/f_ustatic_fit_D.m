function dustatic = f_ustatic_fit_D(rho, Tc, Ys, Ms, asA,asB, drho, dTc, dYs)
habs = f_fitAbsoluteHeat(Tc, asA,asB);
dhabs = f_fitcps(Tc, asA, asB).*dTc;
pc = f_DaltonPressureSum(rho, Ys, Ms, Tc);
dpc = f_DaltonPressureSum_D(rho,Ys,Ms,Tc,drho,dYs,dTc);



dustatic = sum(dhabs .* (Ys ./ Ms), 1) + sum(habs .* (dYs ./ Ms), 1)...
    - dpc ./rho + pc ./rho.^2 .*drho;
end