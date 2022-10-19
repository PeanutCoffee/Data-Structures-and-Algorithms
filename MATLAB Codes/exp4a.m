n=0:9;
N=6;
x=n+1;
Lenx= length(x);
h=[1 0 -1];
M=length(h);
M1=M-1;
L=N-M1;
hz=[h zeros(1,N-M)]; %Appending N-M Zeros
nhz=0:length(hz)-1;
xz=[zeros(1,M1) x zeros(1,N-1)]; %Preappending M-1 Zeros
nxz=0:length(xz)-1;
K=ceil((Lenx+M1-1)/L);
y=zeros(K,N);
for i=0:K-1
xi=xz(i*L+1:i*L+N)
for j=0:N-1
m=0:N-1;
n1=mod(j-m,N);
hs=hz(n1+1);
xh=xi.*hs;
y(i+1,j+1)=sum(xh);
end
end
y=y(:,M:N)'; %DiscaRding First M-1 Samples
y=[y(:)]'; %Concatening The Output
ny=0:length(y)-1;
subplot(1,3,1);
stem(nxz,xz,'filled');
xlabel('n');
ylabel('x(n)');
subtitle('x(n)');
title("Using Overlap-save method");
subplot(1,3,2);
stem(nhz,hz,'filled');
xlabel('n');
ylabel('h(n)');
subtitle('h(n)');
subplot(1,3,3);
stem(ny,y,'filled');
xlabel('n');
ylabel('y(n)');
subtitle('y(n)');