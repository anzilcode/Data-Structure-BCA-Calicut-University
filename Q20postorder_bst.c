# Algorithm for Postorder Traversal of a BST

## Step 1: Define the Node Structure
- Create a structure `Node` with:
  - An integer `data`
  - Two pointers: `left` and `right`

## Step 2: Main Function
- Prompt the user to enter the number of nodes.
- Take input for node values and insert them into the BST.
- Display a message indicating the start of postorder traversal.
- Call the postorder traversal function.

## Step 3: Function to Create a New Node
- Allocate memory for a new node.
- Assign the given value to `data`.
- Set `left` and `right` pointers to NULL.

## Step 4: Insert Function
- If the root is NULL, create a new node and return it.
- If the value is smaller than the root, insert it into the left subtree.
- If the value is larger, insert it into the right subtree.

## Step 5: Postorder Traversal Function
- Display a message before starting traversal.
- Recursively call postorder traversal on the left subtree.
- Recursively call postorder traversal on the right subtree.
- Print the root node's data.


  #include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    
    return root;
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void main() {
    struct Node* root = NULL;
    int n, i, val;
    
    clrscr();
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the node values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    
    printf("Postorder Traversal: ");
    postorder(root);
    
    getch();
}

