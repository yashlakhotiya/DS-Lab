# include <stdio.h>
# include <string.h>
# define true 1
# define false 0
# define MAX 50

typedef struct{
    int top;
    char arr[MAX];
}stack;

void init(stack *s){
    s->top = -1;
}

void push(stack *s,char ele){
    if(s->top == MAX){
        printf("\nOVERFLOW\n");
    }
    else{
        s->top = s->top + 1;
        s->arr[s->top] = ele;
    }
}

char pop(stack *s){
    if(s->top == -1){
        printf("\nUNDERFLOW\n");
    }
    else{
        char del = s->arr[s->top];
        s->top = s->top - 1;
        return del;
    }
}

int arePair(char a,char b){
    if(a == '(' && b ==')') return true;
    if(a == '{' && b =='}') return true;
    if(a == '[' && b ==']') return true;
    return false;
}

main(){
    stack s;
    init(&s);
    char expression[MAX],ch;
    printf("\nenter expression\n");
    scanf("%s",&expression);
    int length = strlen(expression),i=0;
    while((ch=expression[i++]) != '\0'){
        if(ch == '(' || ch == '{' || ch == '['){
            push(&s,ch);
        }
        if(ch == ')' || ch == '}' || ch == ']'){
            if(arePair(s.arr[s.top],ch)){
                pop(&s);
            }
        }
    }
    if(s.top == -1){
        printf("\n balanced\n");
    }
    else{
        printf("\nNot balanced\n");
    }
}
