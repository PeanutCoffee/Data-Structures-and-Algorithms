clc;
clear all;
close all;
G = input('Enter Matrix:')
[K, N] = size(G);
m = dec2bin(0:2^K) - '0';
[x, y] = size(m);
m = m(1:(x - 1), 2:y);
x = mod(m*G, 2);
ham_wgt = zeros(1, N);
for i=1:N
s = sum(x(i,:));
if (s > 0)
ham_wgt(i) = s;
else
ham_wgt(i) = 8;
end
end
Wmin = min(ham_wgt);
error_detection_capability = Wmin - 1
error_correction_capability = floor((Wmin - 1) / 2)
P = G(:, 1:N - K);
H = [eye(N - K), P'];
Y = input('Give the Received Vector:')
S = mod(Y * H', 2)
pos = -1;
Ht = H';
for i=1:N
if (S == Ht(i, : ))
pos = i;
end
end
X_cap = Y;
X_cap(pos) = xor(X_cap(pos), 1);