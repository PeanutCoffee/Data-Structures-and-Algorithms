#include <iostream>
using namespace std;
class A
{
public:
    void func1()
    {
        cout << "I am the Parent class funcion" << endl;
    }
};
class B : public A
{
public:
    void func2()
    {
        cout << "I am the 1st child class function which inherits from the Single Parent Class A" << endl;
    }
};
class C : public A
{
public:
    void func3()
    {
        cout << "I am the 2nd child class function which also inherits from the Single Parent Class A" << endl;
    }
};
int main()
{
    A obj1;
    obj1.func1(); // This is the only func of parent class A, therefore any object of A can only access this function
    cout << endl;
    B obj2;
    obj2.func1(); // B is a child class of A, thus it can access the public functions of its parent class
    obj2.func2();
    cout << endl;
    C obj3;
    obj3.func1(); // C is a child class of A, thus it can access the public functions of its parent class
    obj3.func3();
    //*****Note that objects of the two child classes B and C cannot access each other functions, as they are not related to each other in any way. i.e., Although B and C are the child classes of same parent class A, they still cannot access each other's data members and functions*****
    return 0;
}