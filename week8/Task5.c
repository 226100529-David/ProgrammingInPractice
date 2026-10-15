#include <stdio.h>
 
// Function prototype
void displayMenu();
 
int main() {
 
    // Declaring variables
    int choice;
 
    // Calling the function
    displayMenu();
    scanf("%d", &choice);
 
    // Displaying the option chosen
    printf("You chose option %d.\n", choice);
 
    return 0;
}
 
// Displays the main menu
void displayMenu() {
    printf("==================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}