## Algorithm for Stack Operations using Linked List

### 1. Start  

### 2. Define Node Structure  
   - Create `struct Node` with:  
     - `int data`  
     - `struct Node* next`  

### 3. Define `main()`  
   - Initialize `struct Node* top = NULL`  
   - Display menu with options:  
     1. Push  
     2. Pop  
     3. Display  
     4. Exit  
   - Perform operations based on user choice  

### 4. Define `push(struct Node** top, int value)`  
   - Allocate memory for a new node  
   - If allocation fails, print `"Heap overflow"`  
   - Assign `value` to `newNode->data`  
   - Set `newNode->next` to `top`  
   - Update `top` pointer  

### 5. Define `pop(struct Node** top)`  
   - If `top` is `NULL`, print `"Stack underflow"`  
   - Otherwise:  
     - Store `top->data` in `poppedValue`  
     - Move `top` to the next node  
     - Free the removed node  
     - Return `poppedValue`  

### 6. Define `display(struct Node* top)`  
   - If `top` is `NULL`, print `"Stack is empty"`  
   - Otherwise:  
     - Traverse the linked list  
     - Print each node's data  

### 7. End  



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
	printf("Heap overflow\n");
	return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto stack.\n", value);
}

int pop(struct Node** top) {
    struct Node* temp = *top;
    int poppedValue;
    if (*top == NULL) {
	printf("Stack underflow\n");
	return -1;
    }
    poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

void display(struct Node* top) {
    if (top == NULL) {
	printf("Stack is empty\n");
	return;
    }
    printf("Stack: ");
    while (top) {
	printf("%d -> ", top->data);
	top = top->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* top = NULL;
    int choice, value;
    clrscr();

    while (1) {
	printf("\n--- Stack Menu ---\n");
	printf("1. Push\n2. Pop\n3. Display Stack\n4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter value to push: ");
		scanf("%d", &value);
		push(&top, value);
		break;
	    case 2:
		value = pop(&top);
		if (value != -1)
		    printf("%d popped from stack.\n", value);
		break;
	    case 3:
		display(top);
		break;
	    case 4:
		printf("Exiting...\n");
		exit(0);
	    default:
		printf("Invalid choice, try again.\n");
	}
    }
    getch();
    return 0;
}
