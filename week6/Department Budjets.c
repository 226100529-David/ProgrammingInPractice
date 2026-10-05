#include <stdio.h>

int main() {
    
    //Declaring variables

    float budgets[10];
    float total = 0;
    float average;
    float temp;

    //Capturing department budgets 

    for (int i = 0; i < 10; i++) {

        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);

        total = total + budgets[i];
    }

    

    average = total / 10;

    //Display the budgets

    printf("Department Budgets\n");

    for (int i = 0; i < 10; i++) {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }

    //Display the average

    printf("Total budget: %.2f\n", total);
    printf("Average budget: %.2f\n", average);

    //Sorting budgets from lowest to highest

    for (int i = 0; i < 10 - 1; i++) {

        for (int j = 0; j < 10 - i - 1; j++) {

            if (budgets[j] > budgets[j + 1]) {

                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    //Display sorted budget

    printf("Budgets From Lowest To Highest\n");

    for (int i = 0; i < 10; i++) {
        printf("%.2f\n", budgets[i]);
    }

    return 0;
}