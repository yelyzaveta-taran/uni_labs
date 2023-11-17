#include <stdio.h>

int main()
{
    int m, n, i, j;
    int b = 0, k = 0;
    do
    {
        printf("Input the size of first dimension: ");
        scanf("%d", &m);
    } while (m <= 0);

    do
    {
        printf("Input the size of second dimension: ");
        scanf("%d", &n);
    } while (n <= 0);

    int arrA[m][n];

    printf("Input %d array elements\n", m * n);

    for (i = 0; i < m; i++)
    {
        printf("Input %d elements for the %d row: ", n, i + 1);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arrA[i][j]);

            if (arrA[i][j] > 0)
            {
                b += 1;
            }
        }
    }

    int arrB[b];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arrA[i][j] > 0 && k < b)
            {
                arrB[k] = arrA[i][j];
                k += 1;
            }
        }
    }

    printf("Result: ");
    if (b == 0)
        printf("There are no positive numbers in array.");
    else
        for (k = 0; k < b; k++)
        {
            printf("%d  ", arrB[k]);
        }

    return 0;
}