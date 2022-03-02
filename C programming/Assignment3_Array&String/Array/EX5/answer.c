#include <stdio.h>
int main(){
    int test,arr[100];
    printf("enter number between 1 and 99");
    scanf("%d",&test);
    for(int i = 0 ; i < test ; i++){
        printf("Enter number");
        scanf("%d",&arr[i]);
    }
    printf("enter the elment to be searched");
    int num;
    scanf("%d",&num);


    int i;
    for(i = 0 ; i <test  ; i++){
        if (arr[i]==num) {
            printf("Found at location %d ",++i);
            break;
        }
    }
    if (i==test){
        printf("Not found");
    }
    return 0;
}