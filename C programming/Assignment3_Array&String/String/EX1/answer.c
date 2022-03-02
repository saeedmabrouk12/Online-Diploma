#include<stdio.h>
int main (){
    int arr[26]={0};
    char c;
    printf("Enter a string : ");
    while((c= getchar())!='\n') arr[c-'a']++;
    printf("Enter a character : ");
    c= getchar();
    printf("Freq : %d",arr[c-'a']);
    return 0;
}