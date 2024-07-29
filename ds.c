#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int l, int h) {
    int pivot = arr[l];
    int i = l + 1;
    int j = h;
    while (i <= j) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    // Read the number of runners (finishing times)
    printf("Enter the number of finishing times: ");
    scanf("%d", &n);

    // Allocate memory for the array based on user input
    int *numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read the finishing times
    printf("Enter the finishing times (in minutes):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Sort the array
    quickSort(numbers, 0, n - 1);

    // Print the sorted times
    printf("Sorted finishing times:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Free allocated memory
    free(numbers);

    return 0;
}
