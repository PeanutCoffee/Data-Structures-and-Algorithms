#include<stdio.h>

int arrayin(int ar[],int size){
	int index,x;

	printf("Enter the array position and element you want to enter");
	scanf("%d   %d",&index,&x);

	for(int i=size;i>=index;i--)
	{
		ar[i]=ar[i-1];
	}
	ar[index]=x;
	printf("The array elements are");
	for(int i=0;i<size+1;i++)
		printf("%d  ",ar[i]);


}

int main()
{
	int s,arr[20];
	printf("Enter the array size");
	scanf("%d",&s);
	
	printf("Enter the array elements");
	for(int i=0;i<s;i++)
		scanf("%d",&arr[i]);
	printf("The array elements are");
	for(int i=0;i<s;i++)
		printf("%d  ",arr[i]);
	int ch;
	printf("press 1 to insert and 2 to delete in array");
	scanf("%d",&ch);
	if (ch==1)
	arrayin(arr,s);
}	
