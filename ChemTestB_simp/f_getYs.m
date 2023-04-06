function Ys = f_getYs(u)
rho = u(1,:);
Ys = [u(5:end,:); rho - sum(u(5:end,:),1)];
Ys = Ys ./ sum(Ys,1);

end