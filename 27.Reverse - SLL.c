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

// Function to reverse the linked list
struct Node* reverse(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; // New head of the reversed linked list
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

    printf("Original Linked List: ");
    display(head);

    // Reverse the linked list
    head = reverse(head);

    printf("Reversed Linked List: ");
    display(head);

    return 0;
}
