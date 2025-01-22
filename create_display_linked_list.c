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
