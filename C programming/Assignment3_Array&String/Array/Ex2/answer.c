#include <stdio.h>
int main(){
    int test,arr[100];
    printf("enter number between 1 and 100");
    scanf("%d",&test);
    for(int i = 0 ; i < test ; i++){
        printf("Enter number");
        scanf("%d",&arr[i]);
    }
    int sum = 0;
    for(int i = 0 ; i < test ; i++){
        sum+=arr[i];
    }
    printf("Average = %.2f",sum/(float)test);
    return 0;
}