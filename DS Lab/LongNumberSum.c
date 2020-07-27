# include <stdio.h>
# include <stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}*NODE;

NODE getNode(int data){
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	temp->link = NULL;
	temp->data = data;
	return temp;
}

NODE insertFront(NODE first,int ele){
	NODE insert = getNode(ele);
	if(first == NULL){
		first = insert;
	}
	else{
		insert->link = first;
		first = insert;
	}
	return first;
}

void display(NODE first){
    if(first == NULL){
        printf("\nEMPTY!!\n");
    }
    NODE temp = first;
    while(temp !=NULL){
        printf("%d\t",temp->data);
        temp = temp->link;
    }
}

NODE addNumber(NODE f1,NODE f2){
	int divbyten,rem,sum = 0;
	NODE p = f1;
	NODE q = f2;
	NODE new = NULL;
	if(p && q){
		sum = p->data + q->data;
		divbyten = sum/10;
		rem = sum%10;
		new = getNode(rem);
		p = p->link;
		q = q->link;
	}
	while(p && q){
		sum = divbyten + p->data + q->data;
		divbyten = sum/10;
		rem = sum%10;
		new = insertFront(new,rem);
		p = p->link;
		q = q->link;
	}
	//if(!p && !q && divbyten != 0) insertFront(new,divbyten);
	if(q) insertFront(new,(q->data+divbyten));
	else if(p) insertFront(new,(p->data+divbyten));
	return new;
}

int main(){
    NODE first,second;
    first = second = NULL;
    NODE new;
	int ch,ele;
	while(1){
		printf("\nEnter 1 to insert 1st number\nEnter 2 to insert 1st number\n3 to display first number\n4 to display second number\n5 to add\n\n0 to exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("\nEnter 1st number\n");
			scanf("%d",&ele);
			first = insertFront(first,ele);
			break;

			case 2:
			printf("\nEnter second number\n");
			scanf("%d",&ele);
			second = insertFront(second,ele);
			break;

			case 3:
			display(first);
			break;

			case 4:
			display(second);
			break;

			case 5:
            new = addNumber(first,second);
            display(new);
            break;

			case 0:
            free(first);
            free(second);
            free(new);
			exit(0);
		}
	}
    return 0;
}