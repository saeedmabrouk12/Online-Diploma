#include<stdio.h>
int main(){
    float number1 ,max=0;
    printf("Enter 3 numbers : ");
    for (int i = 0 ; i < 3 ; i++){
        scanf(" %f",&number1);
        if (number1>max)
            max=number1;
    }
    printf("Largest is : %f",max);
    return 0;
}