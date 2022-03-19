#include<stdio.h>
int main (){
    char *al={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    printf("The Alphabets are : ");
    while(*al!=0){
        printf("%c ",*(al++));
    }

}