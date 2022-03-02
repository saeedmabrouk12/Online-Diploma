#include<stdio.h>
#include<stdlib.h>
int main(){
    float arr[2][2];
    float sum[2][2];
    printf("Enter the elment of 1st matrix\n");
    for (int i = 0 ; i < 2 ; i++){
        for (int j = 0 ; j < 2 ; j++){
            printf("Enter a%d%d ",i+1,j+1);
            scanf("%f",&arr[i][j]);
        }
    }
    printf("Enter the elment of 2st matrix\n");
    for (int i = 0 ; i < 2 ; i++){
        for (int j = 0 ; j < 2 ; j++){
            printf("Enter b%d%d ",i+1,j+1);
            scanf("%f",&sum[i][j]);
            sum[i][j]+=arr[i][j];
        }
    }
    printf("Sum of Matrix\n");
    for (int i = 0 ; i < 2 ; i++){
        for (int j = 0 ; j < 2 ; j++){
            printf("%.1f\t",sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}