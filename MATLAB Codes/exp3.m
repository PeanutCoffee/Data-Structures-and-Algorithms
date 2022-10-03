clc;
close all;
clear all;
% Circular convolution
x1=[1,2,2,1]
x2=[1,-1,-1,1]
N=4
y=zeros(N);
for n=0:N-1
    for m=0:N-1
        n1=mod(n-m,N)
        y(n+1)=y(n+1)+(x1(m+1)*x2(n1+1))
    end
end
subplot(2,2,1)  %2 rows 2 columns 1st value
stem(x1)
subtitle("Sequence1");
subplot(2,2,2)
stem(x2)
subtitle("Sequence 2");
subplot(2,2,3)
stem(y)
subtitle("Circularly convolved sequence");