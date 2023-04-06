function [uA,aA,rhoA] = f_puty2cons(pA, vxA, TA, YA, M)

rho0 = ones(size(pA));

function p = fP(rhoA)
[~,~,p] = f_ruty2cons(rhoA,vxA,TA,YA,M);
end

rhoA = fsolve(@(rhoA) fP(rhoA)-pA, rho0);

[uA,aA] = f_ruty2cons(rhoA,vxA,TA,YA,M);

end