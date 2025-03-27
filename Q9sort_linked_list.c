# Sorting a Singly Linked List

## Algorithm

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
   - Create a new node `newNode`  
   - Assign `data` to `newNode`  
   - If the linked list is empty, set `head_ref` to `newNode`  
   - Otherwise, traverse to the end and insert `newNode`  

### 5. Define `bubbleSort(head)`  
   - If the list is empty, return  
   - Initialize a pointer `last = NULL`  
   - Repeat until no swaps are needed:  
     - Set `swapped = 0`  
     - Start from `head`  
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
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
	*head = newNode;
	return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void print(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void sort(struct Node* head) {
    struct Node *i, *j;
    int temp;
    if (head == NULL) return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void main() {
    struct Node* head = NULL;
    int n, data, i;

    clrscr();  

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
	printf("Enter element %d (one by one): ", i + 1);
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("\nOriginal list:\n");
    print(head);

    sort(head);

    printf("\nSorted list:\n");
    print(head);

    getch();  
}
