#include <stdio.h>
 
// Function prototype
float calculateBudget(float revenue, float expenses);
 
int main() {
 
    // Declaring variables
    float revenue;
    float expenses;
    float balance;
 
    // Get budget details from the user
    printf("Enter revenue: ");
    scanf("%f", &revenue);
 
    printf("Enter expenses: ");
    scanf("%f", &expenses);
 
    // Calling the function
    balance = calculateBudget(revenue, expenses);
 
    // Displaying the result
    printf("Balance: %.2f\n", balance);
 
    if (balance > 0) {
        printf("SURPLUS\n");
    } else if (balance < 0) {
        printf("DEFICIT\n");
    } else {
        printf("BALANCED\n");
    }
 
    return 0;
}
 
// Calculate revenue minus expenses
float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}