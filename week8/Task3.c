#include <stdio.h>
 
// Function prototype
float calculateSalary(float basic, float housing, float transport);
 
int main() {
 
    // Declaring variables
    float basicSalary;
    float housing;
    float transport;
    float grossSalary;
 
    // Get salary details from the user
    printf("Basic salary: ");
    scanf("%f", &basicSalary);
 
    printf("Housing allowance: ");
    scanf("%f", &housing);
 
    printf("Transport allowance: ");
    scanf("%f", &transport);
 
    // Calling the function
    grossSalary = calculateSalary(basicSalary, housing, transport);
 
    // Displaying the result
    printf("Gross salary: %.2f\n", grossSalary);
 
    return 0;
}
 
// Calculate the gross salary
float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}