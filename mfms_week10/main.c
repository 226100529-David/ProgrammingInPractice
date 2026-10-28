#include <stdio.h>
#include "utilities.h"
#include "employees.h"
#include "budget.h"
#include "reports.h"
#include "suppliers.h"
#include "assets.h"
#include "config.h"

// Function prototypes
void displayMenu(void);
void saveData(void);
void loadData(void);
int savedDataExists(void);

int main() {

    // Declaring variables
    int choice;
    int confirm;
    int dataLoaded = 0;     // 1 when the records in memory already match the data files

    float amount;

    float basicSalary;
    float housing;
    float transport;

    float revenue;
    float expenses;

    // Welcome message
    displayWelcome();

    if (savedDataExists() == 1) {
        printf("Saved data found: choose 15 to load it.\n");
    }

    // Menu repeats until the user chooses Exit
    do {
        displayMenu();
        printf("Enter Choice: ");
        choice = readINT();

        switch (choice) {
            case 1:
                // VAT
                printf("Enter Amount: ");
                amount = readFloat();
                vatReport(amount);
                break;

            case 2:
                // Salary
                printf("Enter Basic Salary: ");
                basicSalary = readFloat();
                printf("Enter Housing Allowance: ");
                housing = readFloat();
                printf("Enter Transport Allowance: ");
                transport = readFloat();
                salaryReport(basicSalary, housing, transport);
                break;

            case 3:
                // Budget
                printf("Enter Revenue: ");
                revenue = readFloat();
                printf("Enter Expenses: ");
                expenses = readFloat();
                budgetReport(revenue, expenses);
                break;

            case 4:
                addEmployee();
                break;

            case 5:
                listEmployees();
                break;

            case 6:
                findEmployee();
                break;

            case 7:
                addSupplier();
                break;

            case 8:
                listSuppliers();
                break;

            case 9:
                searchSupplier();
                break;

            case 10:
                addAsset();
                break;

            case 11:
                listAssets();
                break;

            case 12:
                addBudget();
                break;

            case 13:
                listBudgets();
                break;

            case 14:
                // Save Data: "w" replaces the files, so saved data that was
                // not loaded first would be lost. The user must confirm.
                confirm = 1;

                if (dataLoaded == 0 && savedDataExists() == 1) {
                    printf("Saved data exists but has not been loaded.\n");
                    printf("Saving now will replace it. Continue? (1 = Yes, 0 = No): ");
                    confirm = readINT();
                }

                if (confirm == 1) {
                    saveData();
                    dataLoaded = 1;
                } else {
                    printf("Save cancelled. Choose 15 to load the saved data first.\n");
                }
                break;

            case 15:
                loadData();
                dataLoaded = 1;
                break;

            case 16:
                loadEmployeesBinary();
                break;

            case 17:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 17);

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
    printf("4. Add Employee\n");
    printf("5. List Employees\n");
    printf("6. Search Employee\n");
    printf("7. Add Supplier\n");
    printf("8. List Suppliers\n");
    printf("9. Search Supplier\n");
    printf("10. Add Asset\n");
    printf("11. List Assets\n");
    printf("12. Add Budget\n");
    printf("13. List Budgets\n");
    printf("14. Save Data\n");
    printf("15. Load Data\n");
    printf("16. Load Employees (Binary)\n");
    printf("17. Exit\n");
}

// Saves all the records in the data folder
void saveData(void) {
    printf("\n-----SAVING DATA-----\n");
    saveEmployees();
    saveEmployeesBinary();
    saveSuppliers();
    saveAssets();
    saveBudgets();
}

// Loads all the records from the data folder
void loadData(void) {
    printf("\n-----LOADING DATA-----\n");
    loadEmployees();
    loadSuppliers();
    loadAssets();
    loadBudgets();
}

// Returns 1 if at least one data file already exists, otherwise 0
int savedDataExists(void) {
    if (fileExists(EMPLOYEES_FILE) == 1 || fileExists(SUPPLIERS_FILE) == 1 ||
        fileExists(ASSETS_FILE) == 1 || fileExists(BUDGETS_FILE) == 1) {
        return 1;
    }

    return 0;
}
