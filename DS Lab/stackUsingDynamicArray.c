# include <stdio.h>
# include <stdlib.h>
# define MAX 5

int *arr = (int*)malloc(MAX * sizeof(int));
int top = -1;

void push(int arr[],int *top,int ele){
    if(*top = MAX-1){
        printf("\nStack full\npress 1 to increase its size to add more elements\n0 to exit\n");
        int ch,ch1,ele1;
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("\nenter final size of stack\n");
            scanf("%d",&ch1);
            arr = (int *)realloc(ch1 * sizeof(int));
            printf("\nenter element to add\n");
            scanf("%d",&ele1);
            arr[++top] = ele;
            break;
        case 0:
            exit(0);
        }
    }
    else{
        arr[++top] = ele;
    }
}
main(){
    int top = -1,ele,ch;
    while(1){
        printf("\nenter 1 to add\n0 to exit\n");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("\nenter element to add\n");
            scanf("%d",&ele);
            push(arr,&top,ele);
            break;
        case 0:
            exit(0);
        }
    }
    free(arr);
}
