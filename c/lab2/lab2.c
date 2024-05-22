#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, x, y, xmin, xmax, dx;

    printf("Input a: ");
    scanf("%lf", &a);

    if (a == 0)
    {
        printf("Input b: ");
        scanf("%lf", &b);
    }
    else if (a > 0)
    {
        do
        {
            printf("Input b (not b < 0): ");
            scanf("%lf", &b);
        } while (b < 0);
    }
    else
    {
        do
        {
            printf("Input b (not b > 0): ");
            scanf("%lf", &b);
        } while (b > 0);
    }

    do
    {
        printf("Input xmin<xmax: ");
        scanf("%lf%lf", &xmin, &xmax);
    } while (xmin >= xmax);

    do
    {
        printf("Input dx: ");
        scanf("%lf", &dx);
    } while (dx <= 0 || dx > (xmax - xmin));

    x = xmin;
    printf("X\t\tY\n");

    while (x <= xmax)
    {
        printf("%lf\t", x);
        if (pow(x, 2) + pow(b, 3) == 0)
        {
            printf("Function cannot be calculated!\n");
        }
        else
        {
            y = (tan(3) * a - 20 * fabs(b) - sqrt(a * b)) / (pow(x, 2) + pow(b, 3));
            printf("%lf\n", y);
        }
        x += dx;
    }
    return 0;
}