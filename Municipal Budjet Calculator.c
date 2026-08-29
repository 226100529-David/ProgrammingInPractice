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
int departments;
printf("Enter the departments: ");
scanf("%d", & departments);
double payroll;
printf("Enter the payroll: ");
scanf("%lf", & payroll);
double procurement;
printf("Enter the procurement: ");
scanf("%lf", & procurement);
double assets;
printf("Enter the assets: ");
scanf("%lf", & assets);
printf("Revenue:%.2f\n", revenue);
printf("Expenses:%.2f\n", expenses);
printf("Balance:%.2f\n", balance);
printf("Departments:%d\n", departments);
printf("Payroll:%.2f\n", payroll);
printf("Procurement:%.2f\n", procurement);
printf("Assets:%.2f\n", assets);
return 0;
}