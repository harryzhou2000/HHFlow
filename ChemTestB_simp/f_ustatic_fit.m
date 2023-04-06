function ustatic = f_ustatic_fit(rho, Tc, Ys, Ms, asA,asB)
habs = f_fitAbsoluteHeat(Tc, asA,asB);
habsSum = sum(habs .* (Ys ./ Ms),1);
pc = f_DaltonPressureSum(rho, Ys, Ms, Tc);
ustatic = habsSum - pc ./rho;
end