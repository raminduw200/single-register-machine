/*
 * Name     :   Ramindu Walgama
 * TempNO   :   201177
 * Email    :   raminduw200@gmail.com
 */

#include <stdio.h>

int top = -1;
const int size = 50;
char stack[50];

/*
 * NOTE
 * that all the methods are not being used in the implementation of
 * single register process but used for debugging and testing purposes.
 */

/*
 * Checks the stack is full
 * @return: boolean if stack is full
 */
int isFull(){
    return top == size+1;
}

/*
 * Checks the stack is empty
 * @return: boolean if stack is empty
 */
int isEmpty(){
    return top == -1;
}

// @return: int | size of the stack
int getSize(){
    return size;
}

/*
 * Get the top element of the stack without removing it.
 * @return: char | top element of the stack
 */
char peek(){
    if (!isEmpty())
        return stack[top];
    else
        printf("[ERROR-PEEK] Stack Underflow: Stack is EMPTY!\n");
    return 0;
}

/*
 * Add a character to the stack
 * @return: void
 */
void push(char value_){
    if (!isFull())
        stack[++top] = value_;
    else
        printf("[ERROR-PUSH] Stack Overflow: Stack is FULL!\n");
}

/*
 * Remove the top element of the stack.
 * @return: char | top element of the stack
 */
char pop(){
    if (!isEmpty())
        return stack[top--];
    else
        printf("[ERROR-POP] Stack Underflow: Stack is EMPTY!\n");
    return 0;
}

/*
 * Display all the elements in the stack without removing
 * :: Used for debugging.
 */
void display(){
    printf("[STACK] Printing the stack... \n");
    for (int i = top; i != -1; --i)
        printf("%c", stack[i]);
    printf("\n");
}
