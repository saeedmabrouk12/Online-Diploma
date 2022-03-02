#include<stdio.h>
#include<string.h>
int main(){
    char str1[20];
    printf("Enter string : ");
    gets(str1);
    printf("reversed  string : ");
    for (int i = strlen(str1)-1 ; i>=0 ; i--){
        printf("%c",str1[i]);
    }
    return 0;
}