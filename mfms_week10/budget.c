#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "utilities.h"
#include "config.h"

// Declaring budget records (one budget per department)
char budgetDepartments[MAX_RECORDS][50];
float budgetRevenues[MAX_RECORDS];
float budgetExpenses[MAX_RECORDS];
int budgetCount = 0;

// Calculate the VAT
float calculateVAT(float amount) {
    const float VATRATE = 0.15f;

    return amount * VATRATE;
}

// Calculate revenue minus expenses
float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

// Adds the budget of a department
void addBudget(void) {

    // Declaring variables
    char department[50];
    float revenue;
    float expenses;

    if (budgetCount == MAX_RECORDS) {
        printf("The budget list is full.\n");
        return;
    }

    printf("Enter Department: ");
    readString(department, sizeof(department));

    if (isValidText(department) == 0) {
        printf("Invalid department: it cannot be empty or contain |.\n");
        return;
    }

    printf("Enter Revenue: ");
    revenue = readFloat();
    printf("Enter Expenses: ");
    expenses = readFloat();

    // Storing the budget at the next free position
    strcpy(budgetDepartments[budgetCount], department);
    budgetRevenues[budgetCount] = revenue;
    budgetExpenses[budgetCount] = expenses;
    budgetCount++;

    printf("Budget added. Balance: %.2f\n", calculateBudget(revenue, expenses));
}

// Displays all the budgets with their balance and status
void listBudgets(void) {

    // Declaring variables
    float balance;

    if (budgetCount == 0) {
        printf("No budgets yet.\n");
    } else {
        printf("\n-----BUDGETS-----\n");

        for (int i = 0; i < budgetCount; i++) {
            balance = calculateBudget(budgetRevenues[i], budgetExpenses[i]);

            printf("Department: %s | Revenue: %.2f | Expenses: %.2f | Balance: %.2f | ",
                   budgetDepartments[i], budgetRevenues[i], budgetExpenses[i], balance);

            if (balance > 0) {
                printf("SURPLUS\n");
            } else if (balance < 0) {
                printf("DEFICIT\n");
            } else {
                printf("BALANCED\n");
            }
        }

        printf("Total: %d budget(s)\n", budgetCount);
    }
}

// Saves all the budgets in the text file
// Format: one budget per line -> department|revenue|expenses
void saveBudgets(void) {

    // Declaring variables
    FILE *fp = fopen(BUDGETS_FILE, "w");

    if (fp == NULL) {
        perror(BUDGETS_FILE);
        printf("Budgets not saved (check that the data folder exists).\n");
        return;
    }

    for (int i = 0; i < budgetCount; i++) {
        fprintf(fp, "%s|%.2f|%.2f\n", budgetDepartments[i], budgetRevenues[i], budgetExpenses[i]);
    }

    fclose(fp);
    printf("%d budget(s) saved to %s\n", budgetCount, BUDGETS_FILE);
}

// Loads the budgets from the text file (replaces the budgets in memory)
void loadBudgets(void) {

    // Declaring variables
    FILE *fp = fopen(BUDGETS_FILE, "r");

    if (fp == NULL) {
        perror(BUDGETS_FILE);
        printf("No budgets loaded.\n");
        return;
    }

    budgetCount = 0;

    // fscanf returns 3 when the department, the revenue and the expenses were read
    while (budgetCount < MAX_RECORDS &&
           fscanf(fp, "%49[^|\n]|%f|%f\n", budgetDepartments[budgetCount],
                  &budgetRevenues[budgetCount], &budgetExpenses[budgetCount]) == 3) {
        budgetCount++;
    }

    // The loop stopped before the end of the file: a line is not in the right format
    if (budgetCount < MAX_RECORDS && feof(fp) == 0) {
        printf("Warning: a line in %s is not in the right format, loading stopped there.\n",
               BUDGETS_FILE);
    }

    fclose(fp);
    printf("%d budget(s) loaded from %s\n", budgetCount, BUDGETS_FILE);
}
