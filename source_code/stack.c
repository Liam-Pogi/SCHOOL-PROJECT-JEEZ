#include <stdio.h>
#define SIZE 5

int stack [SIZE], top = -1;

void push (int value) {
	if (top == SIZE - 1) {
		printf("stack is full! Cannot push %d\n", value);
	} else {
	stack[++top] = value;
	printf("Pushed: %d\n", value);
	}
}


void pop() {
	if (top == -1) {
	printf("stack is empty! Cannot pop.\n");
	} else {
		printf("Popped: %d\n", stack[top--]);
	}
}

void display () {
	if (top == -1) {
	printf("Stack is empty!\n");
	} else {
	printf("Stack: ");
	for (int i = 0; i <= top; i++) {
	printf("%d ", stack[i]);
	}
	printf("\n");
	}
}

int main () {
	push(10);
	push(20);
	push(30);
	display();
	pop();
	display();
	return 0;
}
