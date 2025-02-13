## Algorithm for Singly Linked List Deletion

### 1. Start

### 2. Define a structure `Node`
   - Contains `data`
   - Pointer `next` to the next node

### 3. Define `main()`
   - Initialize `head` as `NULL`
   - Use `insertNode` to add nodes
   - Display a menu with options:
     1. Delete a node
     2. Print the list
     3. Exit
   - Perform operations based on user input

### 4. Define `insertNode(head, data)`
   - Create a new node
   - Assign `data` to the new node
   - If the list is empty, set `head` to the new node
   - Otherwise, traverse to the last node and link the new node

### 5. Define `deleteNode(head, key)`
   - If `head` contains `key`, update `head` to `head->next` and free memory
   - Otherwise, traverse the list to find `key`
   - If found, update `prev->next` and free memory

### 6. Define `printList(head)`
   - Traverse and print each node’s `data`
   - Print `NULL` at the end

### 7. End

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
        printf("\n%d deleted successfully.\n", key);
        return;
    }

    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("\nElement %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("\n%d deleted successfully.\n", key);
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
    int choice, deleteValue;

    clrscr();

    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);
    insertNode(&head, 50);

    while (1) {
        printf("\nMenu:");
        printf("\n1. Delete a node");
        printf("\n2. Print list");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to delete: ");
                fflush(stdin);
                scanf("%d", &deleteValue);
                deleteNode(&head, deleteValue);
                break;

            case 2:
                printList(head);
                break;

            case 3:
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    getch();
    return 0;
}
