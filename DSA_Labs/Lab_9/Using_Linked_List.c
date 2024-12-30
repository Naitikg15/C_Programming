#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

// Function to enqueue an element
void enqueue(int element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d\n", element);
}

// Function to dequeue an element
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int element = front->data;
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        free(temp);
        return element;
    }
}

// Function to display the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        Node* temp = front;
        printf("Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
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
