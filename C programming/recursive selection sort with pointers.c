#include <stdio.h>

// Function to swap two elements using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive Selection Sort function
void selectionSort(int *arr, int n) {
    // Base case
    if (n <= 1)
        return;

    // Assume first element is minimum
    int *min = arr;

    // Find the minimum element in the array
    for (int *ptr = arr + 1; ptr < arr + n; ptr++) {
        if (*ptr < *min) {
            min = ptr;
        }
    }

    // Swap first element with minimum
    swap(arr, min);

    // Recursively sort remaining array
    selectionSort(arr + 1, n - 1);
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements using pointers
    printf("Enter elements:\n");
    for (int *ptr = arr; ptr < arr + n; ptr++) {
        scanf("%d", ptr);
    }

    // Call recursive selection sort
    selectionSort(arr, n);

    // Print sorted array using pointers
    printf("Sorted array:\n");
    for (int *ptr = arr; ptr < arr + n; ptr++) {
        printf("%d ", *ptr);
    }

    return 0;
}
