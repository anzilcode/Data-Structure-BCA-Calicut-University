## Algorithm for Stack Operations using Array

### 1. Start

### 2. Define global variables
   - `stack[100]`, `top = -1`, `n` (stack size), `x` (element), `ch` (choice), and `i` (loop index)

### 3. Define `main()`
   - Initialize `top = -1`
   - Take user input for `n` (stack size)
   - Display menu with options:
     1. Push
     2. Pop
     3. Display
     4. Exit
   - Perform operations based on user choice

### 4. Define `push()`
   - Check if `top == n - 1` (Stack Overflow)
   - If not, increment `top` and store `x` in `stack[top]`

### 5. Define `pop()`
   - Check if `top == -1` (Stack Underflow)
   - If not, print and remove the top element

### 6. Define `display()`
   - If `top == -1`, print "Stack is empty"
   - Otherwise, print all elements from `top` to `0`

### 7. End


#include<stdio.h>
#include<conio.h>

int stack[100], ch, n, top, x, i;

void push();
void pop();
void display();

void main() {
    clrscr();
    top = -1;

    printf("Enter the size of the stack: ");
    scanf("%d", &n);

    while(1) {
        printf("\nStack Operation\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter the Choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
	    case 4: return;
            default:
                    printf("Invalid Choice\n");
        }
    }
    getch();
}

void push() {
    if(top == n - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter the value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("%d pushed into the stack\n", x);
    }
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("The popped element is: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if(top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for(i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
