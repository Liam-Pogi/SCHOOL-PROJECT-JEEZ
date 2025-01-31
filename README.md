# My C Data Structures Repository  

This repository contains implementations of **data structures** in **C**, including:  

## 🔗 Single Linked List
	  🎥 https://asciinema.org/a/3HZP0BwyJ6PhEHsmeE1E4Jxyf

### 📂 Source Code

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    displayList(head);
    return 0;
}
```

## 🔗 Doubly Linked List
	 🎥 https://asciinema.org/a/hgP9wo29FRamtcRoUNlG3tDmQ

### 📂 Source Code

```c
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
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayListReverse(struct Node* tail) {
    struct Node* temp = tail;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    insertAtBeginning(&head, &tail, 10);
    insertAtBeginning(&head, &tail, 20);
    insertAtBeginning(&head, &tail, 30);

    printf("Forward: ");
    displayListForward(head);

    printf("Reverse: ");
    displayListReverse(tail);

    return 0;
}

```

## 🔗 Circular Linked List  
	 🎥 https://asciinema.org/a/MdzUJkYGADCLRNjraw0F0ifxe

### 📂 Source Code

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void displayList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printf("Circular Linked List: ");
    displayList(head);
    return 0;
}
```

## 🔗 Stacks
	 🎥 https://asciinema.org/a/bzWGHqBby0W0MGMsKjJSRM4VP

### 📂 Source Code

```c
#include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack is full! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("Pushed: %d\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty! Cannot pop.\n");
    } else {
        printf("Popped: %d\n", stack[top--]);
    }
}

void display() {
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

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}
```

## 🔗 Queues  
	 🎥 https://asciinema.org/a/XTrJ1VnlJxTcvTJoVXObmSqw7


###  📂 Source Code

```c
#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = 0, rear = 0;

void enqueue(int value) {
    if (rear == SIZE) {
        printf("Queue is full!\n");
    } else {
        queue[rear++] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {
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
        for (int i = front; i < rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
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
```

## 🔗 Trees  
	 🎥 https://asciinema.org/a/LYJGCUsrS9JpPNYOh1QbiOhcr


###  📂 Source Code

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) 
        root->left = insert(root->left, data);
    else 
        root->right = insert(root->right, data);
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
```

## 🔗 Graphs
	 🎥 https://asciinema.org/a/EyCEomwterhB6WanlbG7oAMWm

###  📂 Source Code

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (!graph) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    if (!graph->adjLists) {
        printf("Memory allocation failed\n");
        free(graph);
        return NULL;
    }
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    if (!newNode) return;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    if (!newNode) return;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("\nVertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices = 4;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);

    printGraph(graph);

    return 0;
} 
```

## 🔗 Heaps  
	 🎥 https://asciinema.org/a/4Pfo6tva9nSOqWTLJBSu66AZM


### 📂SOURCE CODE:

```c
#include <stdio.h>

#define SIZE 10

int heap[SIZE], heapSize = 0;

void insert(int value) {
    if (heapSize == SIZE) {
        printf("Heap is full! Cannot insert %d\n", value);
        return;
    }
    heap[heapSize] = value;
    int i = heapSize;
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
    heapSize++;
}

void display() {
    if (heapSize == 0) {
        printf("Heap is empty!\n");
    } else {
        printf("Heap: ");
        for (int i = 0; i < heapSize; i++) {
            printf("%d ", heap[i]);
        }
        printf("\n");
    }
}

int main() {
    insert(10);
    insert(20);
    insert(15);
    display();
    return 0;
}
```

## 🚀 How to Compile and Run  
```sh
gcc myprogram.c -o myprogram  
./myprogram
```
Analyze each algorithms and provide the following results in tabular format:
![0Part 1](https://github.com/user-attachments/assets/dbbd8fce-8eb0-4e0d-91c3-8ebac6dbcc87)
![0Part2](https://github.com/user-attachments/assets/542a2017-e70d-4476-8e66-69e669bf202f)
