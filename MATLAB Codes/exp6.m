clear all;
close all;
clc;
N=205;  %DFT length
n=0:N-1;
x=sin(2*pi*n*697/8000)+sin(2*pi*n*1209/8000);
if length(x)<N
    xz=[x zeros(1,N-length(x))];
else
    xz=x
end
    x1=[xz 0]
    k=[18 20 22 24 31 34 38];
    for i=1:7
        W(i) =exp(-j*2*pi*k(i)/N);
        den(i,:)=[1 -2*cos(2*pi*k(i)/N) 1];
        vk(i,:) =filter(1, den(i, :), x1);
        Xk(i)=vk(i,N+1)-W(i)*vk(i,N);
    end

stem(k,abs(Xk),'filled');
xlabel('k');
ylabel('|X(k)|');
title('DFT at k=18,20,22,24,31,34,38');
