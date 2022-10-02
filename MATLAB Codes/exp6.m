clc;
clear all;
close all;
N = 2 * 10^5;
Eb_N0_dB = 2 : 20;
sy_hat = zeros(1, N);
nerr = zeros(1, N);
%Signal Transmission and Detection
for i=1:length(Eb_N0_dB)
si = (2 * (rand(1, N) > 0.5) - 1); %In-Phase Symbol Generation || rand(1, N) > 0.5 -> Gives logical Array of 0s and 1s
sq = (2 * (rand(1, N) > 0.5) - 1); %Quadrature Symbol Generation
sy = si + 1i*sq; %Adding the two Symbols
s = (1 / sqrt(2)) * sy;
n = 1 / sqrt(2) * (randn(1, N) + 1i*randn(1, N)); %Random Noise Generation
y = 10 ^ (Eb_N0_dB(i) / 20) * s + n; %Received Signal
si_ = real(y);
sq_ = imag(y);
sy_hat(si_ < 0 & sq_ < 0) = -1 + -1 * 1i;
sy_hat(si_ >= 0 & sq_ > 0) = 1 + 1 * 1i;
sy_hat(si_ < 0 & sq_ >= 0) = -1 + 1 * 1i;
sy_hat(si_ >= 0 & sq_ < 0) = 1 + -1 * 1i;
%BER Calculation
nerr(i) = size(find((sy - sy_hat)), 2); %No. of Errors
end
simu = nerr / N;
theory = erfc(sqrt(0.5 * (10 .^ (Eb_N0_dB/10)))) - (1/4) * (erfc(sqrt(0.5 * (10 .^ (Eb_N0_dB) / 10)))) .^ 2;
semilogy(Eb_N0_dB, theory, 'b-');
hold on;
semilogy(Eb_N0_dB, simu(2:20), 'k+');
axis([2 14 10^-5 1])
grid on
legend('Theory QPSK', 'Simulated QPSK');
xlabel('SNR(dB)');
ylabel('BER');
title('BER for QPSK modulation in AWGN');