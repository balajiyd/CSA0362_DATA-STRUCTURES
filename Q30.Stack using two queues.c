#include <stdio.h>
#include <stdlib.h>

// Queue structure
struct Queue {
    int *array;
    int front, rear;
    unsigned int capacity;
};

// Create a new queue
struct Queue* createQueue(unsigned int capacity) {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->array = (int*)malloc(capacity * sizeof(int));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// Check if a queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

// Check if a queue is full
int isFull(struct Queue *queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// Enqueue an element to the queue
void enqueue(struct Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
}

// Dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1; // Return a sentinel value or handle empty queue in your preferred way
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % queue->capacity;
    return item;
}

// Stack structure using two queues
struct Stack {
    struct Queue *q1, *q2;
};

// Create a new stack
struct Stack* createStack(unsigned int capacity) {
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->q1 = createQueue(capacity);
    stack->q2 = createQueue(capacity);
    return stack;
}

// Push an element onto the stack
void push(struct Stack *stack, int item) {
    if (isFull(stack->q1)) {
        printf("Stack is full, cannot push.\n");
        return;
    }

    // Enqueue the new element to q1
    enqueue(stack->q1, item);
}

// Pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack->q1)) {
        printf("Stack is empty, cannot pop.\n");
        return -1; // Return a sentinel value or handle empty stack in your preferred way
    }

    // Move elements from q1 to q2 except the last one
    while (!isEmpty(stack->q1)) {
        if (queue->q1->front == queue->q1->rear)
            break;
        enqueue(stack->q2, dequeue(stack->q1));
    }

    // Pop the last element from q1
    int poppedItem = dequeue(stack->q1);

    // Swap q1 and q2
    struct Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;

    return poppedItem;
}

int main() {
    struct Stack *stack = createStack(10);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    return 0;
}
