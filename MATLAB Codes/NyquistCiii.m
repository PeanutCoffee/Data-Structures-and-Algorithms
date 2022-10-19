clear all;
close all;
clc;

k1=245;
k2=235;
k3=240;
num1=[k1];
num2=[k2];
num3=[k3];
den=[5 1 0 0];
func1=tf(num1,den);
func2=tf(num2,den);
func3=tf(num3,den);
nyquist(func1,func2,func3)