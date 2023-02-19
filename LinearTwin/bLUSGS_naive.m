function x = bLUSGS_naive(A,b,bsize)

N = numel(b);
size_vec = size(b);
assert(mod(N,bsize) == 0);
x = zeros(size(b));

maskAdiag = sparse(false(N,N));
for istart = 1:bsize:N
     maskAdiag(istart:istart+bsize-1,istart:istart+bsize-1) = true;
end

D = A.*maskAdiag;
L = tril(A,-1).*(~maskAdiag);
U = triu(A, 1).*(~maskAdiag);

x = x(:);
b = b(:);

x = (D+L)\(-U*x + b);
x = (D+U)\(-L*x + b);

x = reshape(x,size_vec);
end