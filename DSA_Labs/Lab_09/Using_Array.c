#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

// Function to enqueue an element
void enqueue(int element) {
    if (rear == SIZE - 1) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = element;
        printf("Enqueued %d\n", element);
    }
}

// Function to dequeue an element
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        return queue[front++];
    }
}

// Function to display the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
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
    printf("Dequeued: %d\n", dequeue());
    display();
    return 0;
}
