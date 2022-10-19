clear all;
close all;
clc;
num=[2500];
den=[1 15 50 0];
func=tf(num,den);
[GainMargin PhaseMargin PhaseCrossOverFrequency GainCrossOverFrequency]=margin(func);
bode(func)