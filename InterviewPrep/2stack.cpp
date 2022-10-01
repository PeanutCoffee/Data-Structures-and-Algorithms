#include<iostream>
#include<stdlib.h>

using namespace std;

class twoStacks
{
	int *arr;
	int size;
	int top1, top2;
public:
twoStacks(int n)
{
	size = n;
	arr = new int[n];
	top1 = -1;
	top2 = size;
}

//push an element x to stack1
void push1(z x)
{

	if (top1 < top2 - 1)	
	{
		top1++;
		arr[top1] = x;
	}
	else
	{
		cout << "Stack Overflow";
		exit(1);
	}
}






// push an element x to stack2
void push2(int x)
{

	if (top1 < top2 - 1)
	{
		top2--;
		arr[top2] = x;
	}
	else
	{
		cout << "Stack Overflow";
		exit(1);
	}
}

// pop an element from first stack
int pop1()
{
	if (top1 >= 0 )
	{
		int x = arr[top1];
		top1--;
		return x;
	}
	else
	{
		cout << "Stack UnderFlow";
		exit(1);
	}
}

// pop an element from second stack
int pop2()
{
	if (top2 < size)
	{
		int x = arr[top2];
		top2++;
		return x;
	}
	else
	{
		cout << "Stack UnderFlow";
		exit(1);
	}
}
};
void display()
{
	int i;

	if(top1==-1)
	{
		printf("\nStack 1 is empty!!");
	}
	else
	{
		printf("\nStack 1 is...\n");
		for(i=top1;i>=0;--i)
			printf("%d\n",arr[i]);
	}

	if(top2==-1)
	{
		printf("\nStack 2 is empty!!");
	}
	else
	{
		printf("\nStack 2 is...\n");
		for(i=top2;i>=top1;--i)
			printf("%d\n",arr[i]);
	}
}



int main()
{
    int siz,ch,ele,resp;
    cout<<"Enter the size of array";
    cin>>siz;
    twoStacks ts(siz);
   do
   {
    cout<<"Enter your operation \n1 to push in first stack\n2 to push in second stack\n3 to pop in first stack\n4 to pop in second stack\n5 to exit";
    disp();
    cin>>ch;
    switch(ch)
    {

    case 1:cin>>ele;
    ts.push1(ele);
    break;
    case 2:cin>>ele;
    ts.push2(ele);
    break;
    case 3:cin>>ele;
    ts.pop1(ele);
    break;
    case 4:cin>>ele;
    ts.pop2(ele);
    break;

    }
    }
    while(resp='y'||'Y');

	return 0;
}

