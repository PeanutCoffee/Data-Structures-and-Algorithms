// C program for implementation of Bubble sort
#include <stdio.h>

void bubbleSort(int arr[], int n)
{
int i, j, temp;
for (i = 0; i < n-1; i++)

	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
		{
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
}

int main()
{
	int s,x,arr[20];
	printf("Enter the array size");
	scanf("%d",&s);
	printf("Enter the array elements");
	for(int i=0;i<s;i++)
		scanf("%d",&arr[i]);

	
	bubbleSort(arr, s);
	printf("Sorted array: \n");
	for (int i=0; i < s; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
