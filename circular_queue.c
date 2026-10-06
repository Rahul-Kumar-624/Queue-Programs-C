#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

void insert(int element) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Queue is Full!\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("Inserted: %d\n", element);
    }
}

void delete() {
    if (front == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Deleted: %d\n", items[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Circular Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", items[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    // Insert 10, 20, 30, 40[cite: 1]
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    // Delete two elements[cite: 1]
    delete();
    delete();

    // Insert 50, 60[cite: 1]
    insert(50);
    insert(60);

    // Display elements[cite: 1]
    display();

    return 0;
}