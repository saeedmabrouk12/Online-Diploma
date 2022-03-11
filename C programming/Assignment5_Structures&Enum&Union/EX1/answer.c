#include<stdio.h>

struct Sstudent{
    char name[30];
    int roll;
    float marks;
};

struct Sstudent getStudentInfo (void){
    struct Sstudent student1;
    printf("Enter Student Name : ");
    gets(student1.name);
    printf("Enter Student Roll : ");
    scanf("%d",&student1.roll);
    printf("Enter Student Marks : ");
    scanf("%f",&student1.marks);
    return student1;
}

void printStudentInfo (struct Sstudent ab){
    struct Sstudent student1;
    printf("Student Name : %s\n",ab.name);
    printf("Student Roll : %d\n",ab.roll);
    printf("Student Marks : %.2f\n",ab.marks);
    return ;
}
int main(void){
    struct Sstudent student = getStudentInfo();
    printStudentInfo(student);

    return 0;
}