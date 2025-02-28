# Reverse a String Using Pointers 
## Algorithm 

### 1. Start

### 2. Define `main()` function
   - Declare a character array `str` of sufficient size.
   - Prompt the user to enter a string.
   - Read the string using `scanf()`.
   - Call `reverseString(str)`.
   - Print the reversed string.
   - End.

### 3. Define function `reverseString(str)`
   - Declare two character pointers:  
     - `start` pointing to the first character of `str`.  
     - `end` pointing to the last character of `str` (before `\0`).
   - Loop while `start < end`:
     - Swap `*start` and `*end` using a temporary variable.
     - Move `start` one step forward.
     - Move `end` one step backward.
   - End.

### 4. End

  
#include <stdio.h>
#include <string.h>
#include <conio.h>

void reverseString(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    char temp;

    while (start < end) {
	temp = *start;
	*start = *end;
	*end = temp;

	start++;
	end--;
    }
}

int main() {
    char str[100];
    clrscr();

    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    getch();
    return 0;
}
