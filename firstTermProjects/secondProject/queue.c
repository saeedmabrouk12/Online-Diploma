#include "queue.h"

student_status student_init(student **ab, student **a)
{
    *ab = NULL;
    *a = *ab;
    return student_succsess;
}

student_status add_student_from_file(student **head, student **base)
{
    student *neww = (student *)malloc(sizeof(student));
    neww->next = NULL;

    char fileName[20];
    printf("Enter file name example test.txt : ");
    gets(fileName);

    FILE *ptr;

    // Opening file in reading mode
    ptr = fopen(fileName, "r");
    // if we can't access file
    if (NULL == ptr)
    {
        printf("file can't be opened \n");
        fclose(ptr);
        return student_failed;
    }
    // reading student info from file
    fscanf(ptr, "%s", neww->firstName);
    fscanf(ptr, "%s", neww->lastName);
    fscanf(ptr, "%d", &neww->rollNumber);
    fscanf(ptr, "%lf", &neww->gpa);
    fscanf(ptr, "%d", &neww->courses[0]);
    fscanf(ptr, "%d", &neww->courses[1]);
    fscanf(ptr, "%d", &neww->courses[2]);
    fscanf(ptr, "%d", &neww->courses[3]);
    fscanf(ptr, "%d", &neww->courses[4]);
    neww->coursesNumber = 5;

    // search if roll id is existing
    printf("%p", *base);
    // check if roll number dublicated
    student *iffound = find_student_with_rollnumber(*base, neww->rollNumber);
    // if null mean the rolling number is unique
    if (iffound == NULL)
    {
        // check if the queue is empty
        if (*head == NULL)
        {
            *head = neww;
            *base = neww;
        }
        else
        {
            (*head)->next = neww;
            (*head) = neww;
        }
    }
    else
    {
        printf("Repeated Roll Number\n");
    }

    // Closing the file
    fclose(ptr);
}
student_status add_student_manually(student **head, student **base)
{
    student *neww = (student *)malloc(sizeof(student));

    neww->next = NULL;
    printf("Enter The First Name of the Sudent: ");
    scanf("%s", neww->firstName);
    printf("Enter the Last Name of Student: ");
    scanf("%s", neww->lastName);
    printf("Enter roll Number: ");
    scanf("%d", &neww->rollNumber);
    printf("Enter GPA number:");
    scanf("%lf", &neww->gpa);
    printf("Couese ID :");
    scanf("%d", &neww->courses[0]);
    printf("Couese ID :");
    scanf("%d", &neww->courses[1]);
    printf("Couese ID :");
    scanf("%d", &neww->courses[2]);
    printf("Couese ID :");
    scanf("%d", &neww->courses[3]);
    printf("Couese ID :");
    scanf("%d", &neww->courses[4]);
    neww->coursesNumber = 5;
    student *iffound = find_student_with_rollnumber(*base, neww->rollNumber);
    if (iffound == NULL)
    {
        if (*head == NULL)
        {
            *head = neww;
            *base = neww;
        }
        else
        {
            (*head)->next = neww;
            (*head) = neww;
        }
    }
    else
    {
        printf("Repeated Roll Number\n");
    }
}
student *find_student_with_rollnumber(student *base, int x)
{

    while (base)
    {
        if (base->rollNumber == x)
        {
            return base;
        }
        base = base->next;
    }
    return NULL;
}
student_status find_student_with_firstname(student *base)
{
    char search[20];
    printf("Enter First Name : ");
    scanf("%s", search);
    while (base)
    {
        if (strcmp(search, base->firstName) == 0)
        {

            printf("Stuendt First Name : %s\n", base->firstName);
            printf("Stuendt Last Name : %s\n", base->lastName);
            printf("Stuendt Roll Number : %d\n", base->rollNumber);
            printf("Stuendt GPA : %.3lf\n", base->gpa);
            for (int i = 0; i < base->coursesNumber; i++)
            {
                printf("Stuendt course %d ID : %d\n", i, base->courses[i]);
            }
            printf("Enter any character to continue");
            while (getchar() != '\n')
                ;
            while (getchar() != '\n')
                ;
            base = base->next;
        }
        else
        {
            base = base->next;
        }
    }
    return student_not_found;
}

student_status find_student_registed_in_course(student *base)
{
    int search;
    printf("Enter Course ID : ");
    scanf("%d", &search);
    int flag = 0;
    // loop all over the queue
    while (base)
    {
        for (int i = 0; i < base->coursesNumber; i++)
        {
            if (base->courses[i] == search)
            {
                flag = 1;
                printf("Stuendt First Name : %s\n", base->firstName);
                printf("Stuendt Last Name : %s\n", base->lastName);
                printf("Stuendt Roll Number : %d\n", base->rollNumber);
                printf("Stuendt GPA : %.3lf\n", base->gpa);
                printf("Enter any character to continue");
                while (getchar() != '\n')
                    ;
                while (getchar() != '\n')
                    ;
                break;
            }
        }
        base = base->next;
    }
    if (flag == 0)
        return student_not_found;
    return student_succsess;
}
student_status count_of_students(student *base)
{
    int c = 0;
    while (base)
    {
        c++;
        base = base->next;
    }
    printf("Number of sudtents : %d\n", c);
    printf("Enter any character to continue");
    while (getchar() != '\n')
        ;
    while (getchar() != '\n')
        ;
}
student_status delete_a_student(student **head, student **base)
{
    printf("Enter Roll Number : ");
    student *it = *base;
    student *slowit = NULL;
    int r;
    scanf("%d", &r);
    while (it)
    {
        if (it->rollNumber == r)
        {
            if (it == *base)
            {
                if (it->next == NULL)
                {
                    free(*head);
                    *head = NULL;
                    *base = NULL;
                }
                else
                {
                    student *temp = (*base)->next;
                    free(*base);
                    *base = temp;
                }
            }
            else if (it->next == NULL)
            {
                free(it);
                slowit->next = NULL;
                *head = slowit;
            }
            else
            {
                slowit->next = it->next;
                free(it);
            }
            printf("Done\n");
            while (getchar() != '\n')
                ;
            while (getchar() != '\n')
                ;
            return student_succsess;
        }
        slowit = it;
        it = it->next;
    }
    printf("No student with that roll number\n");
    while (getchar() != '\n')
        ;
    while (getchar() != '\n')
        ;
    return student_not_found;
}
student_status update_student(student *base)
{
    printf("Enter Roll Number : ");
    int r;
    char str[20];
    double gpa;
    scanf("%d", &r);
    while (base)
    {
        if (base->rollNumber == r)
        {
            printf("1. update first name .\n");
            printf("2. update lastname name .\n");
            printf("3. update GPA .\n");
            printf("4. update courses .\n");
            int o;
            scanf("%d", &o);
            if (o == 1)
            {
                printf("Enter first Name : ");
                scanf("%s", str);
                strcpy(base->firstName, str);
            }
            else if (o == 2)
            {
                printf("Enter last Name : ");
                scanf("%s", str);
                strcpy(base->lastName, str);
            }
            else if (o == 3)
            {
                printf("Enter GPA : ");
                scanf("%lf", &gpa);
                base->gpa = gpa;
            }
            else if (o == 4)
            {
                printf("1. add course");
                printf("2. delete course");
                int op;
                scanf("%d", &op);
                if (op == 1)
                {
                    printf("Enter course number : ");
                    int course;
                    scanf("%d", &course);
                    base->courses[base->coursesNumber] = course;
                    base->coursesNumber++;
                }
                else if (op == 2)
                {
                    printf("Enter course number : ");
                    int course;
                    scanf("%d", &course);
                    for (int i = 0; i < base->coursesNumber; i++)
                    {
                        if (base->courses[i] == course)
                        {

                            for (int j = i; j < base->coursesNumber - 1; j++)
                            {
                                base->courses[j] = base->courses[j + 1];
                            }
                            (base->coursesNumber)--;
                            break;
                        }
                    }
                }
            }
            printf("Done\n");
            while (getchar() != '\n')
                ;
            while (getchar() != '\n')
                ;
            return student_succsess;
        }
    }
    printf("No student with that roll number\n");
    while (getchar() != '\n')
        ;
    while (getchar() != '\n')
        ;
    return student_not_found;
}
student_status show_all_information(student *base)
{
    if (base == NULL)
    {
        printf("No students in system");
        while (getchar() != '\n')
            ;
        while (getchar() != '\n')
            ;
        return student_not_found;
    }
    while (base)
    {
        printf("==========================================\n");
        printf("Stuendt First Name : %s\n", base->firstName);
        printf("Stuendt Last Name : %s\n", base->lastName);
        printf("Stuendt Roll Number : %d\n", base->rollNumber);
        printf("Stuendt GPA : %lf\n", base->gpa);
        for (int i = 0; i < base->coursesNumber; i++)
        {
            printf("course ID : %d\n", base->courses[i]);
        }
        printf("Enter any character to continue");
        while (getchar() != '\n')
            ;
        while (getchar() != '\n')
            ;
        base = base->next;
    }
    return student_succsess;
}