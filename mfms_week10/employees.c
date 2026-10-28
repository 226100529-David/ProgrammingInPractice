#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"
#include "config.h"

// Declaring employee records (shared by the employee functions in this file)
int employeeIDs[MAX_RECORDS];
char employeeNames[MAX_RECORDS][50];
float employeeSalaries[MAX_RECORDS];
int employeeCount = 0;

// Calculate the gross salary
float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

// Returns the position of the employee ID
int searchEmployee(int id, int ids[], int size) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;
        }
    }

    return -1;
}

// Adds an employee (the gross salary is calculated from the salary details)
void addEmployee(void) {

    // Declaring variables
    int id;
    char name[50];
    float basic;
    float housing;
    float transport;

    if (employeeCount == MAX_RECORDS) {
        printf("The employee list is full.\n");
        return;
    }

    printf("Enter Employee ID: ");
    id = readINT();

    if (searchEmployee(id, employeeIDs, employeeCount) != -1) {
        printf("An employee with ID %d already exists.\n", id);
        return;
    }

    printf("Enter Employee Name: ");
    readString(name, sizeof(name));

    if (isValidText(name) == 0) {
        printf("Invalid name: it cannot be empty or contain |.\n");
        return;
    }

    printf("Enter Basic Salary: ");
    basic = readFloat();
    printf("Enter Housing Allowance: ");
    housing = readFloat();
    printf("Enter Transport Allowance: ");
    transport = readFloat();

    // Storing the employee at the next free position
    employeeIDs[employeeCount] = id;
    strcpy(employeeNames[employeeCount], name);
    employeeSalaries[employeeCount] = calculateSalary(basic, housing, transport);

    printf("Employee added. Gross Salary: %.2f\n", employeeSalaries[employeeCount]);
    employeeCount++;
}

// Displays all the employees
void listEmployees(void) {
    if (employeeCount == 0) {
        printf("No employees yet.\n");
    } else {
        printf("\n-----EMPLOYEES-----\n");

        for (int i = 0; i < employeeCount; i++) {
            printf("ID: %d | Name: %s | Gross Salary: %.2f\n",
                   employeeIDs[i], employeeNames[i], employeeSalaries[i]);
        }

        printf("Total: %d employee(s)\n", employeeCount);
    }
}

// Asks for an employee ID and displays the employee if found
void findEmployee(void) {

    // Declaring variables
    int id;
    int position;

    printf("Enter Employee ID: ");
    id = readINT();

    position = searchEmployee(id, employeeIDs, employeeCount);

    if (position != -1) {
        printf("Employee found at position %d.\n", position);
        printf("ID: %d | Name: %s | Gross Salary: %.2f\n",
               employeeIDs[position], employeeNames[position], employeeSalaries[position]);
    } else {
        printf("Employee not found.\n");
    }
}

// Saves all the employees in the text file
// Format: one employee per line -> id|name|salary
void saveEmployees(void) {

    // Declaring variables
    FILE *fp = fopen(EMPLOYEES_FILE, "w");

    if (fp == NULL) {
        perror(EMPLOYEES_FILE);
        printf("Employees not saved (check that the data folder exists).\n");
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        fprintf(fp, "%d|%s|%.2f\n", employeeIDs[i], employeeNames[i], employeeSalaries[i]);
    }

    fclose(fp);
    printf("%d employee(s) saved to %s\n", employeeCount, EMPLOYEES_FILE);
}

// Loads the employees from the text file (replaces the employees in memory)
void loadEmployees(void) {

    // Declaring variables
    FILE *fp = fopen(EMPLOYEES_FILE, "r");
    int id;
    char name[50];
    float salary;
    int duplicates = 0;

    if (fp == NULL) {
        perror(EMPLOYEES_FILE);
        printf("No employees loaded.\n");
        return;
    }

    employeeCount = 0;

    // fscanf returns 3 when the id, the name and the salary of a line were read
    while (employeeCount < MAX_RECORDS &&
           fscanf(fp, "%d|%49[^|\n]|%f\n", &id, name, &salary) == 3) {

        if (searchEmployee(id, employeeIDs, employeeCount) != -1) {
            duplicates++;
        } else {
            employeeIDs[employeeCount] = id;
            strcpy(employeeNames[employeeCount], name);
            employeeSalaries[employeeCount] = salary;
            employeeCount++;
        }
    }

    // The loop stopped before the end of the file: a line is not in the right format
    if (employeeCount < MAX_RECORDS && feof(fp) == 0) {
        printf("Warning: a line in %s is not in the right format, loading stopped there.\n",
               EMPLOYEES_FILE);
    }

    if (duplicates > 0) {
        printf("Warning: %d employee(s) with a duplicate ID were skipped.\n", duplicates);
    }

    fclose(fp);
    printf("%d employee(s) loaded from %s\n", employeeCount, EMPLOYEES_FILE);
}

// Saves all the employees in the binary file
// Each record is written as raw bytes: id, then name (50 bytes), then salary
void saveEmployeesBinary(void) {

    // Declaring variables
    FILE *fp = fopen(EMPLOYEES_BINARY_FILE, "wb");
    size_t written;
    int saved = 0;

    if (fp == NULL) {
        perror(EMPLOYEES_BINARY_FILE);
        printf("Employees not saved in binary (check that the data folder exists).\n");
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        written = fwrite(&employeeIDs[i], sizeof(employeeIDs[i]), 1, fp);
        written = written + fwrite(employeeNames[i], sizeof(employeeNames[i]), 1, fp);
        written = written + fwrite(&employeeSalaries[i], sizeof(employeeSalaries[i]), 1, fp);

        // fwrite returns 1 when the item was written, so the 3 calls must give 3
        if (written != 3) {
            perror("Error writing employee");
            break;
        }

        saved++;
    }

    fclose(fp);
    printf("%d employee(s) saved to %s\n", saved, EMPLOYEES_BINARY_FILE);
}

// Loads the employees from the binary file (replaces the employees in memory)
void loadEmployeesBinary(void) {

    // Declaring variables
    FILE *fp = fopen(EMPLOYEES_BINARY_FILE, "rb");

    if (fp == NULL) {
        perror(EMPLOYEES_BINARY_FILE);
        printf("No employees loaded.\n");
        return;
    }

    employeeCount = 0;

    // fread returns 1 when the item was read; the loop stops at the end of the file
    while (employeeCount < MAX_RECORDS &&
           fread(&employeeIDs[employeeCount], sizeof(employeeIDs[0]), 1, fp) == 1) {

        if (fread(employeeNames[employeeCount], sizeof(employeeNames[0]), 1, fp) != 1 ||
            fread(&employeeSalaries[employeeCount], sizeof(employeeSalaries[0]), 1, fp) != 1) {
            printf("Warning: %s is incomplete, loading stopped there.\n", EMPLOYEES_BINARY_FILE);
            break;
        }

        // Makes sure the name always ends with '\0'
        employeeNames[employeeCount][49] = '\0';
        employeeCount++;
    }

    fclose(fp);
    printf("%d employee(s) loaded from %s\n", employeeCount, EMPLOYEES_BINARY_FILE);
}
