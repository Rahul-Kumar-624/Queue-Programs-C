#include <stdio.h>
#define SIZE 5

struct Element {
    int data;
    int priority;
} pq[SIZE];

int size = 0;

void insert(int data, int priority) {
    if (size == SIZE) {
        printf("Priority Queue Overflow!\n");
    } else {
        pq[size].data = data;
        pq[size].priority = priority;
        size++;
        printf("Inserted: %d with Priority: %d\n", data, priority);
    }
}

int getHighestPriorityIndex() {
    int highestPriority = pq[0].priority;
    int index = 0;
    for (int i = 1; i < size; i++) {
        // Lower value = higher priority (or vice versa based on requirement)
        if (pq[i].priority < highestPriority) {
            highestPriority = pq[i].priority;
            index = i;
        }
    }
    return index;
}

void deleteHighest() {
    if (size == 0) {
        printf("Priority Queue Underflow!\n");
    } else {
        int index = getHighestPriorityIndex();
        printf("Deleted element with highest priority: %d (Priority: %d)\n", pq[index].data, pq[index].priority);
        for (int i = index; i < size - 1; i++) {
            pq[i] = pq[i + 1];
        }
        size--;
    }
}

void display() {
    if (size == 0) {
        printf("Priority Queue is Empty!\n");
    } else {
        printf("Remaining elements in Priority Queue:\n");
        for (int i = 0; i < size; i++) {
            printf("Data: %d | Priority: %d\n", pq[i].data, pq[i].priority);
        }
    }
}

int main() {
    // Insert 10 (priority 2), 20 (priority 1), 30 (priority 3)[cite: 1]
    insert(10, 2);
    insert(20, 1);
    insert(30, 3);

    // Delete highest priority element[cite: 1]
    deleteHighest();

    // Display remaining elements[cite: 1]
    display();

    return 0;
}