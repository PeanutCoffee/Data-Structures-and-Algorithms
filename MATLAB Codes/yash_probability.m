clc
clear all
close all

%events
a=3;
b=-1;
c=3.5;
d=0;
count=0;

N=10000;
y=-5+10*rand(1,N);
%computing probabilities for y<a, b<y<c and y>b

%events
for item=y
    if item<a
        count=count+1;
    end   
end    

event1uniform=count/N;
disp(event1uniform)