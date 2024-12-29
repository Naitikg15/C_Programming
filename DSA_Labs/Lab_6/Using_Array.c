#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Define the maximum size of the stack

// Define the structure for the stack
struct Stack {
    int items[MAX];
    int top;
};

typedef struct Stack Stack;

// Function to create a stack
void createStack(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("\nStack overflow! Cannot push %d\n", data);
        return;
    }
    stack->items[++stack->top] = data;
    printf("%d pushed onto the stack\n", data);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("\nStack underflow! Cannot pop\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Function to display the stack
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("\nThe stack is empty\n");
        return;
    }
    printf("\nStack elements:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->items[i]);
    }
}

int main() {
    Stack stack;
    createStack(&stack);
    int choice, data;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter data to push onto the stack: ");
            scanf("%d", &data);
            push(&stack, data);
            break;
        case 2:
            data = pop(&stack);
            if (data != -1) {
                printf("\n%d popped from the stack\n", data);
            }
            break;
        case 3:
            display(&stack);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
