function k = f_kArrhenius(ABC,T)
k = ABC(:,1) .* T.^ABC(:,2) .* exp(-ABC(:,3)./T);