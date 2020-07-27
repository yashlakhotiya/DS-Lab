# include <stdio.h>

int GCD(int a,int b){
    if(a%b == 0){
        return b;
    }
    if(b%a == 0){
        return a;
    }
    if(a < b){
        return GCD(a,b%a);
    }
    else if(a > b){
        return GCD(a%b,b);
    }
    else{
        return a;
    }
}

main(){
    printf("%d",GCD(20,10));
}
