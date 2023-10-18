#include <stdio.h>  
#include <stdlib.h>  

struct Node  
{  
    int key;  
    struct Node *left;  
    struct Node *right;  
    int height;  
};  

// Function to calculate the height of a node
int getHeight(struct Node *n) {
    if (n == NULL)  
        return 0;  
    return n->height;  
}  

// Function to create a new node
struct Node *createNode(int key) {
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));  
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;  
    return node;  
}  

// Function that calculates the max of two integers
int max(int a, int b) {  
    return (a > b) ? a : b;  
}  

// Function that calculates the balance factor of a node
int getBalanceFactor(struct Node *n) {  
    if (n == NULL) {  
        return 0;  
    }  
    return getHeight(n->left) - getHeight(n->right);  
}  

// Function to perform a right rotation
struct Node* rightRotate(struct Node* y) {
    
    struct Node* x = y->left; // Store the left child of y
    struct Node* T2 = x->right; // Store the right subtree of x

    // Performing the rotation
    x->right = y;
    y->left = T2;

    // Updating the heights of the rotated nodes
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    // Returning the new root after rotation
    return x;
}

// Function to perform a left rotation
struct Node* leftRotate(struct Node* x) {
    
    struct Node* y = x->right; // Store the right child of x    
    struct Node* T2 = y->left; // Store the left subtree of y

    // Performing the rotation
    y->left = x;
    x->right = T2;

    // Updating heights of the rotated nodes
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    // Returning the new root after rotation
    return y;
}

// Function to insert a new node
struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return createNode(key);

    // Performing standard BST insertion
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Updating the height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Getting the balance factor to check for unbalanced nodes
    int bf = getBalanceFactor(node);

    // Performing rotations based on balance factor and key
    // Left Left Case
    if (bf > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (bf < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (bf > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (bf < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // If no rotation is needed, return the node as it is
    return node;
}


// Function to find the node with the minimum key in the tree
struct Node *findMin(struct Node *node) {
    struct Node *current = node;
    // Traverse the tree to the leftmost node to find the minimum key
    while (current->left != NULL)
        current = current->left;
    // Return the node with the minimum key
    return current;
}

// Function to perform the delete routine
struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with the key to be deleted is found
        if (root->left == NULL) {
            // Storing the right subtree and free the current node
            struct Node *temp = root->right;
            free(root);
            // Returning the right subtree
            return temp;
        } 
        
        else if (root->right == NULL) {
            // Storing the left subtree and free the current node
            struct Node *temp = root->left;
            free(root);
            // Returning the left subtree
            return temp;
        }
        
        // If the node has two children, replace it with the minimum node from the right subtree
        struct Node *temp = findMin(root->right);
        root->key = temp->key;
        
        // Deleting the minimum node from the right subtree
        root->right = deleteNode(root->right, temp->key);
    }
    
    // Updating the height of the current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);
   
    if (bf > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);
    if (bf > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    if (bf < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);
    if (bf < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // Returning the updated root node
    return root;
}


// Pre-order traversal of tree
void preOrder(struct Node *root) {  
    if (root != NULL) {  
        printf("%d ", root->key);  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  

// In-order traversal of tree
void inOrder(struct Node *root) {  
    if (root != NULL) {  
        inOrder(root->left);  
        printf("%d ", root->key);  
        inOrder(root->right);  
    }  
}  

// Function to display the tree structure
void displayTree(struct Node* root, int space) {
    int i;

    if (root == NULL)
        return;

    space += 10;

    displayTree(root->right, space);

    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    displayTree(root->left, space);
}


int main() {  
    struct Node * root = NULL;  
    
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 60);  
    root = insert(root, 30);  
    root = insert(root, 70);  
    root = insert(root, 80);  
    root = insert(root, 90);  
    
    printf("Pre-order Traversal: ");
    preOrder(root);  
    printf("\n");

    printf("In-order Traversal: ");
    inOrder(root);  
    printf("\n");

    printf("Displaying AVL Tree:\n");
    displayTree(root, 10);

    // Deleting nodes (e.g., delete node with key 50)
    int keytoDelete = 50;
    root = deleteNode(root, keytoDelete);
    printf("Deleted node with key %d\n", keytoDelete);

    printf("In-order Traversal after Deletion: ");
    inOrder(root);
    printf("\n");

    printf("Displaying AVL Tree after Deletion:\n");
    displayTree(root, 10);

    return 0;  
}
