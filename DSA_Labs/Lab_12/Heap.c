#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function prototypes
void heapify(int arr[], int n, int i, int isMaxHeap);
void buildHeap(int arr[], int n, int isMaxHeap);
void heapSort(int arr[], int n, int isMaxHeap);
void insertElement(int arr[], int *n, int value, int isMaxHeap);
void deleteElement(int arr[], int *n, int value, int isMaxHeap);
void reheapUp(int arr[], int i, int isMaxHeap);
void reheapDown(int arr[], int n, int i, int isMaxHeap);
void displayArray(int arr[], int n);

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i, int isMaxHeap) {
    int largestOrSmallest = i; // Initialize largest (for max-heap) or smallest (for min-heap)
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (isMaxHeap) {
        // Max-Heap condition
        if (left < n && arr[left] > arr[largestOrSmallest])
            largestOrSmallest = left;
        if (right < n && arr[right] > arr[largestOrSmallest])
            largestOrSmallest = right;
    } else {
        // Min-Heap condition
        if (left < n && arr[left] < arr[largestOrSmallest])
            largestOrSmallest = left;
        if (right < n && arr[right] < arr[largestOrSmallest])
            largestOrSmallest = right;
    }

    // If root is not largest/smallest, swap and continue heapifying
    if (largestOrSmallest != i) {
        int temp = arr[i];
        arr[i] = arr[largestOrSmallest];
        arr[largestOrSmallest] = temp;
        heapify(arr, n, largestOrSmallest, isMaxHeap);
    }
}

// Function to build a max or min heap
void buildHeap(int arr[], int n, int isMaxHeap) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);
}

// Heap Sort function
void heapSort(int arr[], int n, int isMaxHeap) {
    buildHeap(arr, n, isMaxHeap);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, isMaxHeap);
    }
}

// Function to reheap up (used when inserting a new element)
void reheapUp(int arr[], int i, int isMaxHeap) {
    int parent = (i - 1) / 2;
    if (i > 0) {
        if ((isMaxHeap && arr[i] > arr[parent]) || (!isMaxHeap && arr[i] < arr[parent])) {
            int temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;
            reheapUp(arr, parent, isMaxHeap);
        }
    }
}

// Function to insert an element into the heap
void insertElement(int arr[], int *n, int value, int isMaxHeap) {
    if (*n >= MAX) {
        printf("Heap overflow!\n");
        return;
    }
    arr[*n] = value;
    (*n)++;
    reheapUp(arr, *n - 1, isMaxHeap);
}

// Function to reheap down (used when deleting an element)
void reheapDown(int arr[], int n, int i, int isMaxHeap) {
    heapify(arr, n, i, isMaxHeap);
}

// Function to delete an element from the heap
void deleteElement(int arr[], int *n, int value, int isMaxHeap) {
    int i;
    for (i = 0; i < *n; i++) {
        if (arr[i] == value)
            break;
    }
    if (i == *n) {
        printf("Element not found in heap!\n");
        return;
    }
    arr[i] = arr[*n - 1];
    (*n)--;
    reheapDown(arr, *n, i, isMaxHeap);
}

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX];
    int n = 0, choice, value, isMaxHeap;

    printf("Choose Heap Type:\n1. Max-Heap\n2. Min-Heap\nEnter your choice: ");
    scanf("%d", &isMaxHeap);
    isMaxHeap = (isMaxHeap == 1) ? 1 : 0;

    do {
        printf("\nHeap Operations:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Build Heap\n");
        printf("4. Heap Sort\n");
        printf("5. Display Heap\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertElement(arr, &n, value, isMaxHeap);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteElement(arr, &n, value, isMaxHeap);
                break;
            case 3:
                buildHeap(arr, n, isMaxHeap);
                printf("Heap built successfully!\n");
                break;
            case 4:
                printf("Heap before sorting: ");
                displayArray(arr, n);
                heapSort(arr, n, isMaxHeap);
                printf("Heap after sorting: ");
                displayArray(arr, n);
                break;
            case 5:
                printf("Current Heap: ");
                displayArray(arr, n);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
