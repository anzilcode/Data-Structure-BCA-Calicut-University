# Algorithm for Queue Operations using Linked List

## 1. Start

## 2. Define Global Structure and Functions
- **Define `struct Node`** with:
  - `int data` → To store the value
  - `struct Node* next` → Pointer to the next node
- **Define global pointers**:
  - `struct Node* front = NULL`
  - `struct Node* rear = NULL`
- **Define functions**:
  - `void enqueue(int value)`
  - `int dequeue()`
  - `void display()`

---

## 3. Define `main()`
1. Call `clrscr()` to clear the screen (Turbo C requirement).
2. Declare variables `choice` and `value`.
3. Start an infinite loop:
   - Display menu:
     ```
     --- Queue Menu ---
     1. Enqueue
     2. Dequeue
     3. Display Queue
     4. Exit
     ```
   - Prompt user to enter a choice.
   - Read user input into `choice`.
   - Use `switch-case` to perform operations:
     - **Case 1**:  
       - Prompt user to enter value.
       - Read input into `value`.
       - Call `enqueue(value)`.
     - **Case 2**:  
       - Call `dequeue()` and store the returned value.
       - If valid, print the dequeued value.
     - **Case 3**:  
       - Call `display()` to show the queue.
     - **Case 4**:  
       - Print `"Exiting program..."`.
       - Call `getch()` and exit.
     - **Default**:  
       - Print `"Invalid choice, try again"`.

---

## 4. Define `enqueue(int value)`
1. Allocate memory for a new node.
2. If memory allocation fails, print `"Memory allocation failed"` and return.
3. Set:
   ```c
   newNode->data = value;
   newNode->next = NULL;
   ```
4. If the queue is empty (`rear == NULL`):
   - Set `front = rear = newNode`.
5. Else:
   - Set `rear->next = newNode`.
   - Update `rear = newNode`.
6. Print `"Value enqueued"`.
---
## 5. Define `dequeue()`
1. If `front == NULL` (Queue is empty), print `"Queue underflow"` and return `-1`.
2. Store the front node in a temporary pointer `temp = front`.
3. Store `temp->data` in `value`.
4. Update `front = front->next`.
5. If `front == NULL`, set `rear = NULL`.
6. Free the memory of `temp`.
7. Return `value`.
---
## 6. Define `display()`
1. If `front == NULL`, print `"Queue is empty"` and return.
2. Set a temporary pointer `temp = front`.
3. Print `"Queue: "`.
4. Traverse the linked list:
   ```c
   while (temp) {
       printf("%d -> ", temp->data);
       temp = temp->next;
   }
   ```
5. Print `"NULL"`.
## 7. End



#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n%d enqueued.\n", value);
}

int dequeue() {
    struct Node* temp = front;
    int value;
    if (front == NULL) {
	printf("\nQueue underflow!\n");
	return -1;
    }
    value = temp->data;
    front = front->next;

    if (front == NULL)
	rear = NULL;

    free(temp);
    return value;
}

void display() {
    struct Node* temp = front;
    if (temp == NULL) {
	printf("\nQueue is empty!\n");
	return;
    }

    printf("\nQueue: ");
    while (temp) {
	printf("%d -> ", temp->data);
	temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;
    clrscr();

    while (1) {
	printf("\n--- Queue Menu ---\n");
	printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter value to enqueue: ");
		scanf("%d", &value);
		enqueue(value);
		break;
	    case 2:
		value = dequeue();
		if (value != -1)
		    printf("\n%d dequeued.\n", value);
		break;
	    case 3:
		display();
		break;
	    case 4:
		printf("\nExiting program...\n");
		getch();
		return 0;
	    default:
		printf("\nInvalid choice, try again.\n");
	}
    }

    getch();
    return 0;
}
