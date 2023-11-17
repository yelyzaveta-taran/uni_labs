#include <stdio.h>

int main()
{
    int m, n, i, j;
    int b = 0, k = 0;

    printf("Input the size of first dimension: ");
    scanf("%d", &m);
    printf("Input the size of second dimension: ");
    scanf("%d", &n);

    int arr1[m][n];

    printf("Input %d array elements\n", m * n);

    for (i = 0; i < m; i++)
    {
        printf("Input %d elements for the %d row: ", n, i + 1);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr1[i][j]);

            if (arr1[i][j] < 0)
            {
                b += 1;
            }
        }
    }

    int arr2[b];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr1[i][j] < 0)
            {
                arr2[k] = arr1[i][j];
                k += 1;
            }
        }
    }

    printf("Result: ");
    for (k = 0; k < b; k++)
    {
        printf("%d  ", arr2[k]);
    }

    return 0;
}