function ps = plot1DMain(u,T, G,M, f1, f2,t)
Ys = f_getYs(u);

ps = {};
% f1
ps{end+1} = plot(f1,G.xc, Ys);
title(f1,sprintf("Ys t=%f",t));
legend(f1,M.names);

%f2
yyaxis(f2,'left');
ps{end+1} = plot(f2,G.xc, u(1,:), 'DisplayName','\rho');
yyaxis(f2,'right');
ps{end+1} = plot(f2,G.xc, T, 'DisplayName', 'T');
legend;

title(f2,sprintf("rho t=%f",t));
drawnow;