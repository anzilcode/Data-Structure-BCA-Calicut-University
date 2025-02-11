// ## Algorithm  

1. Start  
2. Declare variables  
   - arrA[SIZE], arrB[SIZE], arrC[SIZE] → Arrays to store elements  
   - sizeA, sizeB → Variables to store the sizes of input arrays  
   - i → Loop counter  
3. Clear screen using clrscr() (Turbo C-specific)  
4. Input the first array  
   - Prompt the user: "Enter the size of first Array:"  
   - Read sizeA using scanf("%d", &sizeA)  
   - Prompt the user: "Enter the elements:"  
   - Read sizeA elements into arrA using a loop  
5. Input the second array  
   - Prompt the user: "Enter the size of second Array:"  
   - Read sizeB using scanf("%d", &sizeB)  
   - Prompt the user: "Enter the elements:"  
   - Read sizeB elements into arrB using a loop  
6. Merge the arrays  
   - Copy all elements of arrA into arrC  
   - Copy all elements of arrB into arrC after arrA  
7. Display the merged array  
   - Print "Combined array:"  
   - Loop through arrC and print all elements using printf("%d ", arrC[i])  
8. Wait for user input using getch() (Turbo C-specific)  
9. End  

---

## Code Implementation  
```c
#include <stdio.h>
#include <conio.h>

#define SIZE 10

int main() {
    int arrA[SIZE], arrB[SIZE], arrC[SIZE];
    int sizeA, sizeB, i;

    clrscr();

    printf("Enter the size of first Array: ");
    scanf("%d", &sizeA);

    printf("Enter the elements: ");
    for (i = 0; i < sizeA; i++) {
        scanf("%d", &arrA[i]);
    }

    printf("Enter the size of second Array: ");
    scanf("%d", &sizeB);

    printf("Enter the elements: ");
    for (i = 0; i < sizeB; i++) {
        scanf("%d", &arrB[i]);
    }

    for (i = 0; i < sizeA; i++) {
        arrC[i] = arrA[i];
    }

    for (i = 0; i < sizeB; i++) {
        arrC[sizeA + i] = arrB[i];
    }

    printf("Combined array: ");
    for (i = 0; i < sizeA + sizeB; i++) {
        printf("%d ", arrC[i]);
    }

    getch();
    return 0;
}
