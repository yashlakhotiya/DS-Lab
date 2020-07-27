# include <stdio.h>
# define MAX 10
# include <string.h>
# include <math.h>

typedef struct{
    int top;
    int arr[MAX];
}stack;

void init(stack *s){
    s->top = -1;
}

void push(stack *s,int ele){
    if(s->top == MAX){
        printf("\nOVERFLOW\n");
    }
    else{
        s->top = s->top + 1;
        s->arr[s->top] = ele;
    }
}

int pop(stack *s){
    if(s->top == -1){
        printf("\nUNDERFLOW\n");
    }
    else{
        int del = s->arr[s->top];
        s->top = s->top - 1;
        return del;
    }
}

void evaluate_prefix(stack *temp,char operator,int op1,int op2){
    int result;
    switch(operator){
        case '+': result = op1 + op2;
        break;
        case '-': result = op1 - op2;
        break;
        case '*': result = op1 * op2;
        break;
        case '/': result = op1 / op2;
        break;
        case '%': result = op1 % op2;
        break;
        case '$': result = pow(op1,op2);
        break;
    }
    push(temp,result);
}

int findOperator(char c){
    switch(c){
    case '%': return 20;
    case '/': return 20;
    case '*': return 20;
    case '-': return 20;
    case '$': return 20;
    case '+': return 20;
    default : return 10;
    }
}

main(){
    stack s;
    int length,op1,op2,element;
    char exp[MAX];
    init(&s);
    printf("\nenter expression\n");
    scanf("%s",exp);
    length = strlen(exp);
    for(int i = length-1;i >= 0; i--){
        if(exp[i] == '\0' || exp[i] == ' '){
            continue;
        }
        switch(findOperator(exp[i])){
        case 20:
            op1 = pop(&s);
            op2 = pop(&s);
            evaluate_prefix(&s,exp[i],op1,op2);
            break;

        case 10:
            element = exp[i]-'0';
            push(&s,element);
            break;
        }
    }
    if(s.top != 0){
        printf("\ninvalid expression\n");
        return -1;
    }
    printf("\nEvaluation of prefix expression:\t %d\n",s.arr[s.top]);
}
