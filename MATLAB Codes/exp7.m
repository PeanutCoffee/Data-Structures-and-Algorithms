clear all;
close all;
clc;

Fp=2000; %Fp=2KHz 
Fs=5000; %Fs=5KHz 
Ft=20000; %Ft=20KHz 
wp=(2*pi*Fp)/Ft; 
ws=(2*pi*Fs)/Ft; 
trwidth=ws-wp; %Transition Width 

M=ceil(6.2*pi/trwidth); %FilterLength
tau=(((M-1)/2))
wc=(wp+ws)/2;    %cutoff frequency
n=0:M-1; 
hd=(sin(wc*(n-tau)))./(pi*(n-tau)); %desired filter
hd(tau+1)=0.35;  %found using l'hopital's rule manually
whan=hann(M); 
whan=whan.';   %converting row to column matrix as to be multiplied later
h=hd.*whan;  %practical filter impulse response after multiplying with window
w=0:0.02:pi; 
Hw=freqz(h,1,w);    
MagHw=abs(Hw); %Magnitude Response  
HwdB=20*log(MagHw);

subplot(2,2,1); 
stem(n,hd,'filled'); 
axis([-1 M -0.15 0.5]); 
xlabel('n'); 
ylabel('hd(n)'); 
title('Ideal Impulse Response'); 

subplot(2,2,2); 
stem(n,whan,'filled'); 
axis([-1 M -0.1 1.2]); 
xlabel('n'); 
ylabel('w(n)'); 
title('Hann Window'); 

subplot(2,2,3); 
stem(n,h,'filled'); 
axis([-1 M -0.15 0.5]); 
xlabel('n'); 
ylabel('w(n)'); 
title('Practical Impulse Response'); 

subplot(2,2,4); 
plot(w/pi,HwdB); 
axis([0 1 -100 10]);        
xlabel('Frequency in pi '); 
ylabel('dB'); 
title('Magnitude Response');