#ifndef Q
#define Q
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

typedef struct S
{
    char firstName[20];
    char lastName[20];
    int rollNumber;
    double gpa;
    int courses[20];
    int coursesNumber;
    struct S *next;
} student;

typedef enum
{
    student_not_found,
    student_succsess,
    student_failed
} student_status;
//set the head and the base of the queue to null
student_status student_init(student **, student **);
student_status add_student_from_file(student **, student **);
student_status add_student_manually(student **, student **);
//special function return object of student because it 
//used again in adding student to make sure no dublicates in 
//roll number
student *find_student_with_rollnumber(student *, int);
student_status find_student_with_firstname(student *);
student_status find_student_registed_in_course(student *);
student_status count_of_students(student *);
student_status delete_a_student(student **, student **);
student_status update_student(student *);
student_status show_all_information(student *);

#endif