#include "queue.h"

int main(void)
{
    //base and head of the queue
    student *base, *head;
    printf("Welcome to the Student Mangement System\n");

    student_init(&base, &head);
    while (1)
    {
        
        char x[20];
        printf("Choose The Task that you want to perform\n");
        printf("1. Add the Student Details Manually\n");
        printf("2. Add the Student Details From Text file\n");
        printf("3. Find the Student Details by Roll Number\n");
        printf("4. Find the Student Details by First Name\n");
        printf("5. Find the Student registed in  course Id\n");
        printf("6. Find the Total number of Students\n");
        printf("7. Delete the Students Details by Roll Number\n");
        printf("8. Update the Students Details by Roll Number\n");
        printf("9. Show all information\n");
        printf("10. to Exit\n");
        printf("Enter your choice to perform the task: ");
        gets(x);
        int choice = atoi(x);
        if (choice == 1)
        {
            add_student_manually(&head, &base);
            if (base == NULL)
                base = head;
        }
        else if (choice == 2)
        {
            add_student_from_file(&head, &base);
            if (base == NULL)
                base = head;
        }
        else if (choice == 3)

        {
            printf("Enter Roll Number : ");
            int x;
            scanf("%d", &x);
            student *find = find_student_with_rollnumber(base, x);
            if (find == NULL)
            {
                printf("not found \n");
                printf("Enter any character to continue");
                while (getchar() != '\n')
                    ;
                while (getchar() != '\n')
                    ;
                continue;
            }
            printf("Stuendt First Name : %s\n", find->firstName);
            printf("Stuendt Last Name : %s\n", find->lastName);
            printf("Stuendt Roll Number : %d\n", find->rollNumber);
            printf("Stuendt GPA : %.3lf\n", find->gpa);
            for (int i = 0; i < find->coursesNumber; i++)
            {
                printf("course ID : %d\n",  find->courses[i]);
            }
            while (getchar() != '\n')
                ;
            while (getchar() != '\n')
                ;
        }
        else if (choice == 4)
        {
            find_student_with_firstname(base);
        }
        else if (choice == 5)
        {
            find_student_registed_in_course(base);
        }
        else if (choice == 6)
        {
            count_of_students(base);
        }
        else if (choice == 7)
        {
            delete_a_student(&head, &base);
        }
        else if (choice == 8)
        {
            update_student(base);
        }
        else if (choice == 9)
        {
            show_all_information(base);
        }
        else if (choice == 10)
        {
            break;
        }
        else
        {
            printf("\nEnter Valid Number\n");
        }
        printf("==========================================\n");
    }

    return 0;
}