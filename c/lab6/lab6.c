#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 32

int main()
{
    char str1[MAX];
    char str2[MAX];
    const char delimiters[] = " ";

    printf("Input string 1 (max length: 30 characters): ");
    scanf("%[^\n]s", str1);

    printf("Input string 2 (max length: 30 characters): ");
    scanf(" %[^\n]s", str2);

    int n = strlen(str2);

    char *token = strtok(str1, delimiters);

    while (token != NULL)
    {
        if ((strlen(str2) + strlen(token)) < MAX - 1)
        {
            strncat(str2, token, n);
        }
        else
        {
            printf("Not enough space to concatenate more words.\n");
            exit(1);
        }
        token = strtok(NULL, delimiters);
    }

    printf("%s", str2);

    return 0;
}
