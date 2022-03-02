#include<stdio.h>
#include <ctype.h>
int main(){
    char operation ;
    float operator1,operator2;
    printf("enter operation : ");
    scanf("%c",&operation);
    printf("Enter operators : ");
    scanf("%f %f",&operator1,&operator2);
    switch (operation)
    {
    case '+':
        printf("%f %c %f = %.1f",operator1,operation,operator2,operator1+operator2);
        break;
    case '-':
        printf("%f %c %f = %.1f",operator1,operation,operator2,operator1-operator2);
        break;
    case '*':
        printf("%f %c %f = %.1f",operator1,operation,operator2,operator1*operator2);
        break;
    case '/':
        printf("%f %c %f = %.1f",operator1,operation,operator2,operator1/operator2);
        break;
    default:
        printf("Enter VAlid operation");
        break;
    }
    return 0;
}