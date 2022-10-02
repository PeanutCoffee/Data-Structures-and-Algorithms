clc;
clear all;
close all;
n = input('Number of Symbols:');
p = zeros(1, n);
for i=1:n
fprintf('Give the probability for %dth symbol:', i);
p(i) = input('');
end
[p, I] = sort(p, 'descend');
codes = getCodes(p, 1);
Lk_pk = zeros(1, n);
for i=1:length(codes)
fprintf('\nCode for %dth Symbol: ', I(i));
fprintf('%g ', codes{i});
fprintf('\n');
Lk_pk(i) = length(codes{i}) * p(i);
end
avg_L = sum(Lk_pk);
Entropy = 0;
for i=1:n
Entropy = Entropy + (-1 * p(i) * log2(p(i)));
end
fprintf('\nEntropy: %f\n', Entropy);
efficiency = (Entropy / avg_L) * 100;
fprintf('\nEfficiency: %f\n', efficiency);
function codes=getCodes(p, tp)
if (length(p) == 1 || length(p) == 2)
if (length(p) == 2)
codes = {[0]; [1]};
else
codes = {[]};
end
else
sum = 0;
prevSum = 0;
codes = cell(length(p), 1);
index = -1;
mid = tp/2;
first = 1;
for i=1:length(p)
prevSum = sum;
sum = sum + p(i);
if (sum <= tp / 2)
codes{i} = [0];
else
if (abs(tp/2 - sum) <= abs(tp/2 - prevSum))
codes{i} = [0];
else
if (first)
index = i;
first = 0;
mid = prevSum;
end
codes{i} = [1];
end
end
end
%Recursively Getting the codes
codesUp = getCodes(p(1:index - 1), mid);
codesDown = getCodes(p(index:length(p)), tp - mid);
%Concatenating
i = 1;
j = 1;
while(j <= length(codesUp))
codes{i} = [codes{i}, codesUp{j}];
i = i + 1;
j = j + 1;
end
j = 1;
while (j <= length(codesDown))
codes{i} = [codes{i}, codesDown{j}];
i = i + 1;
j = j + 1;
end
end
end