#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a, b;
    bool isEqual;

    do
    {
        printf("Input amount of digits in number (max 5): ");
        scanf("%d", &a);
    } while (a > 5 || a < 0 || a == 0);

    do
    {
        printf("Input the number with defined number of digits (max 10000): ");
        scanf("%d", &b);
    } while (b > 10000 || a < 0 || a == 0);

    int array[a];

    for (int i = a - 1; i >= 0; i--)
    {
        array[i] = b % 10;
        b /= 10;
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = i + 1; j <= a - 1; j++)
        {
            if (array[i] == array[j])
            {
                isEqual = true;
                break;
            }
        }
    }

    if (isEqual == 1)
        printf("There are equal digits in the number");
    else
        printf("There are no equal digits in the number");

    return 0;
}