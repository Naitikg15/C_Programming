#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int data) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is Full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front = front - 1;
    }
    deque[front] = data;
    printf("%d inserted at the front\n", data);
}

void insertRear(int data) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is Full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear = rear + 1;
    }
    deque[rear] = data;
    printf("%d inserted at the rear\n", data);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque is Empty\n");
        return;
    }
    printf("%d deleted from the front\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front = front + 1;
    }
}

void deleteRear() {
    if (rear == -1) {
        printf("Deque is Empty\n");
        return;
    }
    printf("%d deleted from the rear\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear = rear - 1;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is Empty\n");
        return;
    }
    printf("Deque elements are: ");
    int i = front;
    if (front <= rear) {
        while (i <= rear) {
            printf("%d ", deque[i++]);
        }
    } else {
        while (i <= MAX - 1) {
            printf("%d ", deque[i++]);
        }
        i = 0;
        while (i <= rear) {
            printf("%d ", deque[i++]);
        }
    }
    printf("\n");
}

int main() {
    insertRear(1);
    insertRear(2);
    insertFront(3);
    display();
    deleteFront();
    display();
    insertRear(4);
    insertFront(5);
    display();
    deleteRear();
    display();
    return 0;
}
