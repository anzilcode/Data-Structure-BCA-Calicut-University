## Algorithm for Binary Search Tree Insertion and Search

### 1. Start

### 2. Define Node Structure
Create a `struct Node` with:
- `int data`
- `struct Node* left`
- `struct Node* right`

### 3. Define `main()`
- Initialize `root` as `NULL`
- Read the number of elements `n`
- Repeat `n` times:
  - Read value
  - Insert it into the BST using `insert()`
- Read a key to search
- Use `search()` to check if the key is found
- If found, print `"key is found"`
- Else, print `"key is not found"`

### 4. Define `createNode(int value)`
- Allocate memory for a new node
- Assign `value` to `data`
- Set `left` and `right` to `NULL`
- Return the new node

### 5. Define `insert(struct Node* root, int value)`
- If `root` is `NULL`, return a new node with `value`
- If `value < root->data`, insert in the left subtree
- If `value > root->data`, insert in the right subtree
- Return the updated root

### 6. Define `search(struct Node* root, int key)`
- If `root` is `NULL` or `root->data == key`, return `root`
- If `key < root->data`, search in the left subtree
- Else, search in the right subtree

### 7. End


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
