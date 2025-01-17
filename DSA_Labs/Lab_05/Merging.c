#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct LinkedList {
    int data;
    struct LinkedList* next;
};

typedef struct LinkedList Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to merge two linked lists
Node* mergeLists(Node* list1, Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    Node* mergedHead = NULL;
    Node* mergedTail = NULL;

    if (list1->data < list2->data) {
        mergedHead = mergedTail = list1;
        list1 = list1->next;
    } else {
        mergedHead = mergedTail = list2;
        list2 = list2->next;
    }

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            mergedTail->next = list1;
            mergedTail = list1;
            list1 = list1->next;
        } else {
            mergedTail->next = list2;
            mergedTail = list2;
            list2 = list2->next;
        }
    }

    if (list1 != NULL) mergedTail->next = list1;
    if (list2 != NULL) mergedTail->next = list2;

    return mergedHead;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* mergedList = NULL;
    int n, data;

    // Input first list
    printf("Enter the number of elements in the first list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &data);
        list1 = insertNode(list1, data);
    }

    // Input second list
    printf("Enter the number of elements in the second list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &data);
        list2 = insertNode(list2, data);
    }

    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    // Merge the two lists
    mergedList = mergeLists(list1, list2);

    printf("Merged List: ");
    displayList(mergedList);

    printf("\nAyushree\n");
    printf("2301641530061\n");

    return 0;
}
