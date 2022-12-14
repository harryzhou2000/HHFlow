function oN = f_oNChem(n, kf, kb, nuf, nub, C, L)


nReaction = size(kf,1);
nE = size(kf,2);
Rf = nan(nReaction,nE);
Rb = nan(nReaction,nE);

tbFactors = (C*n).^L;


for r = 1:nReaction
    Rf(r,:) = prod(n .^ (nuf(r, :)'),1) .* kf(r,:);
    Rb(r,:) = prod(n .^ (nub(r, :)'),1) .* kb(r,:);
end
Rf = Rf.*tbFactors;
Rb = Rb.*tbFactors;

R = Rf - Rb;

oN = ((nub - nuf)') * R;




