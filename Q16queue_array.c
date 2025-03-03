## Algorithm for Queue Operations using Array

### 1. Start

### 2. Define global variables
   - `queue[100]`, `front = -1`, `rear = -1`, `n` (queue size), `x` (element), `ch` (choice), and `i` (loop index)

### 3. Define `main()`
   - Initialize `front = rear = -1`
   - Take user input for `n` (queue size)
   - Display menu with options:
     1. Enqueue
     2. Dequeue
     3. Display
     4. Exit
   - Perform operations based on user choice

### 4. Define `enqueue()`
   - Check if `rear == n - 1` (Queue Overflow)
   - If not, insert `x` into `queue[rear]` and update `rear`
   - If inserting the first element, set `front = 0`

### 5. Define `dequeue()`
   - Check if `front == -1 || front > rear` (Queue Underflow)
   - If not, remove and print `queue[front]`, then update `front`
   - If the queue becomes empty, reset `front` and `rear` to `-1`

### 6. Define `display()`
   - If `front == -1 || front > rear`, print "Queue is empty"
   - Otherwise, print all elements from `front` to `rear`

### 7. End


#include <stdio.h>
#include <conio.h>

int queue[100], ch, n, front, rear, x, i;

void enqueue();
void dequeue();
void display();

void main() {
    clrscr();
    front = rear = -1;

    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    while (1) {
        printf("\nQueue Operation\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter the Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: enqueue();
                    break;
            case 2: dequeue();
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

void enqueue() {
    if (rear == n - 1) {
        printf("Queue Overflow\n");
    } else {
        printf("Enter the value to be enqueued: ");
        scanf("%d", &x);
        if (front == -1) front = 0;
        rear++;
        queue[rear] = x;
        printf("%d enqueued into the queue\n", x);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("The dequeued element is: %d\n", queue[front]);
        front++;
        if (front > rear) front = rear = -1;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
