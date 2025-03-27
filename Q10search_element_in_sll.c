## Algorithm for Singly Linked List Search

### 1. Start

### 2. Define a structure `Node`
   - Contains an integer `data`
   - Pointer `next` to the next node

### 3. Define `main()`
   - Initialize `head` as `NULL`
   - **Prompt the user** to enter the number of elements (`n`)
   - Loop `n` times:
     - **Prompt the user** to enter each element
     - Call `insertEnd(head, value)` to insert each value
   - Print the linked list using `display(head)`
   - **Prompt the user** to enter a value to search
   - Call `search(head, key)` and display whether the value is found

### 4. Define `insertEnd(head, value)`
   - Create a new node and assign `value` to it
   - If the list is empty (`head == NULL`), set `head` to the new node
   - Otherwise, traverse to the last node and link the new node

### 5. Define `search(head, key)`
   - Start from `head` and traverse the list
   - If a node’s `data` matches `key`, return `1` (found)
   - If the traversal completes without finding `key`, return `0` (not found)

### 6. Define `printList(head)`
   - Traverse and print each node’s `data`
   - Print `"NULL"` at the end

### 7. End


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertEnd(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

int search(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, i , value, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Linked List: ");
    display(head);

    printf("Enter element to search: ");
    scanf("%d", &key);

    if (search(head, key)) {
        printf("Element %d found in the list.\n", key);
    } else {
        printf("Element %d not found in the list.\n", key);
    }

    return 0;
}
