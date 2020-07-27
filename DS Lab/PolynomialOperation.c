# include <stdio.h>
# include <stdlib.h>

typedef struct node{
	int coeff;
	int expon;
	struct node* link;
}*NODE;

NODE getNode(int coeff,int expon){
	NODE temp = (NODE)malloc(sizeof(struct node));
	temp->coeff = coeff;
	temp->expon = expon;
	temp->link = NULL;
	return temp;
}

// void attachPoly(NODE head,int coeff,int expon){
// 	NODE temp = getNode(coeff,expon);
// 	int flag = 0;
// 	NODE prev;
// 	if(head->link == NULL){
// 		head->link = temp;
// 	}
// 	else{
// 		NODE curr = head->link;
// 		while(curr->link != NULL){
// 			if(curr->expon == expon){
// 				curr->coeff = curr->coeff + coeff;
// 				break;
// 			}
// 			else{
// 				curr = curr->link;
// 			}
// 		}
// 		prev = head;
// 		curr = head->link;
// 		while(curr != NULL){
// 			if(curr->expon == expon){
// 				flag = 1;
// 				break;
// 			}
// 			else{
// 				prev = curr;
// 				curr = curr->link;
// 			}
// 		}
// 		if(flag == 0){
// 			prev->link = temp;
// 		}
// 	}
// }

void attachPoly(NODE head,int coeff,int expon){
	NODE temp = getNode(coeff,expon);
	int flag = 0;
	NODE prev;
	if(head->link == NULL){
		head->link = temp;
	}
	else{
		prev = head;
		NODE curr = head->link;
		while(curr != NULL){
			if(curr->expon == expon){
				flag = 1;
				curr->coeff = curr->coeff + coeff;
				break;
			}
			else{
				prev = curr;
				curr = curr->link;
			}
		}
		if(flag == 0){
			prev->link = temp;
		}
	}
}

void createPolynomial(NODE head){
	int coeff,expon,term = 0;
	printf("Enter -999 to terminate\n");
	while(1){
		printf("\nEnter coefficient of term %d: ",++term);
		scanf("%d",&coeff);
		if(coeff == -999){
			break;
		}
		printf("\nEnter exponent of term %d: ",term);
		scanf("%d",&expon);
		attachPoly(head,coeff,expon);
	}
}

void displayPoly(NODE head){
	NODE curr = head->link;
	printf("%+dX^%d ",curr->coeff,curr->expon);
	curr = curr->link;
	while(curr != NULL){
		printf(" %+dX^%d ",curr->coeff,curr->expon);
		curr = curr->link;
	}
	printf("\n");
}

NODE addPoly(NODE head1,NODE head2){
	NODE p = head1->link;
	NODE q = head2->link;
	NODE newhead = getNode(0,0);
	/*if(p && q){
		if(p->expon > q->expon){
			newhead->link = getNode(p->coeff,p->expon);
			p = p->link;
		}
		else if(q->expon > p->expon){
			newhead->link = getNode(q->coeff,q->expon);
			q = q->link;
		}
		else{
			newhead->link = getNode((p->coeff+q->coeff),p->expon);
			p = p->link;
			q = q->link;
		}
	}*/
	while(p && q){
		if(p->expon > q->expon){
			attachPoly(newhead,p->coeff,p->expon);
			p = p->link;
		}
		else if(q->expon > p->expon){
			attachPoly(newhead,q->coeff,q->expon);
			q = q->link;
		}
		else{
			attachPoly(newhead,(p->coeff+q->coeff),p->expon);
			p = p->link;
			q = q->link;
		}
	}
	while(p){
		attachPoly(newhead,p->coeff,p->expon);
		p = p->link;
	}
	while(q){
		attachPoly(newhead,q->coeff,q->expon);
		q = q->link;
	}
	return newhead;
}

NODE multiplyPoly(NODE head1,NODE head2){
	NODE p = head1->link;
	NODE q = head2->link;
	NODE newhead = getNode(0,0);
	while(p){
		while(q){
			attachPoly(newhead,((p->coeff)*(q->coeff)),(p->expon+q->expon));
			q = q->link;
		}
		q = head2->link;
		p = p->link;
	}
	return newhead;
}

NODE subtractPoly(NODE head1,NODE head2){
	NODE p = head1->link;
	NODE q = head2->link;
	NODE newhead = getNode(0,0);
	if(p && q){
		if(p->expon > q->expon){
			newhead->link = getNode(p->coeff,p->expon);
			p = p->link;
		}
		else if(q->expon > p->expon){
			newhead->link = getNode(((-1)*(q->coeff)),q->expon);
			q = q->link;
		}
		else{
			newhead->link = getNode((p->coeff-q->coeff),p->expon);
			p = p->link;
			q = q->link;
		}
	}
	while(p && q){
		if(p->expon > q->expon){
			attachPoly(newhead,p->coeff,p->expon);
			p = p->link;
		}
		else if(q->expon > p->expon){
			attachPoly(newhead,((-1)*(q->coeff)),q->expon);
			q = q->link;
		}
		else{
			attachPoly(newhead,(p->coeff-q->coeff),p->expon);
			p = p->link;
			q = q->link;
		}
	}
	while(p){
		attachPoly(newhead,p->coeff,p->expon);
		p = p->link;
	}
	while(q){
		attachPoly(newhead,((-1)*(q->coeff)),q->expon);
		q = q->link;
	}
	return newhead;
}

int main()
{
	NODE head1 = getNode(0,0);
	NODE head2 = getNode(0,0);
	NODE addhead,multhead,subthead;
	createPolynomial(head1);
	createPolynomial(head2);
	displayPoly(head1);
	displayPoly(head2);
	addhead = addPoly(head1,head2);
	displayPoly(addhead);
	multhead = multiplyPoly(head1,head2);
	displayPoly(multhead);
	subthead = subtractPoly(head1,head2);
	displayPoly(subthead);
	return 0;
}