#include<stdio.h>
typedef struct stu
{
    char name[20];
    int id;
}student;

int main (){
    student s1={"alex",2001};
    student s2={"saeed",2002};
    student *arr[]={&s1,&s2};
    printf("employee name : %s\nEmployee ID : %d",arr[0]->name,arr[0]->id);

}