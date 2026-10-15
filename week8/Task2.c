#include <stdio.h>
 
// Function prototype
float calculateVAT(float amount);
 
int main() {
 
    // Declaring variables
    float amount;
    float vat;
 
    // Get the amount from the user
    printf("Enter amount: ");
    scanf("%f", &amount);
 
    // Calling the function
    vat = calculateVAT(amount);
 
    // Displaying the result
    printf("VAT: %.2f\n", vat);
 
    return 0;
}
 
// Calculate the VAT 
float calculateVAT(float amount) {
    const float VATRATE = 0.15f;
 
    return amount * VATRATE;
}