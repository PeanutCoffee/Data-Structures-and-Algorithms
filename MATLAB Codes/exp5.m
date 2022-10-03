n=0:99;
k=1:100;
x=cos(0.48*pi*n)+cos(0.52*pi*n);
xpad=[x(1:10),zeros(1,90)];  %first input signal with 90padded zeros
N=100;
w=2*pi/N;
DFTpadded=zeros(1,100);
for l=1:100            %kth sample of DFT is l here
    for i=1:100
    a=xpad(i)*exp(-j*w*(i-1)*l);
    DFTpadded(l)=DFTpadded(l)+a;
    end
end

xoriginal=x(1:100);
DFToriginal=zeros(1,100);
for l=1:100            %kth sample of DFT is l here
    for i=1:100
    a=xoriginal(i)*exp(-j*w*(i-1)*l);
    DFToriginal(l)=DFToriginal(l)+a;
    end
end


subplot(2,2,1);
stem(x);
title("Original signal ");
subplot(2,2,2);
stem(DFToriginal);
title("DFT of original signal");
subplot(2,2,3);
stem(xpad);
title("Zero padded input signal");
subplot(2,2,4);
stem(DFTpadded);
title("DFT of zero padded signal");