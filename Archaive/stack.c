#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    char array[];
};

struct Stack* constructor(int size){
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack -> array[size];
    stack -> size = size;
    stack -> top = -1;
    return stack;
}

int isEmpty(struct Stack *stack){
    if(stack -> top == -1)
        return 1;
    else {
        printf("Is Empty Tested");
        return 0;
    }
}

int isFull(struct Stack *stack){
    if(stack -> top == stack -> size-1)
        return 1;
    else
        return 0;
}

void enqueue(struct Stack *stack, char element){
    if(!isFull(stack)) {
        printf("Is Enqueue Tested");
        stack->array[stack->top++] = element;
    }else
        printf("[ERROR] - StackOverflow: Cannot add another element, Stack is full.\n");
}

char dequeue(struct Stack *stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    else {
        printf("  [ERROR] - StackUnderflow: Cannot remove the top element, Stack is empty.\n");
        return -1;
    }
}

char peek(struct Stack *stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    else {
        printf("  [ERROR] - StackUnderflow: Cannot get the top element, Stack is empty.\n");
        return -1;
    }
}
