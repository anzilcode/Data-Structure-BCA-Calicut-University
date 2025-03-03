### **Algorithm: Quick Sort**

1. **Start**
2. **Main Function**
   - Prompt the user to enter the number of elements and the array elements.
   - Call the QuickSort function to sort the array.
   - Display the sorted array.

3. **QuickSort Function**
   - If the low index is less than the high index:
     - Call the Partition function to get the pivot index.
     - Recursively sort the left and right subarrays.

4. **Partition Function**
   - Select the last element as the pivot.
   - Initialize a pointer for smaller elements.
   - Traverse the array:
     - If an element is smaller than the pivot, swap it.
   - Swap the pivot to its correct position.
   - Return the partition index.

5. **Stop**


#include <stdio.h>
#include <conio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void main() {
    int arr[100], n, i;

    clrscr();

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    getch();
}





