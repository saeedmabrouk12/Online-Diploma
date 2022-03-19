#include<stdio.h>

int main (){
    int arr[15];
    int n;
    printf("Enter the number of elments :");
    scanf("%d",&n);
    printf("Enter %d number of array\n",n);
    for(int i = 0 ; i < n ;i++){
        printf("Elment -%d: " ,i+1);
        scanf("%d",&arr[i]);
    }
    int *ff=arr+n-1;
    printf("Elments in reverse order : \n");
    for(int i = 0 ; i < n ;i++){
        printf("Elment -%d : %d \n" , n-i,*ff--);
    }
}