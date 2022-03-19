#include<stdio.h>
int main (){
    int m=29;
    printf("Adress of m : %x\nValue of m : %d\n",&m,m);
    int *ab=&m;
    printf("Adress of ptr ab : %x\nconntent of ab : %d\n",ab,*ab);
    m=34;
    printf("Adress of ptr ab : %x\nconntent of ab : %d\n",ab,*ab);
    *ab=7;
    printf("Adress of m : %x\nValue of m : %d",&m,m);

}