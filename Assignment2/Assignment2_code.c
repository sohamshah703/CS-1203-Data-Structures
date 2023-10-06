#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct TreeNode *left, *right;
};
typedef struct Node TreeNode;

// Helper function to create a new BST node
TreeNode* createNode(int val) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert an element into the BST
TreeNode* insert(TreeNode *root, int val) {
    TreeNode *temp, *parent;
    int direction;

    if (root == NULL) { // Base case when of no root node or an empty BST
        root = createNode(val); 
        return root;
    }

    temp = root;

    while (temp != NULL) { // Checking if the value already exists in the BST
        if (val < temp->val) { // For inserting node in the left subtree if it is smaller than root
            parent = temp;
            temp = temp->left;
            direction = 0; 
        } else { // For inserting node in the right subtree if it is greater than root
            parent = temp;
            temp = temp->right;
            direction = 1; 
        }
    }

    temp = createNode(val);

    if (direction == 0) { // Traversing towards the left.
        parent->left = temp;
    } else {  // Traversing towards the right.
        parent->right = temp;
    }

    return root;

}

// Function that performs the required inorder traversal of the BST without recursion and using stacks
void inorderTrav(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    TreeNode *stack[1000]; // This stack that is created stores the node pointers
    int top = -1; // Initialising the stack

    TreeNode *current = root;
    
    // Iterative manner for traversing through the BST
    while (current != NULL || top != -1) { //Checking if all nodes under the present subtree have been traversed through. 
        // Traverse down the left subtree and push nodes onto the stack
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        // Reached the leftmost element in the current subtree. 
        // Therefore, we pop it from the stack and print its value
        current = stack[top--];
        printf("%d ", current->val);

        // Moving to the right subtree of the current node.
        current = current->right;
    }
}


int main() {
    TreeNode *root = NULL; // Initialize the BST as empty

    int choice;
    int element;

    while (1) { // Presenting a menu
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert an element\n"); // Allowing user to enter elements and make the BST
        printf("2. Inorder Traversal\n"); // Allowing user to print the inorder or ascending values of the BST
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                root = insert(root, element); // Calling the insert function
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorderTrav(root); // Calling the inorder function
                printf("\n");
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
