# Insertion Sort Algorithm

## Algorithm:

### Step 1: Input the Array
1. Start.
2. Declare an array `arr[]` and an integer `n` for the number of elements.
3. Accept `n` from the user.
4. Input `n` elements into the array.

### Step 2: Sorting using Insertion Sort
5. Loop through the array from index `1` to `n-1`:
   - Store `arr[i]` in `key`.
   - Initialize `j = i - 1`.
   - While `j >= 0` and `arr[j] > key`:
     - Shift `arr[j]` one position to the right.
     - Decrease `j` by 1.
   - Place `key` at the correct sorted position (`arr[j + 1] = key`).
   - This ensures that the left side of the array remains sorted.

### Step 3: Output the Sorted Array
6. Print the sorted array.
7. Stop.

#include <stdio.h>
#include <conio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    int arr[100];

    clrscr();

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    getch();
    return 0;
}
