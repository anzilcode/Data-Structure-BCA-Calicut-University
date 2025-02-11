# Binary Search in C

## Algorithm

1. Start  
2. Declare variables:  
   - arr[100] → To store the sorted array  
   - size → Number of elements in the array  
   - i → Loop counter  
   - search → Element to be searched  
   - result → Stores the result of the binary search  
3. Take input for the array:  
   - Prompt the user to enter size  
   - Read size using scanf("%d", &size)  
   - Prompt the user to enter the array elements (must be sorted)  
   - Use a loop to read size elements into arr[]  
4. Perform Binary Search:  
   - Initialize low = 0, high = size - 1  
   - While low ≤ high:  
     - Compute mid = low + (high - low) / 2  
     - If arr[mid] == search, return mid (index found)  
     - If arr[mid] < search, update low = mid + 1  
     - Else, update high = mid - 1  
   - If element is not found, return -1  
5. Display the result:  
   - If result == -1, print "Element not present in the array!"  
   - Else, print the position (index + 1) of the element  
6. End  

---

## C Program Implementation 

#include <stdio.h>
#include <conio.h>

int binarySearch(int arr[], int search, int high, int low) {
    int mid;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == search) {
            return mid;
        } else if (arr[mid] < search) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], size, i, search, result;
    clrscr();

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter the elements: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &search);

    result = binarySearch(arr, search, size - 1, 0);

    if (result == -1) {
        printf("Element not present in the array...!");
    } else {
        printf("%d found at position: %d", search, result + 1);
    }

    getch();
    return 0;
}

