1. **Start the program**  
2. **Define a structure for a Node**:  
   - Each node contains `data`, a pointer to the `left` child, and a pointer to the `right` child.  
3. **In the main function**:  
   - Initialize `root` as NULL.  
   - Prompt the user for input.  
   - Insert elements into the BST using the insertion function.  
   - Perform Inorder Traversal using the traversal function.  
4. **Create a function to generate a new Node**:  
   - Allocate memory dynamically.  
   - Assign the given value to the node.  
   - Set the left and right pointers to `NULL`.  
5. **Create an Insert Function**:  
   - If the tree is empty, set the new node as the root.  
   - If the value is smaller than the current node, insert it into the left subtree.  
   - If the value is greater, insert it into the right subtree.  
   - Return the root node.  
6. **Define Inorder Traversal Function**:  
   - If the current node is not NULL:  
     - Recursively traverse the left subtree.  
     - Print the node's value.  
     - Recursively traverse the right subtree.  
7. **Call the traversal function from `main()`** to display the BST elements in inorder.  
8. **End the program**.  


  #include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, i, value;
    
    clrscr();
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements to insert in BST: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    
    printf("\nInorder Traversal: ");
    inorder(root);
    
    getch();
    return 0;
}


  
