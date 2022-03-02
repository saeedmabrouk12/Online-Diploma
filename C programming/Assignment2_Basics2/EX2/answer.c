#include<stdio.h>
int main(){
    char arr[]={'a','e','o','i','u'};
    char ab ;
    printf("Enter Charater : ");
    scanf("%c",&ab);
    for(int i = 0 ; i < 5 ; i++){
        if (ab==arr[i]){
            printf("Character is Vowel");
            return 0;
        }
    }
    printf("Character is Constant");
    return 0;
}