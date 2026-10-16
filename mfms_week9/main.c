#include <stdio.h>
#include "utilities.h"
#include "employees.h"
#include "reports.h"
#include "suppliers.h"

// Function prototype
void displayMenu(void);

int main() {

    // Declaring variables
    int choice;

    float amount;

    float basicSalary;
    float housing;
    float transport;

    float revenue;
    float expenses;

    int employeeIDs[] = {101, 102, 103, 104, 105};
    int size = 5;
    int employeeID;
    int position;

    // Welcome message
    displayWelcome();

    // Menu repeats until the user chooses Exit
    do {
        displayMenu();
        choice = readInt("Enter Choice: ");

        switch (choice) {
            case 1:
                // VAT
                amount = readFloat("Enter Amount: ");
                vatReport(amount);
                break;

            case 2:
                // Salary
                basicSalary = readFloat("Enter Basic Salary: ");
                housing = readFloat("Enter Housing Allowance: ");
                transport = readFloat("Enter Transport Allowance: ");
                salaryReport(basicSalary, housing, transport);
                break;

            case 3:
                // Budget
                revenue = readFloat("Enter Revenue: ");
                expenses = readFloat("Enter Expenses: ");
                budgetReport(revenue, expenses);
                break;

            case 4:
                // Employee search
                employeeID = readInt("Enter Employee ID: ");
                position = searchEmployee(employeeID, employeeIDs, size);

                if (position != -1) {
                    printf("Employee found at position %d.\n", position);
                } else {
                    printf("Employee not found.\n");
                }
                break;

            case 5:
                addSupplier();
                break;

            case 6:
                displaySupplier();
                break;

            case 7:
                searchSupplier();
                break;

            case 8:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}

// Displays the main menu
void displayMenu(void) {
    printf("\n");
    printf("==================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Add Supplier\n");
    printf("6. Display Supplier\n");
    printf("7. Search Supplier\n");
    printf("8. Exit\n");
}
