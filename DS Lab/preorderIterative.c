# include <stdio.h>
# include <stdlib.h>
# define true 1
# define false 0
typedef struct node{
	int data;
	struct node *rchild;
	struct node *lchild;
}*NODE;

int count = 0;

NODE getNode(int data){
	NODE temp = (NODE)malloc(sizeof(struct node));
	temp->data = data;
	temp->rchild = temp->lchild = NULL;
	return temp;
}

NODE createBST(NODE root,int ele){
	NODE temp,prev;
	NODE main = getNode(ele);
	if(root == NULL){
		root = main;
		return;
	}
			temp = root;
			prev = NULL;
			while(temp != NULL){
				prev = temp;
				if(ele < temp->data){
					temp = temp->lchild;
				}
				else if(ele > temp->data){//NOTICE THE USE OF ELSE IF HERE.IF I DONT UISE ELSE IF< THEN TEMP IUS ALREADY UPDATED AND TEMP = TEMP->RCHILD ALSO EXECUTES
					temp = temp->rchild;
				}
			}
			if(ele < prev->data){
				prev->lchild = main;
			}
			else if(ele > prev->data){
				prev->rchild = main;
			}
			return root;
	}

void preorder(NODE root){

////BOTH IMPLEMENTATION ARE CORRECT///////

	NODE stack[50];
	NODE temp = root;
	int top = -1;
	stack[++top] = temp;
	while(top != -1){
		temp = stack[top--];
		printf("%d\t",temp->data);
		if(temp->rchild != NULL) stack[++top] = temp->rchild;
		if(temp->lchild != NULL) stack[++top] = temp->lchild;
	}




	/*NODE s[50];
	NODE curr = root;
	int top = -1;
	if(curr == NULL){
		printf("\nEmpty tree\n");
		return;
	}
	while(1){
		while(curr != NULL){
			printf("%d\t",curr->data);
			s[++top] = curr;
			curr = curr->lchild;
		}
		if(top != -1){
			curr = s[top--];
			curr = curr->rchild;
		}
		else{
			return;
		}
	}*/
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
			printf("%d\t",temp->data);
			temp = temp->rchild;
		}
		else return;
	}
}

void postorderUsingOneStack(NODE root){
	NODE curr = root;
	NODE s[50];
	int top = -1;
	while(1){
		if(curr){
			s[++top] = curr;
			curr = curr->lchild;
		}
		else{
			if(top == -1) break;
			else{
				if(s[top]->rchild == NULL){
					curr = s[top--];
					printf("%d\t",curr->data);
					while(curr == s[top]->rchild){
						printf("%d\t",s[top]->data);
						curr = s[top--];
					}
				}
				if(top!=-1){
					curr = s[top]->rchild;
				}
				else{
					curr = NULL;
				}
			}
		}
	}
}

typedef struct{
	NODE arr[50];
	int rear;
	int front;
}queue;

void levelOrderTraversal(NODE root){
	queue q;
	NODE temp = root;
	q.rear = q.front = -1;
	if(root == NULL){
		printf("Empty\n");
	}
	else{
		q.arr[++(q.rear)] = temp;
	}
	while(1){
		if(q.front != q.rear){
			temp = q.arr[++(q.front)];
			printf("%d\t",temp->data);
			if(temp->lchild) q.arr[++(q.rear)] = temp->lchild;
			if(temp->rchild) q.arr[++(q.rear)] = temp->rchild;
		}
		else{
			return;
		}
	}
}

NODE copyBST(NODE root){
	NODE temp;
	if(!root) return NULL;
		temp = getNode(root->data);
		temp->rchild = copyBST(root->rchild);
		temp->lchild = copyBST(root->lchild);
		return temp;
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
		printf("%d\t",temp->data);
	}
}

int checkTreeEqualRecursive(NODE root1,NODE root2){
	NODE p = root1;
	NODE q = root2;

	if(!p && !q){
		return 1;
	}
	if(p && q){
		if(p->data == q->data && checkTreeEqualRecursive(p->lchild,q->lchild) && checkTreeEqualRecursive(p->rchild,q->rchild)){
			return 1;
		}
	}
	return 0;
}

/*int checkTreeEqualIterative(NODE root1,NODE root2){

}
*/
int isBST(NODE root,int min,int max){
	if(root == NULL) return true;
	if(root->data < min || root->data > max) return false;
	return (isBST(root->lchild,min,root->data) && isBST(root->rchild,root->data,max));
}

/*void countLeafNodesRecursive(NODE root){  //This is giving 1 less than the correct answer
	//int count = 0;  We need to take count as global variab;e
	if(root){
		if(root->lchild == NULL && root->rchild == NULL){
			count++;
		}
		if(root->lchild){
			countLeafNodesRecursive(root->lchild);
		}
		if(root->rchild){
			countLeafNodesRecursive(root->rchild);
		}
	}
}*/

int countLeafNodeMyLogic(NODE root){
	count = 0;
	if(root == NULL) return 1;
	if(root){
		if(countLeafNodeMyLogic(root->lchild) && countLeafNodeMyLogic(root->rchild)){
			count++;
			return 1;
		}
	}
}

int countNodes(NODE root){
	if(!root) return 0;
	else{
		return (1 + countNodes(root->lchild) + countNodes(root->rchild)); 
	}
}

/*int countNodes(NODE root){
	int c = 1;
	if(root ==  NULL) return 0;
	else{
		c+=countNodes(root->lchild);
		c+=countNodes(root->rchild); THIS IS ALSO CORRECT
		return c;
	} 
}*/

int max(int a,int b){
	return (a>b)?a:b;
}

int heightBST(NODE root){
	if(root == NULL) return 0;

	return(1 + max(heightBST(root->lchild),heightBST(root->rchild)));
}

int printAncestors(NODE root,int ele){
	NODE p = root;
	if(p != NULL){
		if(p->data == ele){
			return 1;
		}
		if(printAncestors(p->lchild,ele) || printAncestors(p->rchild,ele)){
			printf("%d\t",p->data);
			return 1;
		}
	}
	else return 0;
}

NODE mirror(NODE root){
	if(root == NULL) return;
	else{
		mirror(root->lchild);
		mirror(root->rchild);
		NODE temp = root->lchild;
		root->lchild = root->rchild;
		root->rchild = temp;
	}
	return root;
}

NODE mirrorMyLogic(NODE root){
	NODE temp;
	if(root == NULL) return NULL;
	else{
		temp = getNode(root->data);
		temp->lchild = mirrorMyLogic(root->rchild);
		temp->rchild = mirrorMyLogic(root->lchild);
	}
	return temp;
}

void delBST(NODE root,int ele){
	NODE successor,parent;
	successor = parent = NULL;
	if(root == NULL) printf("\nEmpty\n");
	NODE curr = root;
	NODE prev = NULL;
	while(curr->data != ele){
		prev = curr;
		if(ele > curr->data) curr = curr->rchild;
		else if(ele < curr->data) curr = curr->lchild;
	}
	if(curr->rchild ==NULL && curr->lchild == NULL){
		free(curr);
		return;
	}
	else if(curr->rchild != NULL && curr->lchild == NULL){
		prev->rchild = curr->rchild;
		free(curr);
		return;
	}
	else if(curr->rchild == NULL && curr->lchild != NULL){
		prev->lchild = curr->lchild;
		free(curr);
		return;
	}
	else if(curr->rchild != NULL && curr->lchild != NULL){
		parent = curr;
		NODE prev = NULL;
		successor = parent->rchild;
		while(successor->lchild != NULL){
			prev = successor;
			successor = successor->lchild;
		}
		curr->data = successor->data;
		if(successor->rchild == NULL){
			prev->lchild = NULL;
		}
		else if(successor->rchild != NULL){
			prev->lchild = successor->rchild;
		}

		//or we can write prev->lchild = successor->rchild;
		//curr->rchild = successor->rchild;   XXXXXXX prev should be there instead of curr
		free(successor);
	}
}

int* inorderForBTtoBSTconvert(NODE root,int inord[]){
	int n = 0;
	int top = -1;
	NODE s[50];
	if(root == NULL) return;
	else{
		NODE curr = root;
		while(1){

			while(curr != NULL){
				s[++top] = curr;
				curr = curr->lchild;
			}
			if(top != -1){
				curr = s[top--];
				inord[n++] = curr->data;
				printf("%d\n",inord[n-1]);
				curr = curr->rchild;
			}
		}
	}
	return inord;
}

int comp(const void *a,const void *b){
	int *x = (int*)a;
	int *y = (int*)b;
	return (*x>*y)-(*x<*y);
}

NODE convertBinTreeToBSTWithoutChangingStructure(NODE root,int inorder[]){
	int i,j;
	int n = countNodes(root);
	inorder = inorderForBTtoBSTconvert(root,inorder);
	for(i = 0; i < n; i++){
		for(j = 0; j < n-i-1; j++){
			if(inorder[j] > inorder[j+1]){
				int temp = inorder[j];
				inorder[j] = inorder[j+1];
				inorder[j+1] = temp;
			}
		}
	}
	

	//qsort(inorder,n,sizeof(*inorder),comp);
	NODE s[50];
	int top = -1;
	NODE temp = root;
	int k = 0;
	while(1){
		while(temp!= NULL){
			s[++top] = temp;
			temp = temp->lchild;
		}
		if(top != -1){
			temp = s[top--];
			temp->data = inorder[k++];
			temp = temp->rchild;
		}
	}
	return temp;
}

/*int countLeafNodesIterative(NODE root){
	
}*/

int main(){
	NODE root = NULL;
	root = createBST(root,8);
	createBST(root,7);
	createBST(root,26);
	createBST(root,15);
	createBST(root,30);
	createBST(root,14);
	createBST(root,16);
	createBST(root,29);
	createBST(root,31);
	createBST(root,27);
	createBST(root,28);
	printf("Preorder\n");
	preorder(root);
	printf("\nInorder\n");
	inorder(root);
	printf("\npostorderUsingOneStack\n");
	postorderUsingOneStack(root);
	printf("\npostorderUsingTwoStack\n");
	postorderUsingTwoStack(root);
	printf("\nisBST\t%d",isBST(root,-9999,9999));
	//countLeafNodesRecursive(root);
	//printf("\ncount LeafNodesR\t%d",count);
	countLeafNodeMyLogic(root);
	printf("\ncount LeafNodesMyLogic\t%d",count);
	//printf("\ncount LeafNodesI\t%d",countLeafNodesRecursive(root));
	printf("\nHeight\t%d",heightBST(root));
	printf("\nlevel\n");
	levelOrderTraversal(root);
	printf("\nlevel\n");
	levelOrderTraversal(root);
	printf("\ninorder\n");
	inorder(root);
	printf("\nAncestors\n");
	printAncestors(root,28);
	printf("\ninorder\n");
	inorder(root);
	printf("\ndel\n");
	delBST(root,26);
	inorder(root);
	printf("\nMirrorMyLogic\n");
	inorder(mirrorMyLogic(root));
	printf("\nCONVERT BT to BST without changing structure\n");
	int inord[50];
	NODE new = convertBinTreeToBSTWithoutChangingStructure(mirrorMyLogic(root),inord);
	inorder(new);
	printf("\nMirror\n");
	inorder(mirror(root));
}