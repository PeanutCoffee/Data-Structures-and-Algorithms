clc;
clear all;
close all;

x = [0, 0, 1, 1, 1, 1, 0, 0];
y = fft(x,128);
stem(abs(y));