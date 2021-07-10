#include <stdio.h>

int top = -1;
const int size = 50;
char stack[50];

int isFull(){
    return top == size+1;
}

int isEmpty(){
    return top == -1;
}

int getSize(){
    return size;
}

int peek(){
    if (!isEmpty())
        return stack[top];
    else
        printf("[ERROR-PEEK] Stack Underflow: Stack is EMPTY!\n");
    return 0;
}

char push(char value_){
    if (!isFull())
        stack[++top] = value_;
    else
        printf("[ERROR-PUSH] Stack Overflow: Stack is FULL!\n");
    return 0;
}

char pop(){
    if (!isEmpty())
        return stack[top--];
    else
        printf("[ERROR-POP] Stack Underflow: Stack is EMPTY!\n");
    return 0;
}

void display(){
    printf("[STACK] Printing the stack... \n");
    for (int i = top; i != -1; --i)
        printf("%c", stack[i]);
    printf("\n");
}
