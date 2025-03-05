# Algorithm for Evaluating a Postfix Expression

## Step 1: Define the main function

### Function: main()
- Clear the screen using `clrscr()`.
- Read the postfix expression using `gets()`.
- Call `evaluatePostfix(exp)` to compute the result.
- Print the final result.
- Use `getch()` to wait for user input before exiting.

## Step 2: Define Stack Operations

### Function: push(value)
- If the stack is full, print "Stack Overflow" and return.
- Increment `top` and store `value` in `stack[top]`.

### Function: pop()
- If the stack is empty, print "Stack Underflow" and exit.
- Return `stack[top]` and decrement `top`.

## Step 3: Define the Postfix Evaluation Function

### Function: evaluatePostfix(exp)
- Initialize `num = 0`.
- While there are characters in `exp`:
  - If the character is a digit:
    - Set `num = 0`.
    - While the character is a digit:
      - Multiply `num` by 10 and add the digit to `num`.
      - Move to the next character.
    - Push `num` onto the stack.
  - If the character is an operator:
    - Pop two operands (`opr1`, `opr2`).
    - Perform the corresponding operation:
      - Addition (`+`): `result = opr2 + opr1`
      - Subtraction (`-`): `result = opr2 - opr1`
      - Multiplication (`*`): `result = opr2 * opr1`
      - Division (`/`): Check if `opr1` is zero to avoid division by zero.
    - Push `result` onto the stack.
  - Move to the next character.
- Return the final value from the stack.



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define MAX_SIZE 20

int stack[MAX_SIZE], top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
	printf("Stack Overflow\n");
	return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
	printf("Stack Underflow\n");
	exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char *exp) {
    int num = 0, opr1, opr2, result;
    char ch;

    while (*exp) {
	ch = *exp;

	if (isdigit(ch)) {
	    num = 0;
	    while (isdigit(*exp)) {
		num = num * 10 + (*exp - '0');
		exp++;
	    }
	    push(num);
	}
	else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
	    opr1 = pop();
	    opr2 = pop();

	    switch (ch) {
		case '+': result = opr2 + opr1; break;
		case '-': result = opr2 - opr1; break;
		case '*': result = opr2 * opr1; break;
		case '/':
		    if (opr1 == 0) {
			printf("Error: Division by zero\n");
			return -1;
		    }
		    result = opr2 / opr1;
		    break;
		default:
		    printf("Error: Invalid operator '%c'\n", ch);
		    return -1;
	    }
	    push(result);
	}
	exp++;
    }
    return pop();
}

int main() {
    char exp[100];
    int finalResult;

    clrscr();
    printf("Enter the postfix expression: ");
    gets(exp);

    finalResult = evaluatePostfix(exp);
    if (finalResult != -1) {
	printf("Result of expression = %d\n", finalResult);
    }

    getch();
    return 0;
}
