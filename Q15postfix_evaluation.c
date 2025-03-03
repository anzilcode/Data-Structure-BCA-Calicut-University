# Algorithm for Evaluating a Postfix Expression

## Step 1: Initialize Stack
- Create an empty stack to store operands.

## Step 2: Process Each Character in the Expression
- Read the postfix expression from left to right.

## Step 3: If the Character is an Operand (Digit)
- Convert it to an integer.
- Push it onto the stack.

## Step 4: If the Character is an Operator
- Pop two operands from the stack.
- Perform the operation based on the operator.
- Push the result back onto the stack.

## Step 5: Continue Until End of Expression
- Repeat the above steps until the entire expression is processed.

## Step 6: Get the Final Result
- The final result will be the only element left in the stack.


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
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
    int opr1, opr2, result;

    while (*exp != '\0') {
	if (isdigit(*exp)) {
	    push(*exp - '0');
	} else if (*exp == ' ') {
	} else {
	    opr1 = pop();
	    opr2 = pop();

	    switch (*exp) {
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
		    printf("Error: Invalid operator '%c'\n", *exp);
		    return -1;
	    }
	    push(result);
	}
	exp++;
    }
    return pop();
}

int main() {
    char exp[MAX_SIZE];
    clrscr();

    printf("Enter the postfix expression: ");
    scanf("%s", exp);

    int finalResult = evaluatePostfix(exp);
    if (finalResult != -1) {
	printf("Result of expression %s = %d\n", exp, finalResult);
    }

    getch();
    return 0;
}
