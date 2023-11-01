#include <stdio.h>
#include <math.h>

int main()
{
    double d, x, y;
    printf("Input d: ");
    scanf("%lf", &d);
    printf("Input x and y: ");
    scanf("%lf%lf", &x, &y);
    if ((pow(x, 2) + pow(y, 2) < pow(d, 2)))
    {
        if (x > 0 && y > 0)
            printf("Point is in area A");
        else if (x < 0 && y < 0)
            printf("Point is in area B");
        else
            printf("Point is neither in zone A nor in zone B");
    }
    else
        printf("Point doesn't belong to given circle");
    return 0;
}