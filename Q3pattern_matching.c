Naïve Pattern Matching

1. **Start**

2. **Prompt user for input**
   - Ask the user to enter the text.
   - Ask the user to enter the pattern to search.

3. **Call the `naivePatternMatch` function**
   - Pass `text` and `pattern` as arguments.

4. **Inside `naivePatternMatch` function:**
   - Compute lengths:
     - Calculate the length of the text (`textLen`).
     - Calculate the length of the pattern (`patternLen`).
   - Iterate `i` from `0` to `textLen - patternLen`:
     - Compare each character of the pattern with the substring in the text.
     - If all characters match, print the index (`i+1`).
     - If a mismatch occurs, move to the next index.
   - If no match is found, print `"Pattern not found."`.

5. **End**

#include <stdio.h>
#include <conio.h>
#include <string.h>

void naivePatternMatch(char text[], char pattern[]) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int i, j, found = 0;

    for (i = 0; i <= textLen - patternLen; i++) {
        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLen) {
            printf("Pattern found at index %d\n", i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Pattern not found.\n");
    }
}
int main() {
    char text[100], pattern[50];
    clrscr();

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    naivePatternMatch(text, pattern);

    getch();
    return 0;
}
