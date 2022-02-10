#include <stdio.h>
int main(){
    int test,arr[100];
    printf("enter number between 1 and 99");
    scanf("%d",&test);
    for(int i = 0 ; i < test ; i++){
        printf("Enter number");
        scanf("%d",&arr[i]);
    }
    printf("enter the elment to be inserted");
    int num;
    scanf("%d",&num);

    printf("enter the location");
    int num2;
    scanf("%d",&num2);

    for(int i = test+1 ; i >= num2-1 ; i--){
        arr[i]=arr[i-1];
    }
    arr[num2-1]=num;
    for(int i = 0 ; i < test+1 ; i++){
        printf("%d",arr[i]);
    }
    return 0;
}