#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to get the height of a node
int getHeight(struct Node *node) {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// Function to get the balance factor of a node
int getBalance(struct Node *node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}

// Function to rotate a subtree to the left
struct Node* rotateLeft(struct Node *y) {
    struct Node *x = y->right;
    struct Node *T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

// Function to rotate a subtree to the right
struct Node* rotateRight(struct Node *x) {
    struct Node *y = x->left;
    struct Node *T2 = y->right;

    y->right = x;
    x->left = T2;

    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

// Function to insert a new node into the AVL tree
struct Node* insert(struct Node *node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        // Duplicate keys are not allowed
        return node;
    }

    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    int balance = getBalance(node);

    // Left Heavy
    if (balance > 1 && data < node->left->data) {
        return rotateRight(node);
    }

    // Right Heavy
    if (balance < -1 && data > node->right->data) {
        return rotateLeft(node);
    }

    // Left-Right Heavy
    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right-Left Heavy
    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Function to print the AVL tree in-order
void inorder(struct Node *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main() {
    struct Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("In-order traversal of AVL tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
