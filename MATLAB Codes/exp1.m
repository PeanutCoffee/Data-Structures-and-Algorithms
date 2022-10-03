x=[1];
y=[1,-0.9];
subplot(4,1,1);
zplane(x,y)  %plotted pole zero plot
h=freqz(x,y);  %transfer function
subplot(4,1,2)
plot(abs(h))   
title('Magnitude response');
subplot(4,1,3)
plot(angle(h))
title('Phase response');

n=1:100
z2=zeros(length(n));
z2(1)=0;
for i=2:length(n)
    z2(i)=0.9*z2(i-1)+cos(0.05*pi*i);
end
subplot(4,1,4);
stem(n,z2); 
title("Steady state response");