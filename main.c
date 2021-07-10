#include "stack.c"
#include <string.h>
int main() {
    char postfix[50];
    int temp_no = 1;
    char var1;
    char var2;

    //ABC*+DE-/
    scanf("%s", postfix);

    for(int i = 0; i < strlen(postfix); ++i){
        if(postfix[i] == '+'){
            var1 = pop();
            var2 = pop();
            printf("LD \t%c \nAD \t%c\nST \tTEMP%d\n", var2, var1,temp_no++);
        } else if(postfix[i] == '-'){
            var1 = pop();
            var2 = pop();
            printf("LD \t%c \nSB \t%c\nST \tTEMP%d\n", var2, var1,temp_no++);
        } else if(postfix[i] == '*'){
            var1 = pop();
            var2 = pop();
            printf("LD \t%c \nAD \t%c\nST \tTEMP%d\n", var2, var1,temp_no++);
        } else if(postfix[i] == '/'){
            var1 = pop();
            var2 = pop();
            printf("LD \t%c \nAD \t%c\nST \tTEMP%d\n", var2, var1,temp_no++);
        } else {
            push(postfix[i]);
        }
    }
    return 0;
}
