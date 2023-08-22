#include<stdio.h>
#include <stdlib.h>

struct Node {n
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to find the intersection of two linked lists
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int count1 = 0, count2 = 0;
    struct Node *curr1 = head1, *curr2 = head2;

    // Count the number of nodes in each list
    while (curr1) {
        count1++;
        curr1 = curr1->next;
    }
    while (curr2) {
        count2++;
        curr2 = curr2->next;
    }

    // Make the pointers of the larger list to point to the same number of nodes as the smaller list
    curr1 = head1;
    curr2 = head2;
    if (count1 > count2) {
        int i;
        for (i = 0; i < count1 - count2; i++)
            curr1 = curr1->next;
    } else {
        int i;
        for (i = 0; i < count2 - count1; i++)
            curr2 = curr2->next;
    }

    // Move both pointers together until they meet at the intersection
    while (curr1 && curr2) {
        if (curr1 == curr2)
            return curr1;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    // If there is no intersection, return NULL
    return NULL;
}

// Function to display a linked list
void displayList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


int main() {
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);

    struct Node* head2 = newNode(5);
    head2->next = head1->next->next;
    printf("Original lists:\n");
    displayList(head1);
    displayList(head2);

    struct Node* intersection1 = getIntersection(head1, head2);
    if (intersection1)
        printf("Intersection found at %d.\n", intersection1->data);
    else
        printf("Intersection not found.\n");
        
    struct Node* head3 = newNode(1);
    head3->next = newNode(2);
    head3->next->next = newNode(3);
    head3->next->next->next = newNode(4);

    struct Node* head4 = newNode(5);
    head4->next = newNode(3);
    head4->next->next = newNode(4);
    printf("\nOriginal lists:\n");
    displayList(head3);
    displayList(head4);

    struct Node* intersection2 = getIntersection(head3, head4);
    if (intersection2)
        printf("Intersection found at %d.\n", intersection2->data);
    else
        printf("Intersection not found.\n");           
        
    return 0;
}
