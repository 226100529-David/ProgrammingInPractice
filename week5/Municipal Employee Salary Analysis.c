#include <stdio.h>

int main() {

    //Declaring variable

    float salary;
    float total = 0;
    float highest = 0;
    float lowest = 0;
    float average;

    //Capture the salary of each employee

    for (int i = 1; i <= 50; i++) {

        printf("Enter salary for employee %d: ", i);
        scanf("%f", &salary);

    // Calculate the total salary
        
        total = total + salary;

        if (i == 1) {
            highest = salary;
            lowest = salary;
        }
    //Determine the highest salary
        if (salary > highest) {
            highest = salary;
        }
    //Determine the lowest salary
        if (salary < lowest) {
            lowest = salary;
        }
    }

    //Calculate the average salary

    average = total / 50;
    //Display the result
    printf("\n--- Salary Report ---\n");
    printf("Total salary: %.2f\n", total);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);

    return 0;
}