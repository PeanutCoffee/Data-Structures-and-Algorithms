//2 b ) Write a program to implement queue using Linked list
#include <bits/stdc++.h>
using namespace std;

struct QNode {
	int data;
	QNode* next;
	QNode(int d)
	{
		data = d;
		next = NULL;
	}
};

struct Queue {
	QNode *front, *rear;
	Queue()
	{
		front = rear = NULL;
	}

	void enQueue(int x)
	{

		QNode* temp = new QNode(x);

		// If queue is empty
		if (rear == NULL) {
			front = rear = temp;
			return;
		}

		rear->next = temp;
		rear = temp;
	}

	// Function to remove from queue
	void deQueue()
	{
		// If queue is empty, return NULL.
		if (front == NULL)
			return;

		QNode* temp = front;
		front = front->next;

		// If front becomes NULL, make rear also null
		if (front == NULL)
			rear = NULL;

		delete (temp);
	}
};

int main()
{

	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.deQueue();
	q.deQueue();
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	cout << "Queue Front : " << (q.front)->data << endl;
	cout << "Queue Rear : " << (q.rear)->data;
}
