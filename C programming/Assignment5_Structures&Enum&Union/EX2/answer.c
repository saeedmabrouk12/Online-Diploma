#include<stdio.h>

struct Sdistance{
    int feet;
    float inch;
};

struct Sdistance getDistanceInfo (void){
    struct Sdistance distance;
    printf("Enter information for 1st distance \n");
    printf("Enter Feet : ");
    scanf("%d",&distance.feet);
    printf("Enter Inch : ");
    scanf("%f",&distance.inch);
    return distance;
}

struct Sdistance sum2distances(struct Sdistance ab, struct Sdistance cd){
    struct Sdistance sum;
    int x = ab.feet + cd.feet;
    float y = ab.inch + cd.inch;
    if (y>=12){
        x++;
        y-=12;
    }
    sum.feet = x;
    sum.inch = y;
    return sum;
}

void printDistanceInfo (struct Sdistance ab){
    printf("Sum of distances = %d '",ab.feet);
    printf("%.1f\"",ab.inch);
    return ;
}
int main(void){
    struct Sdistance distance1 = getDistanceInfo();
    struct Sdistance distance2 = getDistanceInfo();
    struct Sdistance distance3 = sum2distances(distance1,distance2);
    printDistanceInfo(distance3);

    return 0;
}