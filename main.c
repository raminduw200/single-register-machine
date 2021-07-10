/*
 * Name     :   Ramindu Walgama
 * TempNO   :   201177
 * Email    :   raminduw200@gmail.com
 */

#include "stack.c"
#include <string.h>

// get the char value of a given integer. 1 -> temp[1]
char temp[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int temp_no = 1;  // keep the track of temp variable number
// var1, var2: temporary variables to keep the pop elements of the stack
char var1;
char var2;

/*
 * @function: check a char is an integer (Ex. '2')
 * @return: true: if char is an integer. else false
 */
int isTemp(char a){
    for (int i = 1; i < 10; ++i) {
        if(temp[i] == a)     return 1;
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
        push(temp[temp_no++]);
    } else {
        temp_no = 0;
    }
}

int main() {
    char postfix[50];

    printf("Enter the postfix expression : ");
    scanf("%s", postfix);  //ABC*+DE-/

    for(int i = 0; i < strlen(postfix); ++i){
        if(postfix[i] == '+'){
            process("AD");
        } else if(postfix[i] == '-'){
            process("SB");
        } else if(postfix[i] == '*'){
            process("ML");
        } else if(postfix[i] == '/'){
            process("DV");
        } else {
            // pushing each character to the stack if its not not an operation
            push(postfix[i]);
        }
    }
    return 0;
}
