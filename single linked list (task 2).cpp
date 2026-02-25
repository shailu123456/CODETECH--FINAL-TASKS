#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Insert at end
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete a node by value
struct Node* deleteNode(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head node itself holds the value
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for the value
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found!\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

// Traverse and display
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            head = insertAtBeginning(head, value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            head = insertAtEnd(head, value);
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            head = deleteNode(head, value);
            break;

        case 4:
            display(head);
            break;

        case 5:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

