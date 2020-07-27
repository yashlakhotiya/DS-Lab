# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int isOperator(char c){
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(') return 1;
	else return 0;
}

typedef struct stack{
	char data[100];
	int top;
}STACK;

int insideStackPriority(char c){
	switch(c){
		case '+':
		case '-':return 1;
		break;

		case '*':
		case '/':return 3;
		break;

		case '^':return 5;
		break;

		case'(':return 0;
		break;

		case '#': return -1;
		break;
	}
}

int incomingSymbolPriority(char c){
	switch(c){
		case '+':
		case '-':return 1;
		break;

		case '*':
		case '/':return 3;
		break;

		case '^': return 5;
		break;

		case '(': return 10;
		break;
	}
}

void infixToPostfix(char infix[]){
	int i;
	char c;

	STACK s1,s2;
	s1.top = s2.top = -1;

	s2.data[++(s2.top)] = '#';

	for(i = 0; (c = infix[i]) != '\0'; i++){
		if(!isOperator(c)){
			s1.data[++(s1.top)] = c;
		}
		else{
			if(incomingSymbolPriority(c) > insideStackPriority(c2.data[c2.top])){
				c2.data(++c2.top) = c;
			}
			else{
				if(c == ')'){
					while(c != '('){
						s1.data[++(s1.top)] = s2.data[s2.top--];
					}
					s2.top--;
				}
				else{
					while(incomingSymbolPriority(c) < insideStackPriority(c2.data[c2.top])){
						c1.data[++(c1.top)] = c2.data[c2.top--];
					}
				}
			}
		}
	}
	while(c2.data[c2.top] != '#'){
		c1.data[++(c1.top)] = c2.data[c2.top--];
	}

	for(i = 0;i < strlen(infix); i++){
		printf("%c\t",s1.arr[i]);
	}
}

main(){
	char infix[10] = "a+b-c*d";
	infixToPostfix(infix);
}