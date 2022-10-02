#include <iostream>
using namespace std;

int main() {
	int num1, num2, num3;

    cout<<"Enter first number: ";
    cin>>num1;
    cout<<"Enter second number: ";
    cin>>num2;
    cout<<"Enter third number: ";
    cin>>num3;

    if (num1 > num2) {
        if (num1 > num3) {
            if (num2 > num3)
                cout<<"Second Largest Number is "<<num2<<endl;
            else
                cout<<"Second Largest Number is "<<num3<<endl;
        }
        else
            cout<<"Second Largest Number is "<<num1;
    else
        if (num2 > num3) {
            if (num1 > num3)
                cout<<"Second Largest Number is "<<num1;
            else
                cout<<"Second Largest Number is "<<num3;
        }
        else
            cout<<"Second Largest Number is "<<num2;
    }
    
	return 0;
}