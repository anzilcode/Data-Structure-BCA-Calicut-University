## Algorithm for Singly Linked List Deletion

### 1. Start

### 2. Define a structure `Node`
   - Contains `data` (integer value)
   - Pointer `next` to point to the next node

### 3. Define `main()` function
   - Initialize `head` as `NULL`
   - Clear screen using `clrscr()` (specific to Turbo C)
   - Insert nodes with values `10, 20, 30, 40, 50`
   - Print the original list
   - Ask the user to enter a value to delete
   - Call `deleteNode(head, key)` to delete the node
   - Print the updated list
   - Wait for user input using `getch()`
   - End

### 4. Define function `insertNode(head, data)`
   - Allocate memory for a new node
   - Assign `data` to the new node
   - Set `next` of the new node to `NULL`
   - If the list is empty:
     - Set `head` to the new node
   - Else:
     - Traverse to the last node
     - Update the `next` of the last node to point to the new node

### 5. Define function `deleteNode(head, key)`
   - Initialize `temp` as `head` and `prev` as `NULL`
   - If `head` contains `key`:
     - Update `head` to `head->next`
     - Free the memory of the deleted node
     - Return
   - Traverse the list to find the node containing `key`
   - If `key` is found:
     - Update `prev->next` to `temp->next`
     - Free the memory of the deleted node

### 6. Define function `printList(head)`
   - Traverse through the linked list and print each node's `data`
   - Print `NULL` at the end

#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

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

void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;

    if (temp && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) return;

    prev->next = temp->next;
    free(temp);
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int deleteValue;

    clrscr();

    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);
    insertNode(&head, 50);

    printf("Original List: ");
    printList(head);

    printf("Enter the value to delete: ");
    scanf("%d", &deleteValue);

    deleteNode(&head, deleteValue);

    printf("Updated List: ");
    printList(head);

    getch();
    return 0;
}
