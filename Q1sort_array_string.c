#Sort a Given List of Strings
## Algorithm

1. Start
2. Declare variables
   - `str[25][25]` → To store up to 25 strings of max length 24 characters  
   - `temp[25]` → Temporary variable for swapping  
   - `size` → Number of strings  
   - `i, j` → Loop counters  
3. Clear screen using `clrscr()` (specific to Turbo C)  
4. Prompt the user** to enter the number of strings  
   - Read `size` using `scanf("%d", &size)`
5. Take input for strings
   - Use a loop to read `size` number of strings using `scanf("%24s", str[i])`
6. Sort the strings using Bubble Sort 
   - Run two nested loops:  
     - Outer loop (`i` from `0` to `size-1`) 
     - Inner loop (`j` from `i+1` to `size`)  
     - Compare `str[i]` and `str[j]` using `strcmp(str[i], str[j])`  
     - If `str[i]` is greater than `str[j]`, swap them using `strcpy()`  
7. Display the sorted strings 
   - Loop through `str` and print each string using `printf("%s\n", str[i])`
8. Wait for user input using `getch()`** (Turbo C-specific)  
9. End 

## Code Implementation
```c
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
    char str[25][25], temp[25];
    int size, i, j;
    
    clrscr(); 

    printf("Enter the number of strings: ");
    scanf("%d", &size);

    printf("Enter the strings (one per line):\n");
    for(i = 0; i < size; i++) {
        scanf("%s", str[i]); 
    }

    for(i = 0; i < size - 1; i++) {
        for(j = i + 1; j < size; j++) {
            if(strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\nThe sorted strings are:\n");
    for(i = 0; i < size; i++) {
        printf("%s\n", str[i]);
    }

    getch(); 
    return 0;
}
