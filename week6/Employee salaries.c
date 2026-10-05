#include <stdio.h>

int main() {

    //Declaring variables

    float salaries[50];
    float total = 0;
    float average;
    float highest;
    float lowest;
    float searchSalary;
    int found = 0;

    //Capture 50 salaries

    for (int i = 0; i < 50; i++) {

        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);

        total = total + salaries[i];

        if (i == 0) {
            highest = salaries[i];
            lowest = salaries[i];
        }

        if (salaries[i] > highest) {
            highest = salaries[i];
        }

        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }

    //Calculate the average

    average = total / 50;

    //Display all salaries

    printf("Employee Salaries\n");

    for (int i = 0; i < 50; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    

    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);

    //Search for salary

    printf("Enter a salary to search:\n");
    scanf("%f", &searchSalary);

    for (int i = 0; i < 50; i++) {

        if (salaries[i] == searchSalary) {
            printf("Salary found at employee %d.\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Salary not found.\n");
    }

    return 0;
}