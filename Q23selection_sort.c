# Selection Sort Algorithm

## Algorithm:

### Step 1: Input the Array
1. Start.
2. Declare an array `arr[]` and an integer `n` for the number of elements.
3. Accept `n` from the user.
4. Input `n` elements into the array.

### Step 2: Selection Sort Process
5. Loop through the array from index `0` to `n-2`:
   - Set `minIndex = i` (assume the first element is the minimum).
   - Loop from `j = i + 1` to `n-1`:
     - If `arr[j] < arr[minIndex]`, update `minIndex = j`.
   - If `minIndex` is not equal to `i`, swap `arr[i]` and `arr[minIndex]`.

### Step 3: Output the Sorted Array
6. Print the sorted array.
7. Stop.


```c
#include <stdio.h>
#include <conio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
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

    selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    getch();
    return 0;
}
