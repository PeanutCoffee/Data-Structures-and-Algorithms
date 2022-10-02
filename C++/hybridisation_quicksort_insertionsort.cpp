#include<iostream>
using namespace std;
void insertion_sort(int a[],int n)
{
           for(int i=1;i<n;i++)
           {
                      int temp=a[i];
                      int j=i-1;
                      while(j>=0&&a[j]>temp)
                      {
                                 a[j+1]=a[j];
                                 j--;
                      }
                      a[j+1]=temp;
           }
}
int partition_scheme(int a[],int p,int r)
{
           int pivot=a[0];
           while(p<r)
           {
                      while(a[p]<=pivot)
                                 p++;
                      while(a[r]>pivot)
                                 r--;
                      if(p<r)
                      {
                                 int temp=a[p];
                                 a[p]=a[r];
                                 a[r]=temp;
                      }
           }
           int temp=a[0];
           a[0]=a[r];
           a[r]=temp;
           return r;
}
void quick_sort(int a[],int p,int r)
{
           if(p<r)
           {
                      int q=partition_scheme(a,p,r);
                      quick_sort(a,p,q-1);
                      quick_sort(a,q+1,r);
           }
}
int main()
{
           int a[200],n;
           cout<<"Enter the number of elements:";
           cin>>n;
           cout<<"Enter the array:\n";
           for(int i=0;i<n;i++)
                      cin>>a[i];
           if(n<=10)
                      insertion_sort(a,n);
           else
                      quick_sort(a,0,n);
           cout<<"Sorted Array:";
           for(int i=0;i<n;i++)
                      cout<<a[i]<<" ";
           return 0;
}
