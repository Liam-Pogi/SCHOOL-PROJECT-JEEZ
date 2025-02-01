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
    
    // Heapify up (max-heap)
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
    
    heapSize++;
    printf("Inserted: %d\n", value);
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
