clear all;
close all;
clc;

w = 1;
E = 0.5;

%Without zero,
numerator = w^2;
denominator = [1,2*E*w,w^2];
sys=tf(numerator,denominator);
sys=sys/(1+sys);
subplot(6,1,1);
step(sys);

%With zero
T=[0,1,3,6,10];
for i=1:5
    numerator=[T(i)*w^2, w^2];
    denominator = [1,2*E*w,w^2];
    sys=tf(numerator,denominator);
    sys=sys/(1+sys);
    subplot(6,1,i+1);
    step(sys);
end
