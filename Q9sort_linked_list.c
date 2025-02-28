## Sorting a Singly Linked List

### Algorithm

### 1. Start

### 2. Define a structure `Node`
   - Contains an integer `data`
   - Pointer `next` to the next node

### 3. Define `main()`
   - Initialize `head` as `NULL`
   - Insert elements into the linked list using `insertNode()`
   - Print the linked list before sorting
   - Call `bubbleSort(head)`
   - Print the sorted linked list

### 4. Define `insertNode(head_ref, data)`
   - Create a new node
   - Assign `data` to the new node
   - If the linked list is empty, set `head_ref` to the new node
   - Otherwise, traverse to the end and insert the new node

### 5. Define `bubbleSort(head)`
   - If the list is empty, return
   - Initialize a pointer `last = NULL`
   - Repeat until no swaps are needed:
     - Set `swapped = 0`
     - Start from the `head`
     - Traverse the linked list until reaching the last sorted node:
       - If two adjacent nodes are out of order, swap their data using `swap(a, b)`
       - Set `swapped = 1`
     - Update `last` to the last checked node

### 6. Define `swap(a, b)`
   - Swap the data values of nodes `a` and `b`

### 7. Define `printList(head)`
   - Traverse the linked list and print each node’s `data`

### 8. End



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

void swap(struct Node *a, struct Node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(struct Node *head) {
    if (head == NULL) {
        return;
    }

    int swapped;
    struct Node *temp;
    struct Node *last = NULL;

    do {
        swapped = 0;
        temp = head;

        while (temp->next != last) {
            if (temp->data > temp->next->data) {
                swap(temp, temp->next);
                swapped = 1;
            }
            temp = temp->next;
        }
        last = temp;
    } while (swapped);
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    printf("\nCurrent List: ");
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    clrscr();

    insertNode(&head, 9);
    insertNode(&head, 4);
    insertNode(&head, 5);
    insertNode(&head, 2);
    insertNode(&head, 5);
    insertNode(&head, 7);
    insertNode(&head, 1);

    printf("Linked list before sorting: \n");
    printList(head);

    bubbleSort(head);

    printf("\nLinked list after sorting: \n");
    printList(head);

    getch();
    return 0;
}

