#include<stdio.h>
int main(){
    float number1 ;
    printf("Enter  number : ");
    scanf("%f",&number1);
    if (number1 > 0)
        printf("Number is Postive");
    else if (number1 < 0)
        printf("Number is negative");
    else 
        printf("Number is zero");
    return 0;
}