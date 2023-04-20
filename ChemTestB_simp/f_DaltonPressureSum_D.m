function dp = f_DaltonPressureSum_D(rho, Ys, Ms, T, drho, dYs, dT)
% rho(1,i): sum of mass density (kg/m^3)
% Ys(s,i): species_s 's mass fraction
% Ms(s,1): molcule mass (kg/mol)
% T(1,i): traverse temp (K)
R = 8.314; % (J/mol/K)

dp =  R * drho .* sum(Ys./Ms, 1) .* T + R * rho .* sum(Ys./Ms, 1) .* dT + R * rho .* sum(dYs./Ms, 1) .* T;