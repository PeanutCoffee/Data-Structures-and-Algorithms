clc;
clear all;
close all;

x = [0, 0, 1, 1, 1, 1, 0, 0];

w = linspace(0,2*pi,628);
X = zeros(length(w),1);
for i=1:length(w)
    sum = 0;
    for n=1:8
        A = -j*w(i)*n;
        Z = exp(A);
        y = x(n)*Z;
        sum = sum+y;
    end
    X(i) = sum;
end
plot(abs(X));