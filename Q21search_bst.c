### **Algorithm: Search an Element in BST**

1. **Start**
2. **Main Function**
   - Clear the screen.
   - Create a BST by inserting elements.
   - Prompt the user to enter the element to search.
   - Call the search function.
   - Display if the element is found or not.
   - Wait for user input before exiting.

3. **Search Function**
   - If the tree is empty, return NULL.
   - If the element matches the root, return the root node.
   - If the element is smaller than the root, search in the left subtree.
   - If the element is greater than the root, search in the right subtree.

4. **Stop**


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

void main() {
    struct Node* root = NULL;
    int n, i, value, key;

    clrscr();
    printf("Enter the number of elements to insert in BST: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    if (search(root, key) != NULL)
        printf("%d is found in the BST.\n", key);
    else
        printf("%d is not found in the BST.\n", key);

    getch();
}
