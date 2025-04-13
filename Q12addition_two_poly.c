

# Polynomial Addition Using Arrays

## **Algorithm**

### **Step 1: Implement `main` Function**
1. Declare arrays `poly1[]`, `poly2[]`, and `result[]`.
2. Read the degree `deg1` and coefficients for `poly1[]`.
3. Read the degree `deg2` and coefficients for `poly2[]`.
4. Call `addPolynomials(poly1, poly2, result, deg1, deg2)`.
5. Display the resultant polynomial.
6. Wait for user input before exiting.

---

### **Step 2: Define `addPolynomials` Function**
1. Accept input arrays `poly1[]`, `poly2[]`, and `result[]`, along with their degrees `deg1` and `deg2`.
2. Determine the highest degree `maxDeg` among `deg1` and `deg2`.
3. Initialize all elements of `result[]` to zero.

---

### **Step 3: Perform Polynomial Addition**
1. Copy `poly1[]` into `result[]`, aligning indices based on `(maxDeg - deg1)`.
2. Add `poly2[]` into `result[]`, aligning indices based on `(maxDeg - deg2)`.
3. Perform coefficient-wise addition to form the resultant polynomial.

---

### **Step 4: Print the Resultant Polynomial**
1. Traverse `result[]` from the highest exponent to the lowest.
2. Print terms in the format:  
   - If exponent > 0: `ax^b`
   - If exponent = 0: `c` (constant term)
3. Ensure correct formatting by handling cases such as:  
   - Avoiding printing `+` at the end.
   - Skipping terms where the coefficient is zero.

---

### **Step 5: End**



#include <stdio.h>
#include <conio.h>

void addPolynomials(int poly1[], int poly2[], int result[], int deg1, int deg2) {
    int maxDeg = (deg1 > deg2) ? deg1 : deg2;
    int i, coeff1, coeff2;

    for (i = 0; i <= maxDeg; i++) {
        coeff1 = (i <= deg1) ? poly1[i] : 0;
        coeff2 = (i <= deg2) ? poly2[i] : 0;
        result[i] = coeff1 + coeff2;
    }

    printf("\nResultant Polynomial: ");
    for (i = maxDeg; i >= 0; i--) {
        if (result[i] != 0) {
            printf("%d", result[i]);
            if (i > 0) {
                printf("x^%d", i);
            }
            if (i > 0) {
                printf(" + ");
            }
        }
    }
}

void main() {
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
}
