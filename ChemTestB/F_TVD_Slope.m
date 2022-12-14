function d = F_TVD_Slope(dL,dR)

d = (sign(dL) + sign(dR)) .* abs(dL.*dR)./ (abs(dL + dR) + 1e-300);