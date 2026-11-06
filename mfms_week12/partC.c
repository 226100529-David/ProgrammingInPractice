#include <stdio.h>

void displaySalaries(const double salaries[], int n);
double findHighest(const double salaries[], int n);
double calculateAverage(const double salaries[], int n);
void giveRaise(double salaries[], int n, double percent);


int main(void)
{
    double salaries[4] = {15000.00, 18500.50, 21000.75, 17200.00};

    printf("Before the raise:\n");
    displaySalaries(salaries, 4);
    printf("Highest: N$%.2f\n", findHighest(salaries, 4));
    printf("Average: N$%.2f\n", calculateAverage(salaries, 4));

    giveRaise(salaries, 4, 10);

    printf("\nAfter a 10%% raise:\n");
    displaySalaries(salaries, 4);
    printf("Highest: N$%.2f\n", findHighest(salaries, 4));
    printf("Average: N$%.2f\n", calculateAverage(salaries, 4));

    return 0;
}


void displaySalaries(const double salaries[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Employee %d: N$%.2f\n", i + 1, salaries[i]);
    }
}


double findHighest(const double salaries[], int n)
{
    int i;
    double highest;

    highest = salaries[0];

    for (i = 1; i < n; i++)
    {
        if (salaries[i] > highest)
        {
            highest = salaries[i];
        }
    }

    return highest;
}


double calculateAverage(const double salaries[], int n)
{
    int i;
    double total = 0.0;

    for (i = 0; i < n; i++)
    {
        total = total + salaries[i];
    }

    return total / n;
}


void giveRaise(double salaries[], int n, double percent)
{
    int i;

    for (i = 0; i < n; i++)
    {
        salaries[i] = salaries[i] + salaries[i] * percent / 100;
    }
}
