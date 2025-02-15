## Algorithm for Singly Linked List Deletion

### 1. Start

### 2. Define a structure `Node`
   - Contains an integer `data`
   - Pointer `next` to the next node

### 3. Define `main()`
   - Initialize `head` as `NULL`
   - Use `insertNode` to add nodes with values `{10, 20, 30, 50, 40}`
   - Print the linked list
   - Display a menu with options:
     1. Delete a node
     2. Print the list
     3. Exit
   - Perform operations based on user input

### 4. Define `insertNode(head, value)`
   - Create a new node and assign `value` to it
   - If the list is empty (`head == NULL`), set `head` to the new node
   - Otherwise, traverse to the last node and link the new node

### 5. Define `deleteNode(head, value)`
   - If `head` contains `value`, update `head` to `head->next` and free memory
   - Otherwise, traverse the list to find `value`
   - If found, update `prev->next` to `temp->next` and free `temp`
   - If the element is **not found**, print a message

### 6. Define `printList(head)`
   - Traverse and print each node’s `data`
   - Print `"NULL"` at the end

### 7. End

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
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

void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head, *prev = NULL;

    if (temp && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("%d deleted successfully from the list\n", value);
        return;
    }

    while (temp && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the list\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted successfully\n");
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;
    clrscr();

    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 50);
    insertNode(&head, 40);

    printList(head);

    while (1) {
        printf("\n1. Delete\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;

            case 2:
                printList(head);
                break;

            case 3:
                return 0;

            default:
                printf("Enter valid input...!\n");
        }
    }

    getch();
    return 0;
}


