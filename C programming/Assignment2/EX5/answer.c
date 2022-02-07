#include<stdio.h>
#include <ctype.h>
int main(){
    char ch;
    printf("Enter character : ");
    scanf("%c",&ch);
    if (isalpha(ch))
        printf("charater is alphapet");
    else
        printf("charater is not alphapet");
    return 0;
}