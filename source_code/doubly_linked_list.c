#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* next;
struct Node* prev;
};

struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
newNode->prev = NULL;
return newNode;
}

void insertAtBeginning(struct Node** head, struct Node** tail, int data) {
struct Node* newNode = createNode(data);
if (!newNode) return;
newNode->next = *head;
if (*head) (*head)->prev = newNode;
else *tail = newNode;
*head = newNode;
}

void displayListForward(struct Node* head) {
struct Node* temp = head;
while (temp){
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}

void displayListReverse(struct Node* tail) {
struct Node* temp = tail;
while (temp) {
printf("%d -> ", temp->data);
if (temp->prev != NULL) {  
    temp = temp->prev;  
} else {  
    break;  
}
}
printf("NULL\n");
}

int main() {
struct Node* head = NULL;
struct Node* tail = NULL;
insertAtBeginning(&head,&tail, 10);
insertAtBeginning(&head,&tail, 20);
insertAtBeginning(&head,&tail, 30);

printf("Forward: ");
displayListForward(head);

printf("Reverse: ");
displayListReverse(tail);

return 0;
} 
