#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct
{
    char name[30];
    int roll;
    float marks;
    char grade;
} Student;

Student s[MAX];
int n = 5;

void show()
{
    printf("\n--- Grade Sheet ---\n");
    for (int i = 0; i < n; i++)
        printf("%d. %s | Roll: %d | Marks: %.1f | Grade: %c\n", i + 1, s[i].name, s[i].roll,
               s[i].marks, s[i].grade);
}

void add()
{
    if (n >= MAX)
    {
        printf("Limit reached.\n");
        return;
    }
    printf("Enter Name Roll Marks Grade: ");
    scanf("%s %d %f %c", s[n].name, &s[n].roll, &s[n].marks, &s[n].grade);
    n++;
}

void remove_by_roll()
{
    int r;
    printf("Enter Roll to Delete: ");
    scanf("%d", &r);
    for (int i = 0; i < n; i++)
    {
        if (s[i].roll == r)
        {
            s[i] = s[n - 1];
            n--;
            printf("Deleted.\n");
            return;
        }
    }
    printf("Roll not found.\n");
}

void update()
{
    int r;
    printf("Enter Roll to Modify: ");
    scanf("%d", &r);
    for (int i = 0; i < n; i++)
    {
        if (s[i].roll == r)
        {
            printf("Enter New Name Marks Grade: ");
            scanf("%s %f %c", s[i].name, &s[i].marks, &s[i].grade);
            printf("Updated.\n");
            return;
        }
    }
    printf("Roll not found.\n");
}

void topper()
{
    if (n == 0)
    {
        printf("No records.\n");
        return;
    }
    int top = 0;
    for (int i = 1; i < n; i++)
        if (s[i].marks > s[top].marks) top = i;
    printf("\n Topper: %s (Roll %d) with %.1f marks\n", s[top].name, s[top].roll, s[top].marks);
}

int main()
{
    // Preloaded data
    strcpy(s[0].name, "Ayush");
    s[0].roll = 101;
    s[0].marks = 88;
    s[0].grade = 'A';
    strcpy(s[1].name, "Riya");
    s[1].roll = 102;
    s[1].marks = 91;
    s[1].grade = 'A';
    strcpy(s[2].name, "Kabir");
    s[2].roll = 103;
    s[2].marks = 76;
    s[2].grade = 'B';
    strcpy(s[3].name, "Neha");
    s[3].roll = 104;
    s[3].marks = 84;
    s[3].grade = 'A';
    strcpy(s[4].name, "Zara");
    s[4].roll = 105;
    s[4].marks = 95;
    s[4].grade = 'A';

    int ch;
    do
    {
        printf("\n1.Show 2.Add 3.Delete 4.Modify 5.Topper 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                show();
                break;
            case 2:
                add();
                break;
            case 3:
                remove_by_roll();
                break;
            case 4:
                update();
                break;
            case 5:
                topper();
                break;
        }
    } while (ch != 6);
    return 0;
}