#include <stdio.h>

void toh(int n,char s,char a,char d){
    if(n ==1){
        printf("\nmove disk %d from %c to %c",n,s,d);
    }
    else{
        toh(n-1,s,d,a);
        printf("\nmove disk %d from %c to %c",n,s,d);
        toh(n-1,a,s,d);
    }
}
main(){
    toh(6,'s','a','d');
}
