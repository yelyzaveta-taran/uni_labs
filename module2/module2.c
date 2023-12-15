#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0;
    double module = 0, perimeter = 0;

    do
    {
        printf("Enter the number of vertices: ");
        scanf("%d", &n);
    } while (n <= 1);

    int array[n][2];

    for (int i = 0; i < n; i++)
    {
        printf("Enter coordinates for %d vertice\n", i + 1);
        printf("Enter x: ");
        scanf("%d", &array[i][0]);
        printf("Enter y: ");
        scanf("%d", &array[i][1]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i != 0)
        {
            module = sqrt(pow((array[i][0] - array[i - 1][0]), 2) + pow((array[i][1] - array[i - 1][1]), 2));
            perimeter += module;
        }
        else
        {
            module = sqrt(pow((array[i][0] - array[n - 1][0]), 2) + pow((array[i][1] - array[n - 1][1]), 2));
            perimeter += module;
        }
    }

    printf("Perimeter: %.2lf", perimeter);

    return 0;
}