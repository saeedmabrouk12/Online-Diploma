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
    char c;
    while((c=getchar())!='\n');
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
    struct Sstudent students[10];
    for (int i = 0 ; i < 10;i++){
        students[i] = getStudentInfo();
    }
    for (int i = 0 ; i < 10;i++){
        printStudentInfo(students[i]);
    }

    return 0;
}