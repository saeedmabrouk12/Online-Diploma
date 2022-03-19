#include <stdio.h>

int power(int x , int y){
    if (y==0) return 1 ;
    return x*power(x,y-1);
}

int main (void){
    int n , m ; 
    scanf("%d %d",&n,&m);
    printf("%d",power(n,m));
}