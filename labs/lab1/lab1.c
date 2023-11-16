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
            printf("The point belongs to area A");
        else if (x < 0 && y < 0)
            printf("The point belongs to area B");
        else
            printf("The point does not belong either to area A or area B");
    }
    else
        printf("The point does not belong to given circle");
    return 0;
}