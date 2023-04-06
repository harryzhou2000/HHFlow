function hs = f_fitAbsoluteHeat(T, asA, asB)
% asA = [as6,as1,as2,as3,as4,as5]
if(sum(T<1e-10,'all') > 0)
   error('T<0!'); 
end
T = reshape(T,1,[]);
nE = size(T,2);
ns = size(asA,1);
hs = zeros(ns, numel(T));

nP = size(asA,2) - 1;
Tprod = [ones(1,nE);cumprod(repmat(T,nP,1),1)];
coefs = [ones(1,nE);repmat(1./(1:nP)', 1, nE)];
hs = hs + asA*(Tprod.*coefs) .* repmat(T<1000, ns,1);
hs = hs + asB*(Tprod.*coefs) .* repmat(T>=1000, ns,1);
% for i = 1:size(asA,2)
%     hs = hs + ((asA(:,i) * (T).^(i-1)) / max(1, i-1)) .* (T < 1000);
%     hs = hs + ((asB(:,i) * (T).^(i-1)) / max(1, i-1)) .* (T >= 1000);
%     % warning: i don't know if this T is good
% end
R = 8.314;
hs = hs * R;

