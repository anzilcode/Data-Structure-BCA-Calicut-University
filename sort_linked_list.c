## Algorithm for Sorting a Singly Linked List 

### 1. Start

### 2. Define a structure `Node`
   - Contains `data`
   - Pointer `next` to the next node

### 3. Define `main()`
   - Initialize `head` as `NULL`
   - Insert elements into the linked list using `push`
   - Print the linked list before sorting
   - Call `bubbleSort(head)`
   - Print the sorted linked list

### 4. Define `push(head_ref, new_data)`
   - Create a new node
   - Assign `data` to the new node
   - Set `next` of the new node to `head_ref`
   - Update `head_ref` to point to the new node

### 5. Define `bubbleSort(start)`
   - Repeat until no swaps are needed:
     - Traverse the linked list
     - Swap adjacent nodes if they are out of order using `swap(a, b)`

### 6. Define `swap(a, b)`
   - Swap the `data` values of nodes `a` and `b`

### 7. Define `printList(node)`
   - Traverse the linked list and print each node’s `data`

### 8. End


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

void swap(struct Node *a, struct Node *b);

void bubbleSort(struct Node *start) {
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    if (start == NULL) {
	return;
    }

    do {
	swapped = 0;
	ptr1 = start;

	while (ptr1->next != lptr) {
	    if (ptr1->data > ptr1->next->data) {
		swap(ptr1, ptr1->next);
		swapped = 1;
	    }
	    ptr1 = ptr1->next;
	}
	lptr = ptr1;
    }
    while (swapped);
}

void swap(struct Node *a, struct Node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node) {
    while (node != NULL) {
	printf(" %d ", node->data);
	node = node->next;
    }
}

int main() {
    struct Node* head = NULL;

    clrscr();

    push(&head, 9);
    push(&head, 4);
    push(&head, 5);
    push(&head, 2);
    push(&head, 5);
    push(&head, 7);
    push(&head, 1);

    printf("Linked list before sorting: \n");
    printList(head);

    bubbleSort(head);

    printf("\nLinked list after sorting: \n");
    printList(head);

    getch();
    return 0;
}
