function gammaM1 = f_gammM1_fit(rho, Tc, Ys, Ms, asA,asB)
R = 8.314;
Cp = f_Cp_fit(rho, Tc, Ys, Ms, asA,asB);
Cp_minus_Cv = R * sum(Ys./Ms, 1);
gammaM1 = Cp_minus_Cv./(Cp - Cp_minus_Cv);

end