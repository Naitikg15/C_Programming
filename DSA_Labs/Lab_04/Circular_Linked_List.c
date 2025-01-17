# include <stdio.h>
#include <stdlib.h>

struct CircularLinkedList {
    int data;
    struct CircularLinkedList* next;
};

typedef struct CircularLinkedList Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; // Circular link
        return newNode;
    }
    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; // Circular link
        return newNode;
    }
    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return head;
}

Node* insertAtLocation(Node* head, int position, int data) {
    Node* newNode = createNode(data);
    if (position == 0) {
        return insertAtBeginning(head, data);
    }
    Node* current = head;
    for (int i = 0; i < position - 1 && current->next != head; i++) {
        current = current->next;
    }
    if (current->next == head && position != 1) {
        printf("\nPosition out of bounds\n");
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("\nUnderflow!!!\n");
        return NULL;
    }
    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    if (head->next == head) { // Only one node in the list
        free(head);
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    current->next = head;
    free(temp);
    return head;
}

Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("\nList Underflow!!!\n");
        return NULL;
    }
    Node* current = head;
    Node* prev = NULL;
    while (current->next != head) {
        prev = current;
        current = current->next;
    }
    if (head->next == head) { // Only one node in the list
        free(head);
        return NULL;
    }
    prev->next = head;
    free(current);
    return head;
}

Node* deleteFromLocation(Node* head, int position) {
    if (head == NULL) {
        printf("\nList Underflow!!!\n");
        return NULL;
    }
    if (position == 0) {
        return deleteFromBeginning(head);
    }
    Node* current = head;
    Node* prev = NULL;
    for (int i = 0; i < position && current->next != head; i++) {
        prev = current;
        current = current->next;
    }
    if (current->next == head && position != 0) {
        printf("\nPosition out of bounds\n");
        return head;
    }
    prev->next = current->next;
    free(current);
    return head;
}

void traverse(Node* head) {
    if (head == NULL) {
        printf("\nList Underflow!!!\n");
        return;
    }
    Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Location\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specific Location\n");
        printf("7. Traverse\n");
        printf("8. Exit\n");
        printf("\nEnter your choice: ");
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
        printf("\nDo you want to perform more operations? [Y to continue] ");
        char c;
        scanf(" %c", &c); // This is to consume the newline character left by scanf
        if (c != 'Y' && c != 'y') {
            break;
        }
    } while (1);

    return 0;
}
