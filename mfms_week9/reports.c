#include <stdio.h>
#include "reports.h"
#include "budget.h"
#include "employees.h"

// Displays the amount
void vatReport(float amount) {

    // Declaring variables
    float vat;
    float total;

    // Calculating the VAT with the budget module
    vat = calculateVAT(amount);
    total = amount + vat;

    // Displaying the report
    printf("\n-----VAT REPORT-----\n");
    printf("Amount: %.2f\n", amount);
    printf("VAT (15%%): %.2f\n", vat);
    printf("Total: %.2f\n", total);
}

// Displays the salary and the gross salary
void salaryReport(float basic, float housing, float transport) {

    // Declaring variables
    float grossSalary;

    // Calculating the gross salary with the employees module
    grossSalary = calculateSalary(basic, housing, transport);

    // Displaying the report
    printf("\n-----SALARY REPORT-----\n");
    printf("Basic Salary: %.2f\n", basic);
    printf("Housing Allowance: %.2f\n", housing);
    printf("Transport Allowance: %.2f\n", transport);
    printf("Gross Salary: %.2f\n", grossSalary);
}

// Displays the revenue, expenses, balance and budget status
void budgetReport(float revenue, float expenses) {

    // Declaring variables
    float balance;

    // Calculating the balance with the budget module
    balance = calculateBudget(revenue, expenses);

    // Displaying the report
    printf("\n-----BUDGET REPORT-----\n");
    printf("Revenue: %.2f\n", revenue);
    printf("Expenses: %.2f\n", expenses);
    printf("Balance: %.2f\n", balance);

    if (balance > 0) {
        printf("Status: SURPLUS\n");
    } else if (balance < 0) {
        printf("Status: DEFICIT\n");
    } else {
        printf("Status: BALANCED\n");
    }
}
