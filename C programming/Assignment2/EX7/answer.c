#include<stdio.h>
#include <ctype.h>
int main(){
    int number,fac=1;
    printf("Enter Number : ");
    scanf("%d",&number);
    if (number<0) {
        printf("Error");
        return 0;
    }
    for(int i = 1 ; i<=number;i++){
        fac*=i;
    }
    printf("factorial : %d",fac);
    return 0;
}