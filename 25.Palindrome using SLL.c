#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to insert a new node at the beginning of the linked list
void insert(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to check if the linked list is a palindrome
int isPalindrome(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;
    struct Node *prev_of_slow = head;
    struct Node *mid_node = NULL;
    int is_palindrome = 1;

    if (head != NULL && head->next != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev_of_slow = slow;
            slow = slow->next;
        }

        if (fast != NULL) {
            mid_node = slow;
            slow = slow->next;
        }

        struct Node *second_half = slow;
        prev_of_slow->next = NULL;
        reverse(&second_half);
        is_palindrome = compareLists(head, second_half);
        reverse(&second_half);

        if (mid_node != NULL) {
            prev_of_slow->next = mid_node;
            mid_node->next = second_half;
        } else {
            prev_of_slow->next = second_half;
        }
    }
    return is_palindrome;
}

// Function to reverse a linked list
void reverse(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Function to compare two linked lists
int compareLists(struct Node *list1, struct Node *list2) {
    while (list1 && list2) {
        if (list1->data != list2->data) {
            return 0;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    if (list1 == NULL && list2 == NULL) {
        return 1;
    }
    return 0;
}

// Function to print the linked list
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    printf("Linked List: ");
    printList(head);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}
