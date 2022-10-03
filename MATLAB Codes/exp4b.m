clear all;
close all;
clc;
n=0:9;
N=4;
x=n+1;
Lenx=length(x);
h=[1 0 -1];
M=length(h);
M1=M-1;
L=N+M-1;
hz=[h zeros(1,L-M)]; %Appending N-M Zeros
nhz=0:length(hz)-1;
K=ceil(Lenx/N);
xx=[x zeros(1,N*K-Lenx)]; %Preappending M-1 Zeros
nxx=0:length(xx)-1;
y=zeros(K,N);
for i=0:K-1
xi=xx(i*N+1:N*(i+1));
xr=[xi zeros(1,M1)];
for j=0:L-1
m=0:L-1;
n1=mod(j-m,L);
hs=hz(n1+1);
xh=xr.*hs;
y(i+1,j+1)=sum(xh);
end
end
yy=[]; %Adding Last M-1 Samples
for i=1:K-1;
y(i,:)=[y(i,1:N) y(i,N+1:L)+y(i+1,1:M1)];
end
yy=[y(1,1:L) y(2,M:L) y(3,M:L-M1)];
ny=0:length(yy)-1;
subplot(1,3,1);
stem(nxx,xx,'filled');
xlabel('n');
ylabel('x(n)');
subtitle('x(n)');
title("Using overlap add method");
subplot(1,3,2);
stem(nhz,hz,'filled');
xlabel('n');
ylabel('h(n)');
subtitle('h(n)');
subplot(1,3,3);
stem(ny,yy,'filled');
xlabel('n');
ylabel('y(n)');
subtitle('y(n)');