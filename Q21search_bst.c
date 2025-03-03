## Algorithm: Search in a Binary Search Tree (BST)

### Step 1: Start
### Step 2: Define the `main()` function  
   - Prompt the user to enter the number of elements in the BST.  
   - Insert the elements into the BST.  
   - Prompt the user to enter the element to search.  
   - Call the `searchBST()` function.  
   - Display whether the element is found or not.  
### Step 3: Define the `searchBST(root, key)` function  
   - If the `root` is `NULL`, return `Not Found`.  
   - If `root->data == key`, return `Found`.  
   - If `key < root->data`, recursively call `searchBST(root->left, key)`.  
   - Otherwise, recursively call `searchBST(root->right, key)`.  
### Step 4: Stop


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
