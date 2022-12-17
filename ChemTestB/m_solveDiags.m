function x = m_solveDiags(A,b)

nG = size(b,2);
x = zeros(size(b));
for i = 1:nG
    x(:,i) = A(:,:,i)\...
        b(:,i);
end