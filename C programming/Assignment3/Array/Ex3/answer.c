#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[100][100];
    int a , b;
    printf("Enter the size of matrix");
    scanf("%d %d",&a,&b);    
    printf("Enter the elment of matrix\n");
    for (int i = 0 ; i < a ; i++){
        for (int j = 0 ; j < b ; j++){
            printf("Enter a%d%d ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i = 0 ; i < b ; i++){
        for (int j = i+1 ; j < a ; j++){
            int temp = arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }

    printf("TRanspose\n");
    for (int i = 0 ; i < b ; i++){
        for (int j = 0 ; j < a ; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}