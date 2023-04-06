function A = fdiffCenter(f,x,step)

N = numel(x);
A = zeros(N,N);


for i = 1:N
    x1 = x;
    x2 = x;
    x1(i) = x1(i) - step;
    x2(i) = x2(i) + step;
    dif = (f(x2) - f(x1))/(2*step);
    A(:,i) = reshape(dif,N,1);
    
end