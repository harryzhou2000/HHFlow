function doN = f_doNChem(n, kf, kb, nuf, nub, C, L)

nReaction = size(kf,1);
nE = size(kf,2);
Rf = nan(nReaction,nE);
Rb = nan(nReaction,nE);
nS = size(n,1);

tbFactors = (C*n).^ repmat(L,1, nE);


for r = 1:nReaction
    Rf(r,:) = prod(n .^ repmat((nuf(r, :)'),1, nE)) .* kf(r, :);
    Rb(r,:) = prod(n .^ repmat((nub(r, :)'),1, nE)) .* kb(r, :);
end
Rf = Rf.*tbFactors;
Rb = Rb.*tbFactors;

% R = Rf - Rb;

% oN = ((nub - nuf)') * R;

ndiv = repmat(reshape(n,1, nS, nE) + 1e-200, nReaction,1,1);
% dR = repmat(nuf,1,1,nE) ./ ndiv .* reshape(Rf,nReaction,1,nE)...
%     - repmat(nub,1,1,nE) ./ ndiv .* reshape(Rb,nReaction,1,nE) +...
%     reshape(C.*L, nReaction, nS, 1) ./ (reshape(tbFactors,nReaction,1,nE) + 1e-200);
dR = repmat(nuf,1,1,nE) ./ ndiv .* repmat(reshape(Rf,nReaction,1,nE),1,nS,1)...
    - repmat(nub,1,1,nE) ./ ndiv .* repmat(reshape(Rb,nReaction,1,nE),1,nS,1) +...
    0 * repmat(C.*repmat(L,1,nS), 1, 1, nE) ./ repmat((reshape(tbFactors,nReaction,1,nE) + 1e-200),1,nS,1);
doN = (nub - nuf)' * reshape(dR, nReaction,[]);
doN = reshape(doN, nS, nS, nE);

% doN = zeros(nS,nS,nE);
% for i = 1:nE
%     dR = nuf ./ (n(:,i)'+1e-200) .* Rf(:,i) - nub ./ (n(:,i)'+1e-200) .* Rb(:,i) + ...
%         C.*L .* R(:,i) ./(tbFactors(:,i)+1e-200);
%     
%     doN(:,:,i) = ((nub - nuf)') * dR;
%     
% end




