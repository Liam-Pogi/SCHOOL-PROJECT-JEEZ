#include <stdio.h>
#define SIZE 5

int queue [SIZE], front = 0, rear = 0;

void enqueue(int value) {
	if (rear == SIZE) {
		printf("Queue us full!\n");
	} else {
		queue[rear++] = value;
		printf("Enqueued: %d\n", value);
	}
}

void dequeue () {
	if (front == rear) {
		printf("Queue is empty!\n");
	} else {
		printf("Dequeued: %d\n", queue[front++]);
	}
}

void display() {
	if (front == rear) {
		printf("Queue is empty!\n");
	} else {
		printf("Queue: ");
		for (int i = front; i < rear; i++)
{		printf("%d ", queue[i]);		}

	}
	printf("\n");
	}
int main() {
	enqueue(10);
	enqueue(20);
	enqueue(30);
	display();
	dequeue();
	display();
	return 0;
}

