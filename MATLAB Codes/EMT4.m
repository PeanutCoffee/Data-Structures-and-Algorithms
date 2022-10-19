clc;
close all; 
clear all;

%Units 
meters = 1;
seconds = 1;
millimeters = 1e-3 * meters;
centimeters = 1e-2 * meters; hertz = 1/seconds;
kilohertz = 1e3 * hertz;
megahertz = 1e6 * hertz;
gigahertz = 1e9 * hertz;

%Constants
u0 = 1.2566370614e-6; 
e0 = 8.8541878176e-12;
c0 = 299792458;
sig = 0.8;
sigm_c = 2;

fprintf('\n Calculation of Primary Constant and Secondary Constant of Coaxial Line: ');
prompt = '\n Enter the inner radius of Conductor (a) (in inches): ';
a = input(prompt);
prompt = '\n Enter the Outer Radius of Conductor (b) (in inches): '; 
b = input(prompt);
prompt = '\n Enter the Length of Conductor (1) (in meters): ';
length = input(prompt);
prompt = '\n Enter the realtive dielectric constant of material (er): '; 
er = input(prompt);
prompt = '\n Enter the Relative Permeability of Conductor (ur): '; 
ur = input(prompt);
prompt = '\n Enter the Operating Frequency (f0, in hertz) [atleast 1 GHz]: '; 
f0 = input(prompt);

A = a * 0.0254 * meters; 
B = b * 0.0254 * meters;
fprintf('****OUTPUT****'); 
fprintf('\n Inner Radius of Conductor (A) (in meters): ');
disp(A);
fprintf('\n Outer Radius of Conductor (B) (in meters): ');
disp(B);
w = 2 * pi * f0;
fprintf('\n Angular Frequency: '); 
disp(w);
X = pi * f0 * u0 * ur;
sd = 1/sqrt(X);

%Calculation of Skin Depth
fprintf('\n Skin Depth of Conductor: '); 
disp(sd);
Y = 2 * pi * sd * sigm_c;
R = [(1/A) + (1/B)] * 1/Y;
Z = log (B / A); %Calculation of Resistance in Ohm/Meters
C = (2 * pi * e0 * er) / Z; %Calculation of Caapcitance in Farads/Meters
L = (u0 * ur * length * Z) / (2 * pi); %Calculation of Inductance in Henry/Meters 
G = 2 * sig * pi / Z; %Calculation of Conductance in Simen/Meters
D = log10(B / A);
Z0 = (138 * D) / sqrt(ur * er); % Calculation of Impedance in Ohm
X1 = R + j * w * L; 
X2 = G + j * w * C;
P = abs(X1 * X2); %Calculation of Propogation Constant
ab = sqrt(X1 * X2);
alpha = real(ab); %Calculation of Attenuation Constant
beta = imag(ab); %Calculation of Phase Constant

fprintf('****PRIMARY CONSTANT OF COAXIAL CABLE****'); 
fprintf('\n Resistance of Conductor in Ohm/meter (R): ');
disp(R);
fprintf('\n Capacitance of Conductor in Farad/meter (C): '); 
disp(C);
fprintf('\n Inductance of Conductor in Henry/meter (L): '); 
disp(L);
fprintf('\n Conductance of Conductor in Simens/meter (G): ');
disp(G);
fprintf('****SECONDARY CONSTANT OF COAXIAL CABLE****');
fprintf('\n Impedance of Conductor in Ohm (Z0): '); 
disp(Z0);
fprintf('\n Propogation Constant of Conductor in radian/meter (gamma): ');
disp(P);
fprintf('\n Attenuation Constant of Conductor in Nepers/meter (alpha): '); 
disp(alpha);
fprintf('\n Phase Constant of Conductor in Radian/meter (beta): '); 
disp(beta);