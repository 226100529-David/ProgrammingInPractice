#include <stdio.h>
int main() {

printf("-------MUNICIPAL BUDGET CALCULATOR-------\n");
double revenue;
printf("Enter the revenue: ");
scanf("%lf", & revenue);
double expenses;
printf("Enter the total expenses: ");
scanf("%lf", & expenses);
double balance = revenue - expenses ;
printf("Revenue:%.2f\n", revenue);
printf("Expenses:%.2f\n", expenses);
printf("Balance:%.2f\n", balance);

return 0;
}