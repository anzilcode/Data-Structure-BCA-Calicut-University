# Exchange Sort Algorithm

## Algorithm:
1. **Input the Array**
   - Read `n`, the number of elements.
   - Read `n` elements into an array.

2. **Sorting using Exchange Sort**
   - Use a nested loop:
     - Outer loop runs from `0` to `n-1`.
     - Inner loop runs from `i+1` to `n`.
     - Swap `arr[i]` and `arr[j]` if `arr[i] > arr[j]`.

3. **Output the Sorted Array**
   - Print the array elements after sorting.


#include <stdio.h>
#include <conio.h>

void exchangeSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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

    exchangeSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    getch();
    return 0;
}
