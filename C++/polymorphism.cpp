#include <iostream>
using namespace std;
class A
{
public:
    // This is function Overloading. Although the name of the functions are same, still they dont give an error coz no. of arguments passed in each function is different which helps the objects to determine which function do they have to use.
    int add(int x, int y)
    {
        cout << x + y << endl;
    }
    int add(int a, int b, int c)
    {
        cout << a + b + c << endl;
    }
};
class B
{
    // operator overloading re understand
public:
    int val1, val2, a = 10;
    void operator+(B obj2)
    {
        val1 = this->a;
        val2 = obj2.a;
        cout << "Difference is : " << val1 - val2 << endl;
    }
};
int main()
{
    A obj1;
    obj1.add(10, 20);
    obj1.add(10, 20, 30);
    B obj2;
    obj2.a + obj2.a;
    return 0;
}