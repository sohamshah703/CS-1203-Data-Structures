#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Define a structure for the Queue
typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Function to initialize an empty Queue
void initializeQueue(Queue *q) {
    q->front = q->rear = NULL;
}

// Function to check if the Queue is empty
int isEmpty(Queue *q) {
    return q->front == NULL;
}

// Function to insert an element into the Queue
void insert(Queue *q, int elm) {
    // Create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = elm;
    newNode->next = NULL;
    
    if (isEmpty(q)) {
        // If the Queue is empty, set both front and rear to the new node
        q->front = q->rear = newNode;
    } else {
        // Otherwise, update the rear node's next pointer and set rear to the new node
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to delete an element from the Queue
int delete(Queue *q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    
    // Get the data from the front node
    int data = q->front->data;
    
    // Move the front to the next node
    Node *temp = q->front;
    q->front = q->front->next;
    
    // Free the memory of the old front node
    free(temp);
    
    return data;
}

// Function to print the elements of the Queue
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue: ");
    Node *current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initializeQueue(&q);
    int choice, element;

    while (1) {
        printf("1. Insert\n2. Delete\n3. Print Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(&q, element);
                break;
            case 2:
                if (!isEmpty(&q)) {
                    element = delete(&q);
                    printf("Deleted element: %d\n", element);
                }
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
