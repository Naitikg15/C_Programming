#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct StackNode {  
    int data;
    struct StackNode* next;
};

typedef struct StackNode Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(Node* root) {
    return !root;
}

// Function to push an element onto the stack
void push(Node** root, int data) {
    Node* newNode = createNode(data);
    newNode->next = *root;
    *root = newNode;
    printf("%d pushed onto the stack\n", data);
}

// Function to pop an element from the stack
int pop(Node** root) {
    if (isEmpty(*root)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }
    Node* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to display the stack
void display(Node* root) {
    if (isEmpty(root)) {
        printf("The stack is empty\n");
        return;
    }
    Node* current = root;
    printf("Stack elements:\n");
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {
    Node* root = NULL;
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
            printf("Enter data to push onto the stack: ");
            scanf("%d", &data);
            push(&root, data);
            break;
        case 2:
            data = pop(&root);
            if (data != -1) {
                printf("%d popped from the stack\n", data);
            }
            break;
        case 3:
            display(root);
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
