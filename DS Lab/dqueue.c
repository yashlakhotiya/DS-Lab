# include <stdio.h>
# include <stdlib.h>
# define MAX 5

typedef struct dqueue
{
	int data[MAX];
	int front,rear;
}*DQUEUE;

int isEmpty(DQUEUE q){
	if(q->front == q->rear == -1){
		return 1;
	}
	return 0;
}

int isFull(DQUEUE q){
	if(q->front == ((q->rear)+1)%MAX){
		return 1;
	}
	return 0;
}

void enqueueR(DQUEUE q,int ele){
	if(isEmpty(q)){
		q->rear = q->front = 0;
		q->data[q->rear] = ele;
	}
	else if(isFull(q)){
		printf("\nQueue is Full\n");
	}
	else{
		q->rear = (q->rear+1)%MAX;
		q->data[q->rear] = ele;
	}
}

void enqueueF(DQUEUE q,int ele){
	if(isEmpty(q)){
		q->front = q->rear = 0;
		q->data[q->front] = ele;
	}
	else if(isFull(q)){
		printf("\nQueue is Full\n");
	}
	else{
		q->front = (q->front+MAX-1)%MAX;
		q->data[q->front] = ele;
	}
}

int dqueueF(DQUEUE q){
	int del;
	if(isEmpty(q)){
		printf("\nQueue is empty\n");
	}
	else{
		if(q->front == q->rear){
			del = q->data[q->front];
			q->front = q->rear = -1;
		}
		else{
			del = q->data[q->front];
			q->front = (q->front+1)%MAX;
		}
	}
	printf("\nDeleted %d Succesfully",del);
	return del;
}

int dqueueR(DQUEUE q){
	int del;
	if(isEmpty(q)){
		printf("\nQueue is empty\n");
	}
	else{
		if(q->front == q->rear){
			del = q->data[q->rear];
			q->front = q->rear = -1;
		}
		else{
			del = q->data[q->rear];
			q->rear = (q->rear+MAX-1)%MAX;
		}
	}
	printf("\nDeleted %d Succesfully",del);
	return del;
}

void display(DQUEUE q){
	if(isEmpty(q)){
		printf("\nQueue is empty\n");
		return;
	}
	else{
		int i = q->front;
		while(i != q->rear){
			printf("%d\t",q->data[i]);
			i = (i+1)%MAX;
		}
		printf("%d",q->rear);
	}
}

main(){
	DQUEUE q = (DQUEUE)malloc(sizeof(struct dqueue));
	q->front = q->rear = -1;
	int ch,ele;
	while(1){
		printf("\nenter ch\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("\nEnter ele\n");
			scanf("%d",&ele);
			enqueueF(q,ele);
			break;

			case 2:
			printf("\nEnter ele\n");
			scanf("%d",&ele);
			enqueueR(q,ele);
			break;

			case 3:
			dqueueF(q);
			break;

			case 4:
			dqueueR(q);
			break;

			case 5:
			display(q);
			break;

			case 0:
			exit(0);
		}
	}
}