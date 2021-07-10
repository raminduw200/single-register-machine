#include "stack.c"
#include <string.h>

char temp[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int temp_no = 1;
char var1;
char var2;

int isTemp(char a){
    for (int i = 1; i < 10; ++i) {
        if(temp[i] == a)     return 1;
    }
    return 0;
}

void process(char *instruction){
    var1 = pop();
    var2 = pop();

    if (isTemp(var1) && isTemp(var2)) {
        printf("LD \tTEMP%c \n%s \tTEMP%c\nST \tTEMP%d\n", var2, instruction, var1, temp_no);
    }  else if (isTemp(var2)){
        printf("LD \tTEMP%c \n%s \t%c\nST \tTEMP%d\n", var2, instruction, var1, temp_no);
    } else if (isTemp(var1)) {
        printf("LD \t%c \n%s \tTEMP%c\nST \tTEMP%d\n", var2, instruction, var1, temp_no);
    } else {
        printf("LD \t%c \n%s \t%c\nST \tTEMP%d\n", var2, instruction, var1, temp_no);
    }

    push(temp[temp_no++]);
}

int main() {
    char postfix[50];

    printf("Enter the postfix expression : ");
    scanf("%s", postfix);

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
            push(postfix[i]);
        }
    }
    return 0;
}
