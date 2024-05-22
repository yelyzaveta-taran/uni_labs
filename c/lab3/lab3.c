#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, i, j;
    bool is_descending = true;
    printf("Input array length: ");
    scanf("%d", &n);
    char arr[n];
    printf("Input array characters (total: %d)\n", n);
    for (i = 0; i < n; i++)
    {
        scanf(" %c", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                is_descending = false;
                break;
            };
        }
    }
    if (is_descending)
        printf("Array characters are in descending order.");
    else
        printf("Array characters are not in descending order. ");
    return 0;
}