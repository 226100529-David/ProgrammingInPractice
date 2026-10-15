#include <stdio.h>
 
// Function prototypes
void displayWelcome();
void displayMenu();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);
 
int main() {
 
    // Declaring variables
    int choice;
 
    float amount;
    float vat;
 
    float basicSalary;
    float housing;
    float transport;
    float grossSalary;
 
    float revenue;
    float expenses;
    float balance;
 
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int size = 5;
    int employeeID;
    int position;
 
    // Task 1: welcome message
    displayWelcome();
 
    // Task 7: menu repeats until the user chooses Exit
    do {
        displayMenu();
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                // Task 2: calculate VAT
                printf("Enter amount: ");
                scanf("%f", &amount);
 
                vat = calculateVAT(amount);
                printf("VAT: %.2f\n", vat);
                break;
 
            case 2:
                // Task 3: calculate gross salary
                printf("Basic salary: ");
                scanf("%f", &basicSalary);
 
                printf("Housing allowance: ");
                scanf("%f", &housing);
 
                printf("Transport allowance: ");
                scanf("%f", &transport);
 
                grossSalary = calculateSalary(basicSalary, housing, transport);
                printf("Gross salary: %.2f\n", grossSalary);
                break;
 
            case 3:
                // Task 4: calculate budget balance
                printf("Enter revenue: ");
                scanf("%f", &revenue);
 
                printf("Enter expenses: ");
                scanf("%f", &expenses);
 
                balance = calculateBudget(revenue, expenses);
                printf("Balance: %.2f\n", balance);
 
                if (balance > 0) {
                    printf("SURPLUS\n");
                } else if (balance < 0) {
                    printf("DEFICIT\n");
                } else {
                    printf("BALANCED\n");
                }
                break;
 
            case 4:
                // Task 6: search for an employee ID
                printf("Enter employee ID: ");
                scanf("%d", &employeeID);
 
                position = searchEmployee(employeeID, employeeIDs, size);
 
                if (position != -1) {
                    printf("Employee found at position %d.\n", position);
                } else {
                    printf("Employee not found.\n");
                }
                break;
 
            case 5:
                printf("Goodbye.\n");
                break;
 
            default:
                printf("Invalid choice.\n");
        }
 
    } while (choice != 5);
 
    return 0;
}
 
// Task 1: displays the welcome message
void displayWelcome() {
    printf("Welcome to the Municipal Financial Management System\n");
}
 
// Task 5: displays the main menu
void displayMenu() {
    printf("\n");
    printf("==================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}
 
// Task 2: Calculate VAT
float calculateVAT(float amount) {
    const float VATRATE = 0.15f;
 
    return amount * VATRATE;
}
 
// Task 3: Calculate the gross salary
float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}
 
// Task 4: Calculate revenue minus expenses
float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}
 
// Task 6: Give the posotion of the employee
int searchEmployee(int id, int ids[], int size) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;
        }
    }
 
    return -1;
}