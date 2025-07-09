function [a0, a1, a2, b1,b2,b3, d1,d2] = f_getDITR(method, c2, Theta)

b1 = 1/2 - 1/6/c2;
b3 = 1/2 - 1/6/(1-c2);
b2 = 1/6/c2/(1-c2);

if method == 1
    a0 = 0;
    a1 = 1 - (3*c2^2-2*c2^3);
    a2 = 1 - a1;
    d1 = c2 - 2 * c2^2 + c2^3;
    d2 = - 1 * c2^2 + c2^3;

elseif method == 2
    a0 = 0;
    a1 = 1 - (2 * c2 - c2^2);
    a2 = 1 - a1;
    d1 = 0;
    d2 = c2^2 - c2;

elseif method == 3
    a0 = -(c2*(c2 - 1)^2)/(Theta*(Theta + 1)^2);
    a1 = ((Theta + c2)*(c2 - 1)^2)/Theta;
    a2 = (c2*(- Theta^2*c2 + 2*Theta^2 - Theta*c2^2 + 3*Theta - 2*c2^2 + 3*c2))/(Theta + 1)^2;
    d1 = 0;
    d2 = (c2*(Theta + c2)*(c2 - 1))/(Theta + 1);
end

