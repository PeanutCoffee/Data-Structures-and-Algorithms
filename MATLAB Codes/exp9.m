clear all;
close all;
clc;
M=25; %Hanning Window of Length=25 
tau=(M-1)/2; 
n=0:M-1; 
hd=(2./(pi*(n-tau))).*(sin(pi*(n-tau)/2).^2); 
hd(tau+1)=0; 
whamm=hamming(M)'; 
h=hd.*whamm; 
w=-pi:0.01:pi;   %here we delay positive and negative frequency phases by pi/2 so range is +ve and -ve bothS
Hw=freqz(h,1,w); 
Hrw=exp(-j*((pi/2)-12*w)).*Hw;  %amplitude plotted using the function H(e^(jw))=Hr(e^jw)*exp(j(pi/2-tau*w))
%Note: This is type 3 or 4 type filter used as this is antisymmetric
subplot(2,2,1); 
stem(n,hd,'filled'); 
axis([-1 M -0.8 1]); 
xlabel('n'); 
ylabel('hd(n)'); 
title('Ideal Impulse Response'); 

subplot(2,2,2); 
stem(n,whamm,'filled'); 
axis([-1 M -0.2 1.2]); 
xlabel('n'); 
ylabel('w(n)'); 
title('Hanning Window'); 

subplot(2,2,3); 
stem(n,h,'filled'); 
axis([-1 M -0.8 1]); 
xlabel('n'); 
ylabel('h(n)'); 
title('Practical Impulse Response'); 

subplot(2,2,4); 
plot(w/pi,Hrw); 
axis([-1 1 -1.2 1.2]); 
xlabel('Frequency in pi Units'); 
ylabel('Amplitude'); 
title('Amplitude Response'); 