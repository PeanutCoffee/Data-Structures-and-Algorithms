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
codes = getCodes(p);
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
function codes=getCodes(p)
if (length(p) == 2)
codes = {[0]; [1]};
else
len = length(p);
p_new = [p(1:len-2), p(len - 1) + p(len)];
p_new = sort(p_new, 'descend');
codes = getCodes(p_new);
codeLen = length(codes);
pos = find(p_new==(p(len - 1) + p(len)));
pos = pos(1);
codes = [codes(1:pos - 1); codes(pos + 1:codeLen); codes(pos); codes(pos)];
codeLen = length(codes);
codes{codeLen} = [codes{codeLen}, 1];
codes{codeLen - 1} = [codes{codeLen - 1}, 0];
end
end