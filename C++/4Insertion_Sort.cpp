#include <iostream>
using namespace std;
void insertionsort(int nums[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current_val = nums[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (current_val < nums[j])
            {
                nums[j + 1] = nums[j];
            }
            else
            {
                break;
            }
        }
        nums[j + 1] = current_val;
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int nums[20];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    insertionsort(nums, n);
    return 0;
}