## Appending Two Arrays
## Algorithm 

### 1. Start

### 2. Define `main()` function
   - Declare integer variables `size1`, `size2`, and `i`.
   - Declare three arrays: `arr1` of size `SIZE`, `arr2` of size `SIZE`, and `result` of size `SIZE * 2`.
   - Prompt user to enter the number of elements in the first array.
   - Read and store the values in `arr1`.
   - Prompt user to enter the number of elements in the second array.
   - Read and store the values in `arr2`.
   - Call `appendArrays(arr1, size1, arr2, size2, result)`.
   - Print the appended array.
   - End.

### 3. Define function `appendArrays(arr1, size1, arr2, size2, result)`
   - Declare integer variables `i` and `j`.
   - Copy all elements of `arr1` into `result`.
   - Copy all elements of `arr2` into `result` after `arr1` elements.
   - Return the appended array.

### 4. End

## Code Implementation  
```c
#include <stdio.h>
#include <conio.h>
#define SIZE 10

void appendArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i, j;

    for (i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }

    for (j = 0; j < size2; j++) {
        result[i + j] = arr2[j];
    }
}

int main() {
    int size1, size2, i;
    int arr1[SIZE], arr2[SIZE], result[SIZE * 2];
    clrscr();

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &size1);

    printf("Enter elements for the first array: ");
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &size2);

    printf("Enter elements for the second array: ");
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    appendArrays(arr1, size1, arr2, size2, result);

    printf("Appended Array: ");
    for (i = 0; i < size1 + size2; i++) {
        printf("%d ", result[i]);
    }

    getch();
    return 0;
}
