

## Algorithm for Queue Operations using Linked List

### 1. Start

### 2. Define Node Structure
- Create a structure `Node` with:
  - `int data` to hold the value
  - `struct Node* next` to point to the next node

### 3. Initialize Pointers
- Declare and initialize two pointers:
  - `front = NULL`
  - `rear = NULL`

### 4. Display Menu in Loop
- Use a loop to display the following options to the user:
  1. Enqueue
  2. Dequeue
  3. Display
  4. Exit
- Perform the corresponding operation based on user input

### 5. Enqueue Operation
- Create a new node using dynamic memory allocation
- If memory allocation fails, print "Memory allocation failed"
- Set `newNode->data = value`, and `newNode->next = NULL`
- If `rear == NULL` (queue is empty):
  - Set both `front` and `rear` to `newNode`
- Else:
  - Set `rear->next = newNode`
  - Update `rear = newNode`
- Print the enqueued value

### 6. Dequeue Operation
- If `front == NULL`, print "Queue underflow"
- Else:
  - Store the value from `front->data`
  - Move `front` to `front->next`
  - If `front == NULL`, also set `rear = NULL`
  - Free the dequeued node
  - Print the dequeued value

### 7. Display Operation
- If `front == NULL`, print "Queue is empty"
- Else:
  - Traverse from `front` to `rear`, printing each node's data

### 8. Exit
- If the user chooses to exit, terminate the loop and end the program

### 9. End



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
