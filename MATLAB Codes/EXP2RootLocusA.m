clear all;
close all;
clc;

k=[-3000,3000];
for i=1:2
    numerator=k(i);
    denominator=[1,8,36,80,0];
    sys=tf(numerator,denominator);
    display(sys)
    subplot(2,1,i);
    rlocus(sys);
end
