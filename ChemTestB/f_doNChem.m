function doN = f_doNChem(n, kf, kb, nuf, nub, C, L)

nReaction = size(kf,1);
nE = size(kf,2);
Rf = nan(nReaction,nE);
Rb = nan(nReaction,nE);
nS = size(n,1);

tbFactors = (C*n).^L;


for r = 1:nReaction
    Rf(r,:) = prod(n .^ (nuf(r, :)')) .* kf(r, :);
    Rb(r,:) = prod(n .^ (nub(r, :)')) .* kb(r, :);
end
Rf = Rf.*tbFactors;
Rb = Rb.*tbFactors;

R = Rf - Rb;

% oN = ((nub - nuf)') * R;
doN = zeros(nS,nS,nE);
for i = 1:nE
dR = nuf ./ (n(:,i)'+1e-200) .* Rf(:,i) - nub ./ (n(:,i)'+1e-200) .* Rb(:,i) + ...
    C.*L .* R(:,i) ./(tbFactors(:,i)+1e-200);

doN(:,:,i) = ((nub - nuf)') * dR;

end




