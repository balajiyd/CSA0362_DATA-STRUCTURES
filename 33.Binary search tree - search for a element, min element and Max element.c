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

// Function to search for an element in the BST
struct Node* search(struct Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}

// Function to find the minimum element in the BST
struct Node* findMin(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->left == NULL) {
        return root;
    }

    return findMin(root->left);
}

// Function to find the maximum element in the BST
struct Node* findMax(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->right == NULL) {
        return root;
    }

    return findMax(root->right);
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

    int searchKey = 40;
    struct Node *searchResult = search(root, searchKey);
    if (searchResult) {
        printf("Element %d found in the BST.\n", searchKey);
    } else {
        printf("Element %d not found in the BST.\n", searchKey);
    }

    struct Node *minNode = findMin(root);
    if (minNode) {
        printf("Minimum element in the BST: %d\n", minNode->data);
    }

    struct Node *maxNode = findMax(root);
    if (maxNode) {
        printf("Maximum element in the BST: %d\n", maxNode->data);
    }

    return 0;
}
