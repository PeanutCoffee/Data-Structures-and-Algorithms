clc;
close all;
clear all;

x= [1,1,1,1];

w=linspace(0,4*pi,628);
X=zeros(length(w));
for i=1:length(w)
     sum=0;
     for n=1:4
     sum=sum+(exp(-j*w(i)*n))
     end
   X(i)=sum;
end
figure;
subplot(5,1,1)
plot(w,abs(X));   
title('Magnitude response of DTFT');
subplot(5,1,2)
plot(w,angle(X));
title("Phase response of DTFT");

wk=linspace(0,4*pi,8); %4 point DFT, double the range so 8 points given
X2=zeros(length(wk));
for i=1:length(wk)
     sum=0;
     for n=1:4
     A=-j*wk(i)*n;
     Z=exp(A);
     y=x(n)*Z;
     sum=sum+y;
     end
   X2(i)=sum;
end
subplot(5,1,3)
stem(wk,abs(X2));
title("Magnitude response of 4 point DFT");

wk1=linspace(0,4*pi,16);
X3=zeros(length(wk1));
for i=1:length(wk1)
     sum=0;
     for n=1:4
     A=-j*wk1(i)*n;
     Z=exp(A);
     y=x(n)*Z;
     sum=sum+y;
     end
   X3(i)=sum;
end
subplot(5,1,4)
stem(wk1,abs(X3));
title("Magnitude response of 8 point DFT");

wk2=linspace(0,4*pi,32);
X4=zeros(length(wk2));
for i=1:length(wk2)
     sum=0;
     for n=1:4
     A=-j*wk2(i)*n;
     Z=exp(A);
     y=x(n)*Z;
     sum=sum+y;
     end
   X4(i)=sum;
end
subplot(5,1,5)
stem(wk2,abs(X4));
title("Magnitude response of 16 point DFT");