    #include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial term
struct PolynomialTerm {
    int coeff;  // Coefficient
    int exp;    // Exponent
    struct PolynomialTerm* next;
};

typedef struct PolynomialTerm Node;

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in the polynomial linked list in decreasing order of exponents
Node* insertNode(Node* head, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (head == NULL || head->exp < exp) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL && current->next->exp >= exp) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to display the polynomial
void displayPolynomial(Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%dx^%d", current->coeff, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* ptr1 = poly1;
    Node* ptr2 = poly2;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exp > ptr2->exp) {
            result = insertNode(result, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        } else if (ptr1->exp < ptr2->exp) {
            result = insertNode(result, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        } else {
            result = insertNode(result, ptr1->coeff + ptr2->coeff, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    
    // Add remaining terms of poly1
    while (ptr1 != NULL) {
        result = insertNode(result, ptr1->coeff, ptr1->exp);
        ptr1 = ptr1->next;
    }
    
    // Add remaining terms of poly2
    while (ptr2 != NULL) {
        result = insertNode(result, ptr2->coeff, ptr2->exp);
        ptr2 = ptr2->next;
    }

    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* sum = NULL;
    int n, coeff, exp;

    // Input first polynomial
    printf("\nEnter the number of terms in the first polynomial: ");
    scanf("\n%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        poly1 = insertNode(poly1, coeff, exp);
    }

    // Input second polynomial
    printf("\nEnter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        poly2 = insertNode(poly2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);
    printf("\nPolynomial 2: ");
    displayPolynomial(poly2);

    // Add the two polynomials
    sum = addPolynomials(poly1, poly2);

    printf("\nSum: ");
    displayPolynomial(sum);

    printf("\nAyushree\n");
    printf("2301641530061\n");

    return 0;
}
