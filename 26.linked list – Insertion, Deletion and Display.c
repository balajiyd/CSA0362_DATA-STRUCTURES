#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to insert a new node at the beginning of the linked list
struct Node* insertFront(struct Node *head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to delete a node with a given value from the linked list
struct Node* deleteNode(struct Node *head, int data) {
    if (head == NULL) {
        return head;
    }
    
    if (head->data == data) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    struct Node *current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    
    if (current->next != NULL) {
        struct Node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    
    return head;
}

// Function to display the linked list
void display(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    
    // Insertion at the front
    head = insertFront(head, 3);
    head = insertFront(head, 2);
    head = insertFront(head, 1);
    
    printf("Linked List after insertion: ");
    display(head);
    
    // Deletion
    head = deleteNode(head, 2);
    
    printf("Linked List after deletion: ");
    display(head);

    return 0;
}
