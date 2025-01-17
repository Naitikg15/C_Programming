#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure for BFS
struct Queue {
    int items[MAX];
    int front, rear;
};

// Stack structure for DFS
struct Stack {
    int items[MAX];
    int top;
};

// Initialize a queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isQueueEmpty(struct Queue *q) {
    return q->front == -1;
}

// Enqueue an element
void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}

// Dequeue an element
int dequeue(struct Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return value;
}

// Initialize a stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isStackEmpty(struct Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(struct Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

// Pop an element from the stack
int pop(struct Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[s->top--];
}

// Breadth-First Search (BFS)
void bfs(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    struct Queue q;
    initQueue(&q);

    printf("BFS Traversal: ");
    enqueue(&q, start);
    visited[start] = 1;

    while (!isQueueEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Depth-First Search (DFS)
void dfs(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    struct Stack s;
    initStack(&s);

    printf("DFS Traversal: ");
    push(&s, start);

    while (!isStackEmpty(&s)) {
        int node = pop(&s);

        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (graph[node][i] == 1 && !visited[i]) {
                push(&s, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[MAX][MAX], n, start, choice;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    do {
        printf("\nGraph Traversal Options:\n");
        printf("1. Breadth-First Search (BFS)\n");
        printf("2. Depth-First Search (DFS)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bfs(graph, n, start);
                break;
            case 2:
                dfs(graph, n, start);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
