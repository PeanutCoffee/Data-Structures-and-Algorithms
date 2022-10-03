clc
clear all
a=[1,2,3,4,5,6,7,8,9];
%Verified circular shifting for first shift x<n-3>
out1_fin=zeros(length(a));
for i=1:length(a)
    j=mod(i+3,length(a));
    if(j<=0)
        j=j+length(a)
        out1_fin(j)=a(i);
    else
        out1_fin(j)=a(i);
    end
end
 %Verifying the shift by plotting magnitude and phse spectrum
A=fft(a,length(a));
out1_finfft=fft(out1_fin,length(a));
subplot(2,3,1)
stem(a)
subtitle("Original sequence");
subplot(2,3,2)
stem(angle(A))
subtitle("Phase plot of original")
subplot(2,3,3)
stem(abs(A))
subtitle("Magnitude plot of original")
subplot(2,3,4)
stem(out1_fin)
subtitle("Shifted sequence");
subplot(2,3,5)
stem(angle(out1_finfft))
subtitle("Phase plot of shifted")
subplot(2,3,6)
stem(abs(out1_finfft))
subtitle("Magnitude plot of shifted")

% Finding x<n+3>9
out2_fin=zeros(length(a));
for i=1:length(out2_fin)
    j=i-3;
    if(j<=0)
        j=j+length(a);
        out2_fin(j)=a(i);
    else
        out2_fin(j)=a(i);
    end
end

% x<-n>
out3_fin=zeros(length(a))
for i=1:length(a)
    j=length(a)-i+1
    out3_fin(j)=a(i)
end
figure
subplot(2,2,1)
stem(a)
subtitle("Original sequence");
subplot(2,2,2)
stem(angle(A))
subtitle("Phase of the sequence");
subplot(2,2,3)
stem(out3_fin)
subtitle("reverse sequence");
f3=fft(out3_fin,length(a))

subplot(2,2,4)
stem(angle(f3))
subtitle("Phase of reversed sequence");