function ustatic = f_Cp_fit(rho, Tc, Ys, Ms, asA,asB)
habs = f_fitcps(Tc, asA,asB);
habsSum = sum(habs .* (Ys ./ Ms),1);
ustatic = habsSum;
end