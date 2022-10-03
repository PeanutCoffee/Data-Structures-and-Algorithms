%Nyquist Criteria
clear all
close all
clc
num1=[245]
num2=[235]
num3=[240]
den=[1 12 20 0]
func1=tf(num1,den)
func2=tf(num2,den)
func3=tf(num3,den)
nyquist(func1,func2,func3)