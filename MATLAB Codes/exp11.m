x=3/8;
B=2;
x1=abs(x);
Qx=0;
for k=1:B
    Qxbeq(k)=fix(x1*2);
    Qx=fix(x1*2)/(2^k)+Qx;
    x1=(x1*2)-fix(x1*2);
end
sg=sign(x);
if sg>0
    Qxbeq=[0 Qxbeq];
else
    Qxbeq=[1 Qxbeq];
end
disp('Truncated Number');
disp(Qx);
disp('Binary equivalent of truncated number is:');
disp(Qxbeq);
