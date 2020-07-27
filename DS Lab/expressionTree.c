# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct node{
	char data;
	struct node *lchild;
	struct node *rchild;
}*NODE;

int isOperator(char c){
	if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^') return 1;
	else return 0;
}

NODE getNode(char c){
	NODE temp = (NODE)malloc(sizeof(struct node));
	temp->data = c;
	temp->rchild = temp->lchild = NULL;
	return temp;
}

NODE createExpTree(char postfix[]){
	NODE stack[50];
	int top = -1,i;
	NODE root,r,l;
	for(i = 0; postfix[i] != '\0'; i++){
		if(!isOperator(postfix[i])){
			root = getNode(postfix[i]);
			stack[++top] = root;
		}
		else{
			root = getNode(postfix[i]);
			r = stack[top--];
			l = stack[top--];
			root->rchild = r;
			root->lchild = l;
			stack[++top] = root;
		}
	}
	root = stack[top--];
	return root;
}

int evaluatePostfix(NODE root){
	if(!root) return 0;
	if(!root->lchild && !root->rchild) return ((root->data) - '0');
	int lval = evaluatePostfix(root->lchild);
	int rval = evaluatePostfix(root->rchild);
	if(root->data == '+') return lval + rval;
	if(root->data == '-') return lval - rval;
	if(root->data == '*') return lval * rval;
	if(root->data == '/') return lval / rval;
}

void postorderUsingTwoStack(NODE root){
	NODE s1[50],s2[50];
	int top1 = -1;
	int top2 = -1;
	NODE temp;
	s1[++top1] = root;	
	while(top1 != -1){
		temp = s1[top1--];
		s2[++top2] = temp;
		if(temp->lchild) s1[++top1] = temp->lchild;
		if(temp->rchild) s1[++top1] = temp->rchild;
	}
	while(top2 != -1){
		temp = s2[top2--];
		printf("%c\t",temp->data);
	}
}

void inorder(NODE root){
	NODE temp = root;
	NODE s[50];
	int top = -1;
	while(1){
		while(temp != NULL){
			s[++top] = temp;
			temp = temp->lchild;
		}
		if(top != -1){
			temp = s[top--];
			printf("%c\t",temp->data);
			temp = temp->rchild;
		}
		else return;
	}
}

int main(){
	char arr[50] = "456*+";
	NODE root = createExpTree(arr);
	postorderUsingTwoStack(root);
	printf("\n");
	inorder(root);
	printf("\nEvaluate Postfix %d",evaluatePostfix(root));
}