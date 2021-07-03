#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    char stack[];
};

struct Stack* constructor(int size){
    struct Stack* stack = malloc(size * sizeof(struct Stack));
    stack -> size = size;
    stack -> top = -1;
}

int isEmpty(struct Stack *stack){
    if(stack -> top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack *stack){
    if(stack -> top == stack -> size-1)
        return 1;
    else
        return 0;
}

void enqueue(struct Stack *stack, char element){
    if(!isFull(stack))
        stack -> stack[stack -> top++] = element;
    else
        printf("[ERROR] - StackOverflow: Cannot add another element, Stack is full.\n");
}

char dequeue(struct Stack *stack) {
    if (!isEmpty(stack))
        return stack->stack[stack->top--];
    else {
        printf("[ERROR] - StackUnderflow: Cannot remove the top element, Stack is empty.\n");
        return -1;
    }
}

char peek(struct Stack *stack) {
    if (!isEmpty(stack))
        return stack->stack[stack->top--];
    else {
        printf("[ERROR] - StackUnderflow: Cannot get the top element, Stack is empty.\n");
        return -1;
    }
}
