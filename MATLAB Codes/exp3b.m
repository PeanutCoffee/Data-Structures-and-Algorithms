N=4
a=[1 2 2 1];
N1=length(a);
b=[1 -1 -1 1];
N2=length(b);
Ny=N1+N2-1;
az=[a zeros(1,Ny-N1)];
bz=[b zeros(1,Ny-N2)];
y=zeros(1,Ny);
%circular convolution
for n=0:Ny-1
    m=0:Ny-1
    n1=mod(n-m,Ny)
    bs=bz(n1+1)
    ab=az.*bs;
    y(n+1)=sum(ab);
end
n=0:Ny-1
subplot(1,3,1)
stem(n,az,'filled');
xlabel('n');
title('x1(n)');

subplot(1,3,2)
stem(n,bz,'filled');
xlabel('n')
title('x2(n)');

subplot(1,3,3);
stem(b);
xlabel('n');
title('y(n)');