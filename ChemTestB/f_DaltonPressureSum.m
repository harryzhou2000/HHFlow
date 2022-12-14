function p = f_DaltonPressureSum(rho, Ys, Ms, T)
% rho(1,i): sum of mass density (kg/m^3)
% Ys(s,i): species_s 's mass fraction
% Ms(s,1): molcule mass (kg/mol)
% T(1,i): traverse temp (K)
R = 8.314; % (J/mol/K)

p =  R * rho .* sum(Ys./Ms, 1) .* T;