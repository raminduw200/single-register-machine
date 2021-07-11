/*
 * Name     :   Ramindu Walgama
 * TempNO   :   201177
 * Email    :   raminduw200@gmail.com
 */

#include "stack.c"
#include <string.h>

// get the char value of a given integer. 1 -> int_to_char[1]
char int_to_char[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int temp_no = 1;  // keep the track of int_to_char variable number
// var1, var2: temporary variables to keep the pop elements of the stack
char var1;
char var2;

/*
 * @function: check a char is an integer (Ex. '2')
 * @return: true: if char is an integer. else false
 */
int isTemp(char a){
    for (int i = 1; i < 10; ++i) {
        if(int_to_char[i] == a)     return 1;
    }
    return 0;
}

/*
 * @function: Do the given instruction(+,-,*, and /) for the
 * next two variables in the stack.
 * @param: instruction in below format.
 *         LD A which places the operand A into the register.
 *         ST A which places the contents of the register into the variable A.
 *         AD A which adds the contents of variable A to the register.
 *         SB A which subtracts the contents of the variable A from the register.
 *         ML A which multiplies the contents of the register by the variable A.
 *         DV A which divides the contents of the register by the variable A.
 * @return: void | Print the process
 */
void process(char *instruction){
    var1 = pop();
    var2 = pop();

    // Decide the print place of TEMPn variable and print.
    if (isTemp(var1) && isTemp(var2)) {
        printf("LD \tTEMP%c \n%s \tTEMP%c\nST \tTEMP%d\n", var2, instruction, var1, temp_no);
    }  else if (isTemp(var2)){
        printf("LD \tTEMP%c \n%s \t%c\nST \tTEMP%d\n", var2, instruction, var1, temp_no);
    } else if (isTemp(var1)) {
        printf("LD \t%c \n%s \tTEMP%c\nST \tTEMP%d\n", var2, instruction, var1, temp_no);
    } else {
        printf("LD \t%c \n%s \t%c\nST \tTEMP%d\n", var2, instruction, var1, temp_no);
    }

    // Reset if the temp_no variable if exceed 9
    if (temp_no < 10) {
        push(int_to_char[temp_no++]);
    } else {
        temp_no = 0;
    }
}

/*
 * @function: to check whether input has integers
 * example: '123'
 * @return: true if contains integers
 *          else false
 */
int isIntInput(char input[]){
    for (int i = 0; i < strlen(input); ++i) {
        for (int j = 1; j < 10; ++j) {
            if(input[i] == int_to_char[j])     return 1;
        }
    }
    return 0;
}

/*
 * @function: to check whether input is valid postfix
 * @return: true if input is a valid input
 *          else false
 * NOTE: This is limited to check number of instructions and the number of characters in
 *       the input.
 *       Example: ABCD/+*
 *                instructions_count(3) + 1 = character count(4)
 *       This can't validate expression which are not in order.
 *       Example : A/+*BCD
 */
int validPostfix(char input[]){
    int instructionsCount = 0;
    int charCount = 0;

    for (int i = 0; i < strlen(input); ++i) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            instructionsCount++;
        } else {
            charCount++;
        }
    }

    return charCount == instructionsCount+1;
}

int main() {
    char postfix[50];

    /*
     * NOTE that if the given input is invalid it will either one of the following errors.
     * [ERROR-POP] Stack Underflow: Stack is EMPTY!
     * [ERROR-PUSH] Stack Overflow: Stack is FULL!
     */
    printf("Enter the postfix expression : ");
    scanf("%s", postfix);  //ABC*+DE-/

    while (1) {
        if (isIntInput(postfix)) {
            printf("Please do not enter integers or decimal as the input\n");
        } else if (!validPostfix(postfix)) {
            printf("Please enter a valid postfix expression.\nExample: ABC*+DE-/");
        } else {
            for (int i = 0; i < strlen(postfix); ++i) {
                if (postfix[i] == '+') {
                    process("AD");
                } else if (postfix[i] == '-') {
                    process("SB");
                } else if (postfix[i] == '*') {
                    process("ML");
                } else if (postfix[i] == '/') {
                    process("DV");
                } else {
                    // pushing each character to the stack if its not not an operation
                    push(postfix[i]);
                }
            }
        }

        printf("\n-------------------------------------------------");
        printf("\n\nEnter the postfix expression (Enter 0 to exit): ");
        scanf("%s", postfix);  //ABC*+DE-/
        temp_no = 1;
        if(postfix[0] == '0')
            break;
    }
    return 0;
}
