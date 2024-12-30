#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

// Function to enqueue an element
void enqueue(int element) {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
        printf("Queue is full!\n");
    } else if (front == -1) {
        front = rear = 0;
        queue[rear] = element;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0;
        queue[rear] = element;
    } else {
        queue[++rear] = element;
    }
    printf("Enqueued %d\n", element);
}

// Function to dequeue an element
int dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int element = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
    return element;
}

// Function to display the queue
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
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
