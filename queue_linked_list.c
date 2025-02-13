## Algorithm for Queue Operations using Linked List

### 1. Start

### 2. Define global structure and functions
   - Define `struct Node` with:
     - `int data`
     - `struct Node* next`
   - Define `struct Queue` with:
     - `struct Node* front`
     - `struct Node* rear`
   - Define functions:
     - `createQueue()`
     - `enqueue(struct Queue* q, int value)`
     - `dequeue(struct Queue* q)`
     - `isEmpty(struct Queue* q)`
     - `display(struct Queue* q)`

### 3. Define `main()`
   - Create an empty queue `struct Queue* q = createQueue()`
   - Display menu with options:
     1. Enqueue
     2. Dequeue
     3. Display
     4. Exit
   - Perform operations based on user choice

### 4. Define `createQueue()`
   - Allocate memory for `struct Queue`
   - Initialize `front = NULL` and `rear = NULL`
   - Return the created queue

### 5. Define `enqueue(struct Queue* q, int value)`
   - Allocate memory for a new node
   - If memory allocation fails, print "Heap overflow"
   - Insert `value` at the rear of the queue
   - Update `rear` pointer

### 6. Define `dequeue(struct Queue* q)`
   - Check if queue is empty (`isEmpty(q)`)
   - If empty, print "Queue underflow"
   - Otherwise, remove and return the front element
   - Update `front` pointer

### 7. Define `display(struct Queue* q)`
   - If queue is empty, print "Queue is empty"
   - Otherwise, traverse the linked list and print elements

### 8. End


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
	q->front = q->rear = newNode;
    } else {
	q->rear->next = newNode;
	q->rear = newNode;
    }
    printf("%d enqueued.\n", value);
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
	printf("Queue underflow\n");
	return -1;
    }
    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
	q->rear = NULL;

    free(temp);
    return value;
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
	printf("Queue is empty\n");
	return;
    }
    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp) {
	printf("%d -> ", temp->data);
	temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue* q = createQueue();
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
		enqueue(q, value);
		break;
	    case 2:
		value = dequeue(q);
		if (value != -1)
		    printf("%d dequeued.\n", value);
		break;
	    case 3:
		display(q);
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
