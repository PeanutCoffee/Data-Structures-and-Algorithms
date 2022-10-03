clear all;
close all;
clc;
M=21; %Hamming Window Length=21 
tau=(M-1)/2; 
n=0:M-1; 
hd=((cos(pi*(n-tau)))./(n-tau))-((sin(pi*(n-tau)))./(pi*(n-tau).^2));  %manually calculated impulse response
hd(tau+1)=0;   %manually calculated using l'hopital's
whamm=hamming(M)';   %converted to column matrix for multiplication
h=hd.*whamm; 
w=0:0.01:pi; 
Hw=freqz(h,1,w); 
Hrw=exp(-j*(pi/2-10*w)).*Hw; %amplitude plotted using the function H(e^(jw))=Hr(e^jw)*exp(j(pi/2-tau*w))

subplot(2,2,1); 
stem(n,hd,'filled'); 
axis([-1 M -1.2 1.2]); 
xlabel('n'); 
ylabel('hd(n)'); 
title('Ideal Impulse Response'); 

subplot(2,2,2); 
stem(n,whamm,'filled'); 
axis([-1 M -0.2 1.2]); 
xlabel('n'); 
ylabel('w(n)'); 
title('Hamming Window'); 

subplot(2,2,3); 
stem(n,h,'filled'); 
axis([-1 M -1.2 1.2]); 
xlabel('n'); 
ylabel('h(n)'); 
title('Practical Impulse Response'); 

subplot(2,2,4); 
plot(w,Hrw); 
axis([0 pi 0 pi]); 
xlabel('Frequency'); 
ylabel('Amplitude'); 
title('Amplitude Response'); 