#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

// Function to find the minimum value node in the BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node with one or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// In-order traversal
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Pre-order traversal
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Function to count the total number of nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count the number of internal nodes
int countInternalNodes(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// Function to count the number of external nodes (leaf nodes)
int countExternalNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countExternalNodes(root->left) + countExternalNodes(root->right);
}

// Function to find the height of the tree
int findHeight(struct Node* root) {
    if (root == NULL)
        return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to find the smallest node
int findSmallest(struct Node* root) {
    struct Node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current->data;
}

// Function to find the largest node
int findLargest(struct Node* root) {
    struct Node* current = root;
    while (current->right != NULL)
        current = current->right;
    return current->data;
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. In-order Traversal\n");
        printf("4. Pre-order Traversal\n");
        printf("5. Post-order Traversal\n");
        printf("6. Count Total Nodes\n");
        printf("7. Count Internal Nodes\n");
        printf("8. Count External Nodes\n");
        printf("9. Find Height of Tree\n");
        printf("10. Find Smallest Node\n");
        printf("11. Find Largest Node\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Pre-order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Post-order Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Total Number of Nodes: %d\n", countNodes(root));
                break;
            case 7:
                printf("Number of Internal Nodes: %d\n", countInternalNodes(root));
                break;
            case 8:
                printf("Number of External Nodes: %d\n", countExternalNodes(root));
                break;
            case 9:
                printf("Height of Tree: %d\n", findHeight(root));
                break;
            case 10:
                if (root != NULL)
                    printf("Smallest Node: %d\n", findSmallest(root));
                else
                    printf("Tree is empty.\n");
                break;
            case 11:
                if (root != NULL)
                    printf("Largest Node: %d\n", findLargest(root));
                else
                    printf("Tree is empty.\n");
                break;
            case 12:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 12);

    return 0;
}
