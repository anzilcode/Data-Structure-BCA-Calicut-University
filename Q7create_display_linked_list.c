# Algorithm

## 1. Start  
## 2. Declare Structures  
   - Define a structure `Node` containing:  
     - `data` (integer)  
     - `next` (pointer to next node)  

## 3. main() Function  
   1. Declare variables:  
      - `head` (pointer to store the head of the linked list)  
      - `n` (number of nodes)  
      - `value` (to store user input)  
      - `i` (loop counter)  

   2. Clear the screen using `clrscr()` (for Turbo C users)  

   3. Prompt the user for the number of nodes and read `n`  

   4. Loop from `0` to `n-1`:  
      - Ask for node value  
      - If `head` is `NULL`, create the first node using `createNode(value)`  
      - Otherwise, insert the node at the end using `insertNode(head, value)`

   5. Display the linked list using `displayList(head)`

   6. Wait for user input using `getch()`

   7. End  

## 4. createNode(value) Function  
   - Allocate memory for a new node  
   - Assign `data = value`  
   - Set `next = NULL`  
   - Return the newly created node  

## 5. insertNode(head, value) Function  
   - Create a new node using `createNode(value)`  
   - Traverse to the last node of the linked list  
   - Set `lastNode->next = newNode`  

## 6. displayList(head) Function  
   - If `head` is `NULL`, print "List is empty" and return  
   - Traverse the list and print `data` of each node  
   - Print `NULL` at the end 


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, i;

    clrscr();  

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &value);

        if (head == NULL) {
            head = createNode(value);
        } else {
            insertNode(head, value);
        }
    }

    printf("The linked list is: ");
    displayList(head);

    getch();  
    return 0;
}
