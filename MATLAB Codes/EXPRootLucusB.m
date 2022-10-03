clear all;
close all;
clc;

k=[-3000,3000];
for i=1:2
    numerator=[k(i),3*k(i)];
    denominator=[1,21,35,44,22,0];
    sys=tf(numerator,denominator);
    display(sys)
    subplot(2,1,i);
    rlocus(sys);
end
