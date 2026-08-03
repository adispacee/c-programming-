// pointers to find the smallest element in a dynamically allocated array
#include <stdio.h>
#include <stdlib.h>

// Function to find smallest element using pointers
int findSmallest(int *arr, int n) {
    int *ptr = arr;       // pointer to array
    int min = *ptr;       // assume first element is smallest

    for (int i = 1; i < n; i++) {
        if (*(ptr + i) < min) {
            min = *(ptr + i);
        }
    }
    return min;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Reading elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    // Calling function
    int smallest = findSmallest(arr, n);

    // Display result
    printf("Smallest element = %d\n", smallest);

    // Free memory
    free(arr);

    return 0;
}
