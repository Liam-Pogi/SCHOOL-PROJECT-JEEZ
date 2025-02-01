# My C Data Structures Repository  

This repository contains implementations of **data structures** in **C**, including:  

## 🔗 Single Linked List
	  🎥 https://asciinema.org/a/3HZP0BwyJ6PhEHsmeE1E4Jxyf

### 📌 Quick Code Snippet
```c
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
```
👉 [Click Here for the source code](https://github.com/Liam-Pogi/SCHOOL-PROJECT-JEEZ/blob/main/source_code/linked_list.c)

## 🔗 Doubly Linked List
	 🎥 https://asciinema.org/a/hgP9wo29FRamtcRoUNlG3tDmQ

### 📌 Quick Code Snippet
```
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
```
👉 Click here to see the full source code

## 🔗 Circular Linked List  
	 🎥 https://asciinema.org/a/MdzUJkYGADCLRNjraw0F0ifxe

### 📌 Quick Code Snippet

```c
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
```
👉Click here to see the full source code

## 🔗 Stacks
	 🎥 https://asciinema.org/a/bzWGHqBby0W0MGMsKjJSRM4VP

### 📌 Quick Code Snippet

```c
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
```
👉 Click here to see the full source code

## 🔗 Queues  
	 🎥 https://asciinema.org/a/XTrJ1VnlJxTcvTJoVXObmSqw7


### 📌 Quick Code Snippet

```c
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
```
👉 Click here to see the full source code

## 🔗 Trees  
	 🎥 https://asciinema.org/a/LYJGCUsrS9JpPNYOh1QbiOhcr


### 📌 Quick Code Snippet

```c
 typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}
```
👉 Click here to see the full source code

## 🔗 Graphs
	 🎥 https://asciinema.org/a/EyCEomwterhB6WanlbG7oAMWm

### 📌 Quick Code Snippet

```c
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}
```
👉 Click here to see the full source code

## 🔗 Heaps  
	 🎥 https://asciinema.org/a/4Pfo6tva9nSOqWTLJBSu66AZM


###📌 Quick Code Snippet

```c
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
    printf("Inserted: %d\n", value);
}
```
👉 Click here to see the full source code


## 🚀 How to Compile and Run  
```sh
gcc myprogram.c -o myprogram  
./myprogram
```
