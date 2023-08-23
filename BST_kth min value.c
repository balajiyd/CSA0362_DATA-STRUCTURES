#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        // Duplicate keys are not allowed
        return root;
    }

    return root;
}

// Function to find the kth smallest value in the BST
void kthSmallestUtil(struct Node *root, int k, int *count, int *result) {
    if (root == NULL || *count >= k) {
        return;
    }

    kthSmallestUtil(root->left, k, count, result);

    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }

    kthSmallestUtil(root->right, k, count, result);
}

int kthSmallest(struct Node *root, int k) {
    int count = 0;
    int result = -1;

    kthSmallestUtil(root, k, &count, &result);

    return result;
}

int main() {
    struct Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int k = 3;
    int kthValue = kthSmallest(root, k);
    printf("The %dth smallest value in the BST is: %d\n", k, kthValue);

    return 0;
}

