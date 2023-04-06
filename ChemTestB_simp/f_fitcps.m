function hs = f_fitcps(T, asA, asB)
% asA = [as6,as1,as2,as3,as4,as5]
if(sum(T<1e-10,'all') > 0)
   error('T<0!'); 
end
T = reshape(T,1,[]);
nE = size(T,2);
ns = size(asA,1);
hs = zeros(ns, numel(T));

nP = size(asA,2) - 1;
Tprod = [ones(1,nE);cumprod(repmat(T,nP-1,1),1)];
hs = hs + asA(:,2:end)*(Tprod) .* repmat(T<1000, ns,1);
hs = hs + asB(:,2:end)*(Tprod) .* repmat(T>=1000, ns,1);

% for i = 2:size(asA,2)
%     hs = hs + asA(:,i) * (T/1).^(i-2) .* (T < 1000);
%     hs = hs + asB(:,i) * (T/1).^(i-2) .* (T >= 1000);
%     % warning: i don't know if this T is good
% end
R = 8.314;
hs = hs * R;    

