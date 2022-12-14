function Xs = f_getXs(Ys,Ms)

Xs = Ys./Ms;
Xs = Xs ./ sum(Xs,1);