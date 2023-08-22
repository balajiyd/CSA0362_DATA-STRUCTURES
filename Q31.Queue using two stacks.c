#include <stdio.h>
#include <stdlib.h>

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
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack *stack) {
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

struct Queue {
    struct Stack *stack1;
    struct Stack *stack2;
};

// Create a new queue
struct Queue* createQueue() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = (struct Stack*)malloc(sizeof(struct Stack));
    queue->stack2 = (struct Stack*)malloc(sizeof(struct Stack));
    initialize(queue->stack1);
    initialize(queue->stack2);
    return queue;
}

// Enqueue an element to the queue
void enqueue(struct Queue *queue, int item) {
    if (isFull(queue->stack1)) {
        printf("Queue is full, cannot enqueue.\n");
        return;
    }

    // Transfer all elements from stack1 to stack2
    while (!isEmpty(queue->stack1)) {
        push(queue->stack2, pop(queue->stack1));
    }

    // Push the new element to stack1
    push(queue->stack1, item);

    // Transfer all elements back to stack1 from stack2
    while (!isEmpty(queue->stack2)) {
        push(queue->stack1, pop(queue->stack2));
    }
}

// Dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue->stack1)) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1; // Return a sentinel value or handle empty queue in your preferred way
    }

    return pop(queue->stack1);
}

int main() {
    struct Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    return 0;
}
