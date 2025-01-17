#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct DoublyLinkedList {
    int data;
    struct DoublyLinkedList* prev;
    struct DoublyLinkedList* next;
};

typedef struct DoublyLinkedList Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a node at the end
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to insert a node at a specific position
Node* insertAtLocation(Node* head, int position, int data) {
    Node* newNode = createNode(data);
    if (position == 0) {
        return insertAtBeginning(head, data);
    }
    Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to delete a node from the beginning
Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("\nList Underflow!!!\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node from the end
Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("\nList Underflow!!!\n");
        return NULL;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(current);
    return head;
}

// Function to delete a node from a specific position
Node* deleteFromLocation(Node* head, int position) {
    if (head == NULL) {
        printf("\nList Underflow!!!\n");
        return NULL;
    }
    if (position == 0) {
        return deleteFromBeginning(head);
    }
    Node* current = head;
    for (int i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("\nPosition out of bounds\n");
        return head;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
    return head;
}

// Function to traverse and print the list
void traverse(Node* head) {
    printf("\n");
    if (head == NULL) {
        printf("\nList Underflow!!!.\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Location\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specific Location\n");
        printf("7. Traverse\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter data to insert at the beginning: ");
            scanf("%d", &data);
            head = insertAtBeginning(head, data);
            break;
        case 2:
            printf("\nEnter data to insert at the end: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            break;
        case 3:
            printf("\nEnter data to insert: ");
            scanf("%d", &data);
            printf("\nEnter position to insert the data: ");
            scanf("%d", &position);
            head = insertAtLocation(head, position, data);
            break;
        case 4:
            head = deleteFromBeginning(head);
            printf("\nElement deleted from the beginning.\n");
            break;
        case 5:
            head = deleteFromEnd(head);
            printf("\nElement deleted from the end.\n");
            break;
        case 6:
            printf("\nEnter the position from which you want to delete: ");
            scanf("%d", &position);
            head = deleteFromLocation(head, position);
            printf("\nElement deleted from position %d.\n", position);
            break;
        case 7:
            traverse(head);
            break;
        case 8:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
