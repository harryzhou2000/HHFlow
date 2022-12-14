function hs = f_fitcps(T, asA, asB)
% asA = [as6,as1,as2,as3,as4,as5]
if(sum(T<100) > 0)
   warning('T<100!'); 
end
T = reshape(T,1,[]);
ns = size(asA,1);
hs = zeros(ns, numel(T));
R = 8.314;
for i = 2:size(asA,2)
    hs = hs + asA(:,i) * (T/1).^(i-2) .* (T < 1000);
    hs = hs + asB(:,i) * (T/1).^(i-2) .* (T >= 1000);
    % warning: i don't know if this T is good
end
hs = hs * R;

