#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

void insertFront(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque Overflow!\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front--;
        }
        deque[front] = value;
        printf("Inserted at Front: %d\n", value);
    }
}

void insertRear(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque Overflow!\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = value;
        printf("Inserted at Rear: %d\n", value);
    }
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow!\n");
    } else {
        printf("Deleted from Front: %d\n", deque[front]);
        if (front == rear) { // Sirf 1 element bacha ho toh reset karein
            front = -1;
            rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow!\n");
    } else {
        printf("Deleted from Rear: %d\n", deque[rear]);
        if (front == rear) { // Sirf 1 element bacha ho toh reset karein
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = SIZE - 1;
        } else {
            rear--;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Deque is Empty!\n");
    } else {
        printf("Deque elements: ");
        int i = front;
        while (1) {
            printf("%d ", deque[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    // Question 3 ke according operations[cite: 1]:
    insertFront(10);
    insertRear(20);
    insertFront(30);

    deleteFront();
    deleteRear();

    display();

    return 0;
}