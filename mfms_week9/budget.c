#include "budget.h"

// Calculate the VAT 
float calculateVAT(float amount) {
    const float VATRATE = 0.15f;

    return amount * VATRATE;
}

// Calculate revenue minus expenses
float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}
