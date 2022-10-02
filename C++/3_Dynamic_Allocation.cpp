#include <bits/stdc++.h>
using namespace std;

void dynamic_int()
{
    int n = 10;       // Static Memory ALlocation :- Stores the data in a stack
    int *p = new int; // Dynamic Allocation :- Stores the data in a heap
    *p = 10;
    cout << n << " " << *p << endl;
}
void dynamic_arr()
{
    int m;
    cin >> m;
    int arr1[m]; // This should not be done because we dont know how much memory the user might assign, and the stack has a limited storage, so if the value of m entered by the user exceeds the storage size of the stack, then the program will crash

    int *arr2 = new int[m]; // This is the correct way of making a variable size array, as the array will now be stored in a heap, whose size can be increased dynamically
}
void dynamic_2D_arr()
{
    int m, n;
    cin >> m >> n;
    int **arr3 = new int[m]; // Declaring Rows Dynamically
    for (int i = 0; i < m; i++)
    {
        arr3[i] = new int[n]; // Declaring Columns Dynamically
        for (int j = 0; j < n; j++)
        {
            cin >> arr3[i][j];
        }
    }
}
int main()
{
    dynamic_int();
    // dynamic_arr();
    // dynamic_2D_arr();
    return 0;
}