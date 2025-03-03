#  Addition of Two Polynomials using Arrays

## **Step 1: Implement `main` function**
1. Declare arrays `poly1[]`, `poly2[]`, and `result[]`.
2. Read `deg1` and coefficients for `poly1[]`.
3. Read `deg2` and coefficients for `poly2[]`.
4. Call `addPolynomials(poly1, poly2, result, deg1, deg2)`.
5. Wait for user input before exiting.

## **Step 2: Define the function `addPolynomials`**
1. Accept arrays `poly1[]`, `poly2[]`, and `result[]` along with degrees `deg1` and `deg2`.
2. Find the maximum degree `maxDeg` of the two polynomials.
3. Initialize `result[]` with zeros.

## **Step 3: Align and add polynomials**
1. Copy `poly1[]` into `result[]`, shifting indices based on `(maxDeg - deg1)`.
2. Add `poly2[]` into `result[]`, aligning with `(maxDeg - deg2)`.
3. Sum corresponding coefficients.

## **Step 4: Print the resultant polynomial**
1. Iterate over `result[]` from highest to lowest exponent.
2. Display the polynomial in the form `ax^b + cx^d + ...`.

## **Step 5: End**


#include <stdio.h>
#include <conio.h>

void addPolynomials(int poly1[], int poly2[], int result[], int deg1, int deg2) {
    int maxDeg = (deg1 > deg2) ? deg1 : deg2;
    int minDeg = (deg1 < deg2) ? deg1 : deg2;
    int i;

    for (i = 0; i <= maxDeg; i++) {
        result[i] = 0;
    }

    for (i = 0; i <= deg1; i++) {
        result[i + (maxDeg - deg1)] = poly1[i];
    }

    for (i = 0; i <= deg2; i++) {
        result[i + (maxDeg - deg2)] += poly2[i];
    }

    printf("\nResultant Polynomial: ");
    for (i = 0; i <= maxDeg; i++) {
        printf("%dx^%d", result[i], maxDeg - i);
        if (i < maxDeg) {
            printf(" + ");
        }
    }
}

int main() {
    int poly1[10], poly2[10], result[10];
    int deg1, deg2, i;

    clrscr();

    printf("Enter the degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter coefficients of first polynomial: ");
    for (i = 0; i <= deg1; i++) {
        scanf("%d", &poly1[i]);
    }

    printf("Enter the degree of second polynomial: ");
    scanf("%d", &deg2);
    printf("Enter coefficients of second polynomial: ");
    for (i = 0; i <= deg2; i++) {
        scanf("%d", &poly2[i]);
    }

    addPolynomials(poly1, poly2, result, deg1, deg2);

    getch();
    return 0;
}
