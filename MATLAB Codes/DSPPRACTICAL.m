%To find 4 point circular convolution of x1(n) and x2(n)
clear all;
close all;
clc;

x1 = [1, 2, 3, 4];
x2 = [1, -1, -1, 1];

y = zeros(1,4);

for n=0:3
    for m=0:3
        n1=mod(n-m,4)
        y(n+1)=y(n+1)+(x1(m+1)*x2(n1+1))
    end
end
    
y
  

subplot(2,2,1)  
stem(x1)
subtitle("Sequence1");
subplot(2,2,2)
stem(x2)
subtitle("Sequence 2");
subplot(2,2,3)
stem(y)
subtitle("Circularly convolved sequence");