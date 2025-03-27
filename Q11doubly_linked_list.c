# Algorithm for Creating and Displaying a Doubly Linked List in Forward and Backward Direction

## 1. Start  

## 2. Define a structure `Node`  
   - Contains an integer `data`  
   - A pointer `next` pointing to the next node  
   - A pointer `prev` pointing to the previous node  

## 3. Define the `main()` function  
   - Declare `head` as `NULL` (represents an empty list)  
   - Prompt the user to enter the number of elements  
   - Loop through user input and insert each element using `insertEnd()`  
   - Call `displayForward(head)` to show elements in forward order  
   - Call `displayBackward(head)` to show elements in backward order  
   - Exit the program  

## 4. Define `insertEnd(head, data)`  
   - Create a new node and assign `data` to it  
   - If the list is empty (`head == NULL`):  
     - Set `head` to the new node  
     - Set `prev` as `NULL`  
   - Otherwise:  
     - Traverse to the last node  
     - Link the new node at the end and update `prev`  

## 5. Define `displayForward(head)`  
   - Traverse the list from `head`  
   - Print each node’s `data` until the end  

## 6. Define `displayBackward(head)`  
   - Traverse to the last node  
   - Print each node’s `data` moving backward until `NULL` is reached  

## 7. End  


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertEnd(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
	newNode->prev = NULL;
	*head = newNode;
	return;
    }

    while (temp->next != NULL) {
	temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void displayForward(struct Node* head) {
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
	printf("%d -> ", temp->data);
	temp = temp->next;
    }
    printf("NULL\n");
}

void displayBackward(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) return;
	
    while (temp->next != NULL) {
	temp = temp->next;
    }

    printf("Backward: ");
    while (temp != NULL) {
	printf("%d -> ", temp->data);
	temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int i , n , value;
    clrscr();

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
	scanf("%d", &value);
	insertEnd(&head, value);
    }

    displayForward(head);
    displayBackward(head);

    getch();
    return 0;
}
