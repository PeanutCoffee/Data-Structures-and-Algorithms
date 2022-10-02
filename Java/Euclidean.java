#include <stdio.h>
int counter=0;
int gcdFun(int a,int b)
{
    while (b!=0)
    {
        ++counter;
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
int main()
{
    int num1,num2,i,gcd;
    printf("\n Enter integer  num1:");
    scanf("%d",&num1);
    printf("\n Enter integer num2:");
    scanf("%d",&num2);
    gcd=gcdFun(num1,num2);
    printf("\n GCD of %d and %d is %d and counter is %d\n",num1,num2,gcd,counter);
    return 0;
}
