## Algorithm for Converting a Matrix to Sparse Matrix Form

### 1. Start

### 2. Define `main()` function
   - Declare a 2D array `a[100][3]` to store the sparse matrix representation.
   - Declare integer variables `m`, `n`, `i`, `j`, `l = 1`, `x`, and `k`.
   - Clear the screen using `clrscr()` (specific to Turbo C).
   - Prompt the user to enter the order (dimensions) of the matrix.
   - Read the values of `m` and `n`.

### 3. Read the matrix elements
   - Print a message to enter the elements.
   - Loop through the matrix using:
     - **Outer loop**: Iterates through `m` rows.
     - **Inner loop**: Iterates through `n` columns.
   - For each element:
     - Read the element `x`.
     - If `x` is **not zero**, store:
       - Row index in `a[l][0]`
       - Column index in `a[l][1]`
       - Value in `a[l][2]`
     - Increment `l`.

### 4. Store metadata for sparse matrix
   - Compute `k = l - 1`, the count of nonzero elements.
   - Store:
     - `m` (number of rows) in `a[0][0]`
     - `n` (number of columns) in `a[0][1]`
     - `k` (nonzero count) in `a[0][2]`

### 5. Print the sparse matrix
   - Print a message: "The sparse matrix is:"
   - Loop through the sparse matrix:
     - Print each row of the 3-column format.

### 6. Wait for user input using `getch()`

### 7. End


#include <stdio.h> 
#include <conio.h>

void main() {
    int a[100][3], m, n, i, j, l = 1, x, k;
    clrscr();

    printf("Enter the order of the matrix: ");
    scanf("%d%d", &m, &n);

    printf("Enter the elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &x);
            if (x != 0) {
                a[l][0] = i; 
                a[l][1] = j;  
                a[l][2] = x;  
                l++;
            }
        }
    }

    k = l - 1; 
    a[0][0] = m;
    a[0][1] = n;
    a[0][2] = k;

    printf("\nThe sparse matrix is:\n");
    for (i = 0; i < l; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
  getch();
}
