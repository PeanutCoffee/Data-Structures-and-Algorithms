T=1;
wp=0.3*pi;
ws=0.8*pi;
Ap=1;
As=40;
Ohmp=(2/T)*tan(wp/2);
Ohms=(2/T)*tan(ws/2);
X=(10^(0.1*Ap)-1)/(10^(0.1*As)-1);
N=ceil(0.5*(log10(X)/(log10(Ohmp/Ohms))));
Ohmc=Ohmp/((10^(0.1*Ap)-1)^(1/(2*N)));
[b,a]=butter(N,Ohmc,'low','s');  %specified the order,cutoff and low pass type butterworth
Hs=tf(b,a)
[numdig,dendig]=bilinear(b,a,1/T);
Hz=tf(numdig,dendig,T);
Hz
w=0:0.01:pi;
Hw=freqz(numdig,dendig,w);
subplot(1,2,1);
plot(w,abs(Hw));
xlabel("Frequency");
ylabel("Magnitude");
subplot(1,2,2)
plot(w,20*log10(abs(Hw)));
xlabel("Frequency");
ylabel("Magnitued in dB");