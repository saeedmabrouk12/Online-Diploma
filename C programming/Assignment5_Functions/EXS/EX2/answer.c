#include<stdio.h>
#include<math.h>
int fac (int x){
    if (x==0)
        return 0 ;
    else if (x==1)
        return 1;
    else 
        return x * fac (x-1);
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d",fac(x));
    return 0;
}