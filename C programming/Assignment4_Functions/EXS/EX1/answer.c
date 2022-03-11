#include<stdio.h>
#include<math.h>
void prime (int x , int y){
    for (int i = x+1 ; i < y ; i++){
        int j ;
        int c = sqrt(i)+1 ;
        for (j = 2 ; j < c ; j++){
            if (i%j==0)
                break;
        }
        if (j==(int)sqrt(i)+1)
            printf("%d ",i);
    }
}

int main(){
    int x, y ;
    scanf("%d %d", &x,&y);
    prime(x,y);
    return 0;
}