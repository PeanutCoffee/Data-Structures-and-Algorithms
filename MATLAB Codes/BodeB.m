clear all;
close all;
clc;
num=[100 4500 20000];
den=[1 300 20000 0 0 0];
func=tf(num,den);
[GainMargin PhaseMargin PhaseCrossOverFrequency GainCrossOverFrequency]=margin(func);
bode(func)