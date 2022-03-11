#include<stdio.h>

struct Scomplex {
    float real;
    float img;
};

struct Scomplex getNumberInfo (void){
    struct Scomplex complex;
    printf("Enter real and imaginary respectively :");
    scanf("%f %f",&complex.real,&complex.img);
    return complex;
}

struct Scomplex sum2complexs(struct Scomplex ab, struct Scomplex cd){
    struct Scomplex sum;
    int x = ab.real + cd.real;
    float y = ab.img + cd.img;
    sum.real = x;
    sum.img = y;
    return sum;
}

void printNumberInfo (struct Scomplex ab){
    printf("Sum of complexs = %.1f + %.1fi",ab.real,ab.img);
    return ;
}
int main(void){
    struct Scomplex number1 = getNumberInfo();
    struct Scomplex number2 = getNumberInfo();
    struct Scomplex number3 = sum2complexs(number1,number2);
    printNumberInfo(number3);

    return 0;
}