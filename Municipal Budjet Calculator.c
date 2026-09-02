#include <stdio.h>
int main () {
    printf("-------Municipal Budget Calculator-------\n");
    double revenue;
    //printf("Enter the revenue: ");
    printf("Enter the revenue: ");
    scanf("%lf", &revenue);
    double expenses;
    //printf("Enter the expenses: ");
    printf("Enter the expenses: ");
    scanf("%lf", &expenses);
    double balance = revenue - expenses;
    int departements;
    //printf("Enter the number of departments: ");
    printf("Enter the number of departments: ");
    scanf("%d", &departements);
    double payroll;
    //printf("Enter the payroll: ");
    printf("Enter the payroll: ");
    scanf("%lf", &payroll);
    double procurement;
    //printf("Enter the procurement: ");
    printf("Enter the procurement: ");
    scanf("%lf", &procurement);
    double assets;
    //printf("Enter the assets: ");
    printf("Enter the assets: ");
    scanf("%lf", &assets);
    printf("-------Budget Summary-------\n");
    printf("Revenue: %.2lf\n", revenue);
    printf("Expenses: %.2lf\n", expenses);
    printf("Balance: %.2lf\n", balance);
    printf("Number of Departments: %d\n", departements);
    printf("Payroll: %.2lf\n", payroll);
    printf("Procurement: %.2lf\n", procurement);
    printf("Assets: %.2lf\n", assets);
    return 0;
    
}