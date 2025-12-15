#include <stdio.h>
#include <math.h>

double g(double x)
{
    return (2 + 4*x - x*x) / (x*x);
}

double f(double x)
{
    return (x*x*x) + (x*x) - 4*x - 2;
}

int main()
{
    double x0, x1;
    int itr = 0, max_itr = 10;
    double tol = 0.00001;

    printf("Enter initial guess x0: ");
    scanf("%lf", &x0);

    printf("\nIteration\t x\t\t f(x)\n");

    do
    {
        x1 = g(x0);

        printf("%d\t\t %lf\t %lf\n", itr + 1, x1, f(x1));

        itr++;
        x0 = x1;

    } while (fabs(f(x1)) > tol && itr < max_itr);

    printf("\n----- Result -----\n");
    printf("Estimated Root = %lf\n", x1);
    printf("Functional Value at Root = %lf\n", f(x1));
    printf("Number of Iterations = %d\n", itr);

    return 0;
}

