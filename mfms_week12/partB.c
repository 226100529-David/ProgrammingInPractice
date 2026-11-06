#include <stdio.h>

void swapSalaries(double *a, double *b);
void swapSalariesWrong(double a, double b);


int main(void)
{
    double salary1 = 15000.00;
    double salary2 = 21000.75;

    printf("Before: salary1 = %.2f, salary2 = %.2f\n", salary1, salary2);

    // Wrong version: it receives copies
    swapSalariesWrong(salary1, salary2);
    printf("After wrong swap: salary1 = %.2f, salary2 = %.2f\n", salary1, salary2);

    // Right version: it receives the addresses
    swapSalaries(&salary1, &salary2);
    printf("After right swap: salary1 = %.2f, salary2 = %.2f\n", salary1, salary2);

    return 0;
}


void swapSalaries(double *a, double *b)
{
    double temp;

    temp = *a;
    *a = *b;
    *b = temp;
}


void swapSalariesWrong(double a, double b)
{
    double temp;

    temp = a;
    a = b;
    b = temp;
}
