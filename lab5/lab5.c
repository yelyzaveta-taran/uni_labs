#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char surname[20];
    int group_number;
    int math_score;
    int pr_score;
    int en_score;
};

struct Student *createArrayOfStudents(int size)
{
    struct Student *studentsArray = (struct Student *)malloc(size * sizeof(struct Student));

    if (studentsArray == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Fill the list of students\n");

    for (int i = 0; i < size; i++)
    {
        printf("Enter student's surname: ");
        scanf("%s", studentsArray[i].surname);

        printf("Enter group number: ");
        scanf("%d", &studentsArray[i].group_number);

        printf("Enter further math score: ");
        scanf("%d", &studentsArray[i].math_score);

        printf("Enter programming fundamentals score: ");
        scanf("%d", &studentsArray[i].pr_score);

        printf("Enter english score: ");
        scanf("%d", &studentsArray[i].en_score);

        printf("\n");
    }

    return studentsArray;
}

void printListOfStudents(struct Student *students, int size)
{
    printf("List of students: \n");
    for (int i = 0; i < size; i++)
    {
        printf("Student: %s\n", students[i].surname);
        printf("Group number: %d\n", students[i].group_number);
        printf("Further math score: %d\n", students[i].math_score);
        printf("Programming fundamentals score: %d\n", students[i].pr_score);
        printf("English score: %d\n", students[i].en_score);
        printf("\n");
    }
}

void findTheBestStudent(struct Student *students, int size)
{

    int averageScores[size];
    char bestStudent[20];
    int bestScore;

    for (int i = 0; i < size; i++)
    {
        averageScores[i] = (students[i].math_score + students[i].pr_score + students[i].en_score) / 3;
    }

    bestScore = averageScores[0];
    strcpy(bestStudent, students[0].surname);

    for (int i = 0; i < size; i++)
    {
        if (averageScores[i] > bestScore)
        {
            bestScore = averageScores[i];
            strcpy(bestStudent, students[i].surname);
        }
    }

    printf("The best student: %s\n", bestStudent);
}

void countSubjectAverageScore(struct Student *students, int size)
{
    char subject[20];
    float averageScore;

    printf("Enter the subject to count average: ");
    scanf("%s", subject);

    for (int i = 0; i < size; i++)
    {
        if (!strcmp(subject, "math"))
        {
            averageScore += students[i].math_score;
        }
        else if (!strcmp(subject, "programming"))
        {
            averageScore += students[i].pr_score;
        }
        else if (!strcmp(subject, "english"))
        {
            averageScore += students[i].en_score;
        }
        else
        {
            averageScore = 0;
            printf("Unknown type of subject\n");
            break;
        }
    }

    printf("Average score: %.2f\n", averageScore / size);
}

void printListOfDebtors(struct Student *students, int size)
{
    printf("List of debtors:\n");
    for (int i = 0; i < size; i++)
    {
        if (students[i].math_score == 0 || students[i].pr_score == 0 || students[i].en_score == 0)
        {
            printf("%s\n", students[i].surname);
        }
    }
}

int main()
{
    int size;

    printf("Enter the number of students in group: ");
    scanf("%d", &size);

    struct Student *students = createArrayOfStudents(size);

    printListOfStudents(students, size);

    findTheBestStudent(students, size);

    countSubjectAverageScore(students, size);

    printListOfDebtors(students, size);

    return 0;
}