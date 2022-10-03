clear all;
close all;
clc;

k=[7.248,14.5,181.2];
for i=1:3
    numerator=15000000*k(i);
    denominator=[1,3408.3,1204000,15000000*k(i)];
    sys=tf(numerator,denominator);
    sys=sys/(1+sys);
    subplot(3,1,i);
    step(sys);
end
