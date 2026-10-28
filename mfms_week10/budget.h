#ifndef BUDGET_H
#define BUDGET_H

float calculateVAT(float amount);
float calculateBudget(float revenue, float expenses);

void addBudget(void);
void listBudgets(void);

void saveBudgets(void);
void loadBudgets(void);

#endif
