#include<stdio.h>
#define cal(a) 3.14*a*a
int main(){
    int rad;
    printf("Enter The radious");
    scanf("%d",&rad);
    printf("\n area = %.2f",cal(rad));
}