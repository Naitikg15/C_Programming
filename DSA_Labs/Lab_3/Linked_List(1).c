#include <stdio.h>
#include <stdlib.h>

struct Linked_list {
    int data;
    struct Linked_list *next;
};
typedef struct Linked_list Node;

Node* insertion_at_beginning(Node* head, int ele) {
    Node* avail = (Node*)malloc(sizeof(Node));
    avail->data = ele;
    avail->next = head;
    head = avail;
    return head;
}

Node* insertion_at_the_end(Node* head, int ele) {
    Node* avail = (Node*)malloc(sizeof(Node));
    avail->data = ele;
    avail->next = NULL;
    if (head == NULL) {
        return avail;
    }
    Node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = avail;
    return head;
}

Node* insertion_at_any_location(Node* head, int position, int ele) {
    Node* avail = (Node*)malloc(sizeof(Node));
    avail->data = ele;
    if (position == 1) {
        avail->next = head;
        return avail;
    }
    Node* ptr = head;
    for (int i = 1; i < position - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Position out of range\n");
        free(avail);
        return head;
    }
    avail->next = ptr->next;
    ptr->next = avail;
    return head;
}

Node* deletion_from_the_beginning(Node* head) {
    if (head == NULL) return NULL;
    Node* ptr = head->next;
    free(head);
    return ptr;
}

Node* deletion_from_the_end(Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* ptr = head;
    Node* prev = NULL;
    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    free(ptr);
    return head;
}

Node* deletion_from_any_location(Node* head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 1) {
        Node* newHead = head->next;
        free(head);
        return newHead;
    }
    Node* ptr = head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    if (ptr == NULL || ptr->next == NULL) {
        printf("Position out of range\n");
        return head;
    }
    Node* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    return head;
}

void traverse(Node* head) {
    Node* ptr = head;
    printf("\nLinked List: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void reverse_traverse(Node* head) {
    if (head == NULL) {
        return;
    }
    reverse_traverse(head->next);
    printf("%d ", head->data);
}

Node* search(Node* head, int target) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    int ele;
    char ch = 'Y';
    printf("Enter the first element of the Linked List: ");
    scanf("%d", &ele);
    Node* Node1 = (Node*)malloc(sizeof(Node));
    Node1->data = ele;
    Node1->next = NULL;
    Node* head = Node1;
    printf("\nDo you want to perform operations? [Y to continue]: ");
    scanf(" %c", &ch);  // Use a leading space to handle newline
    while (ch == 'Y' || ch == 'y') {
        int choice;
        printf("Choose one of the following Operations:\n1. Insert an element at the beginning.\n2. Insert an element at the last.\n3. Insert an element at a specific location.\n4. Deletion from the beginning.\n5. Deletion from the End.\n6. Deletion from any specific location.\n7. Print the Linked List.\n8. Reverse Traversal.\n9. Search an element.\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                printf("Enter the element you want to insert: ");
                scanf("%d", &ele);
                head = insertion_at_beginning(head, ele);
                printf("\n");
                break;

            case 2:
                printf("Enter the element you want to insert: ");
                scanf("%d", &ele);
                head = insertion_at_the_end(head, ele);
                printf("\n");
                break;

            case 3:
                printf("Enter the element you want to insert: ");
                scanf("%d", &ele);
                int pos;
                printf("Enter the position to which you want to insert the element: ");
                scanf("%d", &pos);
                head = insertion_at_any_location(head, pos, ele);
                printf("\n");
                break;

            case 4:
                head = deletion_from_the_beginning(head);
                printf("Element Deleted!\n");
                break;

            case 5:
                head = deletion_from_the_end(head);
                printf("Element Deleted!\n");
                break;

            case 6:
                printf("Enter the position from which you want to remove the element: ");
                int position;
                scanf("%d", &position);
                head = deletion_from_any_location(head, position);
                printf("\n");
                break;

            case 7:
                traverse(head);
                break;

            case 8:
                printf("\nReverse Linked List: ");
                reverse_traverse(head);
                printf("\n");
                break;

            case 9:
                printf("Enter the element you want to find: ");
                scanf("%d", &ele);
                Node* ans = search(head, ele);
                printf("\n");
                if (ans == NULL) {
                    printf("Element Not Found in the Linked List\n");
                } else {
                    printf("Element found in the Linked List!\n");
                }
                break;

            default:
                printf("Enter a Valid Choice!\n");
                break;
        }
        printf("\nDo you want to perform more operations? [Y to continue]: ");
        scanf(" %c", &ch);  // Use a leading space to handle newline
    }

    return 0;
}
