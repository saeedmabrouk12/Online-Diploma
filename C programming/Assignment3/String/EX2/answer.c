#include<stdio.h>
#include<string.h>
int main (){
    char arr[26];
    printf("Enter a string : ");
    gets(arr);
    printf("Length : %d",strlen(arr));
    return 0;
}