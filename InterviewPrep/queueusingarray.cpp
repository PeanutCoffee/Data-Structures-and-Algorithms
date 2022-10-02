//2 a ) Write a program to implement queue using i) array
#include <bits/stdc++.h>
using namespace std;

struct Queue 
{
	int front, rear, capacity;
	int* queue;
	Queue(int c)
	{
		front = rear = 0;
		capacity = c;
		queue = new int;
	}

	~Queue() { delete[] queue; }

	// function to insert an element at the rear position
	void queueEnqueue(int data)
	{
		if (capacity == rear)  // if queue full
		 {
			printf("\nQueue is full\n");
			return;
		}

		else 
		{
			queue[rear] = data;
			rear++;
		}
		return;
	}

	// function to delete an element from front
	void queueDequeue()
	{
		if (front == rear)   // if queue empty
		{
			printf("\nQueue is empty\n");
			return;
		}

		else {
			for (int i = 0; i < rear - 1; i++) {
				queue[i] = queue[i + 1];
			}

			rear--;
		}
		return;
	}

	// print queue elements
	void queueDisplay()
	{
		int i;
		if (front == rear) {
			printf("\nQueue is Empty\n");
			return;
		}

		// traverse front to rear and print elements
		for (i = front; i < rear; i++) {
			printf(" %d <-- ", queue[i]);
		}
		return;
	}

	// print front of queue
	void queueFront()
	{
		if (front == rear) {
			printf("\nQueue is Empty\n");
			return;
		}
		printf("\nFront Element is: %d", queue[front]);
		return;
	}
};

int main(void)
{
	
	Queue q(4); // Create a queue of capacity 4

	q.queueDisplay();

	// inserting elements in the queue
	q.queueEnqueue(20);
	q.queueEnqueue(30);
	q.queueEnqueue(40);
	q.queueEnqueue(50);

	q.queueDisplay();   // print Queue elements

	q.queueEnqueue(60);

	q.queueDisplay();   // print Queue elements

	q.queueDequeue(); // Deleting elements
	q.queueDequeue();

	printf("\n\nafter two node deletion\n\n");
    q.queueDisplay();

	q.queueFront();  // print front of the queue

	return 0;
}