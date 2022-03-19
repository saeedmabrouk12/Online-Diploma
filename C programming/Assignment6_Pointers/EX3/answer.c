#include<stdio.h>
void reverse(char* ab){
    if(*ab==0)
        return;
    reverse(ab+1);
    printf("%c",*ab);
}
int main (){
    char al[50];
    gets(al);
    reverse(al);
}