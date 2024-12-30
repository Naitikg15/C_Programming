#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int data;
    int priority;
} Element;

Element pq[MAX];
int size = 0;

void insert(int data, int priority) {
    if (size == MAX) {
        printf("Priority Queue is Full\n");
        return;
    }
    Element elem;
    elem.data = data;
    elem.priority = priority;
    int i;
    for (i = size - 1; i >= 0 && pq[i].priority < priority; i--) {
        pq[i + 1] = pq[i];
    }
    pq[i + 1] = elem;
    size++;
    printf("%d with priority %d inserted\n", data, priority);
}

void delete() {
    if (size == 0) {
        printf("Priority Queue is Empty\n");
        return;
    }
    printf("%d with priority %d deleted\n", pq[0].data, pq[0].priority);
    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }
    size--;
}

void display() {
    if (size == 0) {
        printf("Priority Queue is Empty\n");
        return;
    }
    printf("Priority Queue elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("Data: %d Priority: %d\n", pq[i].data, pq[i].priority);
    }
}

int main() {
    insert(4, 1);
    insert(5, 2);
    insert(6, 0);
    display();
    delete();
    display();
    insert(7, 3);
    insert(8, 4);
    display();
    return 0;
}
