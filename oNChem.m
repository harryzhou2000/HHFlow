function oN = oNChem(n, kf, kb, nuf, nub, C, L)

nReaction = numel(kf);
Rf = nan(nReaction,1);
Rb = nan(nReaction,1);

tbFactors = (C*n).^L;


for r = 1:nReaction
    Rf(r) = prod(n .^ (nuf(r, :)')) * kf(r);
    Rb(r) = prod(n .^ (nub(r, :)')) * kb(r);
end
Rf = Rf.*tbFactors;
Rb = Rb.*tbFactors;

R = Rf - Rb;

oN = ((nub - nuf)') * R;




