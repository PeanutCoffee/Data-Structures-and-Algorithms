clear all;
close all;
clc;

k=3000;
a = [1,1.12,1.185,3]
for j=1:4
    numerator=[k,2*k];
    denominator=[1,2,a(j),0];
    sys=tf(numerator,denominator);
    display(sys)
    subplot(4,1,j);
    rlocus(sys);
end
