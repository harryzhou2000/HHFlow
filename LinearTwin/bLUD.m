function [L,U,D] = bLUD(A,bsize)

N = size(A,1);
assert(mod(N,bsize) == 0);

maskAdiag = sparse(false(N,N));
for istart = 1:bsize:N
     maskAdiag(istart:istart+bsize-1,istart:istart+bsize-1) = true;
end

D = A.*maskAdiag;
L = tril(A,-1).*(~maskAdiag);
U = triu(A, 1).*(~maskAdiag);

end