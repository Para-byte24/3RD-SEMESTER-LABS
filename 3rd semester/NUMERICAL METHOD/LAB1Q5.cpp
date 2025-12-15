//Write program to implement Horner’s method.
#include <stdio.h>

int main()
{
    int n, i;
    float x, result;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);

    float a[n + 1];

    printf("Enter the coefficients (from highest degree to constant term):\n");
    for (i = 0; i <= n; i++)
    {
        scanf("%f", &a[i]);
    }

    printf("Enter the value of x: ");
    scanf("%f", &x);

    result = a[0];

    for (i = 1; i <= n; i++)
    {
        result = result * x + a[i];
    }

    printf("\nValue of the polynomial at x = %.2f is %.2f\n", x, result);

    return 0;
}

