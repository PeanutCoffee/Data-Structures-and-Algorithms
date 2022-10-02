clc;
clear all;
close all;
%Speech Sample CDF and PDF Plot
fileName = ('sing.wav'); % Importing The Speech File
[audioIn_Sample, fs] = audioread(fileName);
info = audioinfo(fileName);
audioIn_Sample = audioIn_Sample';
A = max(audioIn_Sample);
miu = 255;
u_law = ((log(1 + (abs(audioIn_Sample) ./ A) .* miu)) ./ log(1 + miu));
[M, N] = size(u_law);
L = 16;
%Compressing using miu-law
delta = (max(u_law) - min(u_law)) / L;
non_uniform_qs = zeros(1, N);
%Quantization
for i=1:N
start = min(u_law);
while(start < u_law(i))
start = start + delta;
end
non_uniform_qs(i) = start - delta;
if (start == u_law(i))
non_uniform_qs(i) = start;
end
end
%Uniform Quantization
delta_uniform = (max(audioIn_Sample) - min(audioIn_Sample)) / L;
uniform_qs = zeros(1, N);
for i=1:N
start = min(audioIn_Sample);
while(start < audioIn_Sample(i))
start = start + delta_uniform;
end
uniform_qs(i) = start - delta_uniform;
if (start == audioIn_Sample(i))
uniform_qs(i) = start;
end
end
error_uniform = uniform_qs - audioIn_Sample;
error_non_uniform = non_uniform_qs - u_law;
speech_signal_power = mean(audioIn_Sample .^ 2);
u_law_power = mean(u_law .^ 2);
uniform_quantization_power = mean(error_uniform .^ 2);
non_uniform_quantization_power = mean(error_non_uniform .^ 2);
snr_uniform = speech_signal_power / uniform_quantization_power;
snr_non_uniform = u_law_power / non_uniform_quantization_power;
fprintf('Output SNR for Uniform Quantizer: %f\n', snr_uniform);
fprintf('\nOutput SNR for Non-Uniform Quantizer: %f\n', snr_non_uniform);
figure(1);
subplot(3,1,1);
plot(audioIn_Sample);
xlabel('Time');
ylabel('Original Speech Signal');
figure(1);
subplot(3,1,2);
plot(uniform_qs);
xlabel('Time');
ylabel('Uniform Quantized Speech Signal');
figure(1);
subplot(3,1,3);
plot(non_uniform_qs);
xlabel('Time');
ylabel('Non Uniform Quantized Speech Sample');
figure(2);
subplot(1,2,1);
plot(error_uniform);
xlabel('Time');
ylabel('Uniform Quantization Error');
figure(2);
subplot(1,2,2);
plot(error_non_uniform);
xlabel('Time');
ylabel('Non Uniform Quantization Error');