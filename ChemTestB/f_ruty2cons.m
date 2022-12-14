function [uA,aA] = f_ruty2cons(rhoA, vxA, TA, YA, M)

rhoYA = rhoA * YA;
EA = rhoA .* (f_ustatic_fit(rhoA,TA,YA,M.Ms,M.asA,M.asB) + vxA.^2 * 0.5);
uA = [rhoA;rhoA.*vxA; rhoA*0;EA;rhoYA(1:end-1,:)];
gM1A = f_gammM1_fit(rhoA,TA,YA,M.Ms,M.asA,M.asB);
pA = f_DaltonPressureSum(rhoA,YA,M.Ms,TA);
aA = sqrt((gM1A+1) .* pA./rhoA);