#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
bool isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow, cannot push element.\n");
    } else {
        stack->top++;
        stack->items[stack->top] = value;
    }
}

// Pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop element.\n");
        return -1; // Return a sentinel value or handle underflow in your preferred way
    } else {
        int poppedValue = stack->items[stack->top];
        stack->top--;
        return poppedValue;
    }
}

// Function to add bottom-most element of stack1 to top-most element of stack2
void addElements(struct Stack *stack1, struct Stack *stack2) {
    if (isEmpty(stack1) || isEmpty(stack2)) {
        printf("Cannot perform addition, at least one of the stacks is empty.\n");
        return;
    }
    
    int bottomElement = stack1->items[0];
    int topElement = stack2->items[stack2->top];
    int result = bottomElement + topElement;
    
    printf("Bottom element of stack1: %d\n", bottomElement);
    printf("Top element of stack2: %d\n", topElement);
    printf("Sum: %d\n", result);
}

int main() {
    struct Stack stack1, stack2;
    initialize(&stack1);
    initialize(&stack2);

    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);

    push(&stack2, 5);
    push(&stack2, 15);

    addElements(&stack1, &stack2);

    return 0;
}
