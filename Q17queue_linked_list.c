## Algorithm for Queue Operations using Linked List


1. Start

2. Define global structure and functions
   - Define `struct Node` with:
     - `int data`
     - `struct Node* next`
   - Define global pointers:
     - `struct Node* front = NULL`
     - `struct Node* rear = NULL`
   - Define functions:
     - `enqueue(int value)`
     - `dequeue()`
     - `isEmpty()`
     - `display()`

3. Define `main()`
   - Call `clrscr()` to clear the screen
   - Declare variables `choice` and `value`
   - Start an infinite loop:
     - Display menu:
       1. Enqueue
       2. Dequeue
       3. Display
       4. Exit
     - Prompt user to enter a choice
     - Read user input into `choice`
     - Use `switch-case` to perform operations:
       - Case 1:  
         - Prompt user to enter value  
         - Read input into `value`  
         - Call `enqueue(value)`
       - Case 2:  
         - Call `dequeue()` and store returned value  
         - If valid, print the dequeued value  
       - Case 3:  
         - Call `display()` to show the queue  
       - Case 4:  
         - Print `"Exiting..."`  
         - Call `exit(0)`  
       - Default:  
         - Print `"Invalid choice, try again"`

4. Define `enqueue(int value)`
   - Allocate memory for a new node
   - If memory allocation fails, print `"Heap overflow"`
   - Set `data = value`, `next = NULL`
   - If queue is empty (`rear == NULL`), update `front` and `rear` to point to new node
   - Else, link the new node to `rear->next` and update `rear`

5. Define `dequeue()`
   - Check if queue is empty (`isEmpty()`)
   - If empty, print `"Queue underflow"`
   - Otherwise, remove and return the front element
   - Update `front` pointer
   - If `front` becomes `NULL`, set `rear = NULL`

6. Define `display()`
   - If queue is empty, print `"Queue is empty"`
   - Otherwise, traverse the linked list and print elements

7. End


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued.\n", value);
}

int isEmpty() {
    return front == NULL;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }
    struct Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return value;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
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
                    printf("%d dequeued.\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                getch();
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    getch();
    return 0;
}
