#include<stdio.h>

void func (char* str){
    if (*str==0)
        return;
    func(str+1);
    printf("%c",*str);
}

int main (void){
    char ab[100];
    gets(ab);
    func(ab);
}