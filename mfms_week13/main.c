#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "records.h"


int addEmployee(Employee list[], int count);
void displayEmployees(Employee list[], int count);

int addSupplier(Supplier list[], int count);
void displaySuppliers(Supplier list[], int count);

int addAsset(Asset list[], int count);
void displayAssets(Asset list[], int count);

int addBudget(Budget list[], int count);
void displayBudgets(Budget list[], int count);

int addProject(Project list[], int count);
void displayProjects(Project list[], int count);

void saveEmployees(Employee list[], int count);
Employee *loadEmployees(Employee *list, int *count, int *capacity);

void suppliersInTown(Supplier list[], int count);
void assetsAbove(Asset list[], int count);
void projectsEndingIn(Project list[], int count);

Employee *findEmployee(Employee list[], int count, int id);
void updateSalary(Employee *e, double newSalary);
void updateEmployeeSalary(Employee list[], int count);

Employee *highestPaid(Employee list[], int count);
void showHighestPaid(Employee list[], int count);
void swapEmployees(Employee *a, Employee *b);
void sortEmployeesBySalary(Employee list[], int count);
void increaseBudget(Budget *b, double amount);
void increaseBudgetMenu(Budget list[], int count);

Employee *growEmployees(Employee *list, int *capacity, int needed);
void searchEmployee(Employee list[], int count);
int removeEmployee(Employee list[], int count);
Employee *shrinkToFit(Employee *list, int count, int *capacity);


int main(void)
{
    Employee *employees = NULL;
    Employee *bigger;
    Supplier suppliers[MAX_RECORDS];
    Asset assets[MAX_RECORDS];
    Budget budgets[MAX_RECORDS];
    Project projects[MAX_RECORDS];

    int employeeCount = 0;
    int employeeCapacity = 2;
    int supplierCount = 0;
    int assetCount = 0;
    int budgetCount = 0;
    int projectCount = 0;

    int choice;

    // Week 13: the employees are on the heap (calloc: the empty slots start at 0)
    employees = calloc(employeeCapacity, sizeof(Employee));

    if (employees == NULL)
    {
        printf("Out of memory!\n");
        return 1;
    }

    do
    {
        printf("\n--------------------------------\n");
        printf("          MFMS RECORDS\n");
        printf("--------------------------------\n");
        printf("Employees: %d (capacity %d), Suppliers: %d, Assets: %d, Budgets: %d, Projects: %d\n",
               employeeCount, employeeCapacity, supplierCount, assetCount, budgetCount, projectCount);
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Add Supplier\n");
        printf("4. Display Suppliers\n");
        printf("5. Add Asset\n");
        printf("6. Display Assets\n");
        printf("7. Add Budget\n");
        printf("8. Display Budgets\n");
        printf("9. Add Project\n");
        printf("10. Display Projects\n");
        printf("11. Save Employees\n");
        printf("12. Load Employees\n");
        printf("13. Suppliers in a Town\n");
        printf("14. Assets above a Value\n");
        printf("15. Projects ending in a Year\n");
        printf("16. Update Employee Salary\n");
        printf("17. Highest-Paid Employee\n");
        printf("18. Sort Employees by Salary\n");
        printf("19. Increase a Budget\n");
        printf("20. Search Employee by ID\n");
        printf("21. Remove Employee\n");
        printf("22. Shrink Employee List to Fit\n");
        printf("23. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Full? Make the list bigger first
                if (employeeCount == employeeCapacity)
                {
                    bigger = growEmployees(employees, &employeeCapacity, employeeCount + 1);

                    if (bigger == NULL)
                    {
                        printf("The employee was not added.\n");
                        break;
                    }

                    employees = bigger;
                }

                employeeCount = addEmployee(employees, employeeCount);
                break;

            case 2:
                displayEmployees(employees, employeeCount);
                break;

            case 3:
                supplierCount = addSupplier(suppliers, supplierCount);
                break;

            case 4:
                displaySuppliers(suppliers, supplierCount);
                break;

            case 5:
                assetCount = addAsset(assets, assetCount);
                break;

            case 6:
                displayAssets(assets, assetCount);
                break;

            case 7:
                budgetCount = addBudget(budgets, budgetCount);
                break;

            case 8:
                displayBudgets(budgets, budgetCount);
                break;

            case 9:
                projectCount = addProject(projects, projectCount);
                break;

            case 10:
                displayProjects(projects, projectCount);
                break;

            case 11:
                saveEmployees(employees, employeeCount);
                break;

            case 12:
                employees = loadEmployees(employees, &employeeCount, &employeeCapacity);
                break;

            case 13:
                suppliersInTown(suppliers, supplierCount);
                break;

            case 14:
                assetsAbove(assets, assetCount);
                break;

            case 15:
                projectsEndingIn(projects, projectCount);
                break;

            case 16:
                updateEmployeeSalary(employees, employeeCount);
                break;

            case 17:
                showHighestPaid(employees, employeeCount);
                break;

            case 18:
                sortEmployeesBySalary(employees, employeeCount);
                break;

            case 19:
                increaseBudgetMenu(budgets, budgetCount);
                break;

            case 20:
                searchEmployee(employees, employeeCount);
                break;

            case 21:
                employeeCount = removeEmployee(employees, employeeCount);
                break;

            case 22:
                employees = shrinkToFit(employees, employeeCount, &employeeCapacity);
                break;

            case 23:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 23);

    // Give the memory back before the program ends
    free(employees);
    employees = NULL;

    return 0;
}


// Employees

int addEmployee(Employee list[], int count)
{
    printf("ID: ");
    scanf("%d", &list[count].id);

    printf("Name (one word): ");
    scanf("%29s", list[count].name);

    printf("Department (one word): ");
    scanf("%19s", list[count].department);

    printf("Salary: ");
    scanf("%lf", &list[count].salary);

    printf("Employee added.\n");

    return count + 1;
}


void displayEmployees(Employee list[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo employee records.\n");
        return;
    }

    printf("\n--- EMPLOYEES ---\n");

    for (i = 0; i < count; i++)
    {
        printf("ID: %d | Name: %s | Department: %s | Salary: N$%.2f\n",
               list[i].id,
               list[i].name,
               list[i].department,
               list[i].salary);
    }
}


// Suppliers

int addSupplier(Supplier list[], int count)
{
    if (count >= MAX_RECORDS)
    {
        printf("The supplier list is full.\n");
        return count;
    }

    printf("ID: ");
    scanf("%d", &list[count].id);

    printf("Name (one word): ");
    scanf("%39s", list[count].name);

    printf("Email: ");
    scanf("%39s", list[count].email);

    printf("Phone: ");
    scanf("%14s", list[count].phone);

    printf("Town (one word): ");
    scanf("%19s", list[count].town);

    printf("Supplier added.\n");

    return count + 1;
}


void displaySuppliers(Supplier list[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo supplier records.\n");
        return;
    }

    printf("\n--- SUPPLIERS ---\n");

    for (i = 0; i < count; i++)
    {
        printf("ID: %d | Name: %s | Email: %s | Phone: %s | Town: %s\n",
               list[i].id,
               list[i].name,
               list[i].email,
               list[i].phone,
               list[i].town);
    }
}


// Assets

int addAsset(Asset list[], int count)
{
    if (count >= MAX_RECORDS)
    {
        printf("The asset list is full.\n");
        return count;
    }

    printf("ID: ");
    scanf("%d", &list[count].id);

    printf("Description (one word): ");
    scanf("%39s", list[count].description);

    printf("Value: ");
    scanf("%lf", &list[count].value);

    printf("Date acquired (day month year): ");
    scanf("%d %d %d", &list[count].acquired.day,
                      &list[count].acquired.month,
                      &list[count].acquired.year);

    printf("Asset added.\n");

    return count + 1;
}


void displayAssets(Asset list[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo asset records.\n");
        return;
    }

    printf("\n--- ASSETS ---\n");

    for (i = 0; i < count; i++)
    {
        printf("ID: %d | Description: %s | Value: N$%.2f | Acquired: %d/%d/%d\n",
               list[i].id,
               list[i].description,
               list[i].value,
               list[i].acquired.day,
               list[i].acquired.month,
               list[i].acquired.year);
    }
}


// Budgets

int addBudget(Budget list[], int count)
{
    if (count >= MAX_RECORDS)
    {
        printf("The budget list is full.\n");
        return count;
    }

    printf("Department (one word): ");
    scanf("%19s", list[count].department);

    printf("Allocated: ");
    scanf("%lf", &list[count].allocated);

    printf("Spent: ");
    scanf("%lf", &list[count].spent);

    printf("Budget added.\n");

    return count + 1;
}


void displayBudgets(Budget list[], int count)
{
    int i;
    double balance;

    if (count == 0)
    {
        printf("\nNo budget records.\n");
        return;
    }

    printf("\n--- BUDGETS ---\n");

    for (i = 0; i < count; i++)
    {
        balance = list[i].allocated - list[i].spent;

        printf("Department: %s | Allocated: N$%.2f | Spent: N$%.2f | Balance: N$%.2f\n",
               list[i].department,
               list[i].allocated,
               list[i].spent,
               balance);

        if (list[i].spent > list[i].allocated)
        {
            printf("WARNING: %s is over budget.\n", list[i].department);
        }
    }
}


// Projects

int addProject(Project list[], int count)
{
    if (count >= MAX_RECORDS)
    {
        printf("The project list is full.\n");
        return count;
    }

    printf("ID: ");
    scanf("%d", &list[count].id);

    printf("Title (one word): ");
    scanf("%39s", list[count].title);

    printf("Budget: ");
    scanf("%lf", &list[count].budget);

    printf("Start date (day month year): ");
    scanf("%d %d %d", &list[count].startDate.day,
                      &list[count].startDate.month,
                      &list[count].startDate.year);

    printf("End date (day month year): ");
    scanf("%d %d %d", &list[count].endDate.day,
                      &list[count].endDate.month,
                      &list[count].endDate.year);

    printf("Project added.\n");

    return count + 1;
}


void displayProjects(Project list[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo project records.\n");
        return;
    }

    printf("\n--- PROJECTS ---\n");

    for (i = 0; i < count; i++)
    {
        printf("ID: %d | Title: %s | Budget: N$%.2f | Start: %d/%d/%d | End: %d/%d/%d\n",
               list[i].id,
               list[i].title,
               list[i].budget,
               list[i].startDate.day,
               list[i].startDate.month,
               list[i].startDate.year,
               list[i].endDate.day,
               list[i].endDate.month,
               list[i].endDate.year);
    }
}


// Save and load employees (binary file)

void saveEmployees(Employee list[], int count)
{
    FILE *fp;

    fp = fopen("employees.dat", "wb");

    if (fp == NULL)
    {
        printf("Could not open employees.dat\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(list, sizeof(Employee), count, fp);

    fclose(fp);

    printf("%d employee(s) saved.\n", count);
}


Employee *loadEmployees(Employee *list, int *count, int *capacity)
{
    FILE *fp;
    int saved = 0;
    Employee *bigger;

    fp = fopen("employees.dat", "rb");

    if (fp == NULL)
    {
        printf("No saved employees yet.\n");
        return list;
    }

    if (fread(&saved, sizeof(int), 1, fp) != 1 || saved < 0)
    {
        printf("The file is damaged.\n");
        fclose(fp);
        return list;
    }

    // Not enough room? Make the list bigger first
    if (saved > *capacity)
    {
        bigger = growEmployees(list, capacity, saved);

        if (bigger == NULL)
        {
            printf("The employees were not loaded.\n");
            fclose(fp);
            return list;
        }

        list = bigger;
    }

    *count = fread(list, sizeof(Employee), saved, fp);

    fclose(fp);

    printf("%d employee(s) loaded.\n", *count);

    return list;
}


// Lab extensions

void suppliersInTown(Supplier list[], int count)
{
    int i;
    int found = 0;
    char town[20];

    printf("Town: ");
    scanf("%19s", town);

    for (i = 0; i < count; i++)
    {
        if (strcmp(list[i].town, town) == 0)
        {
            printf("ID: %d | Name: %s | Phone: %s\n",
                   list[i].id,
                   list[i].name,
                   list[i].phone);
            found++;
        }
    }

    if (found == 0)
    {
        printf("No supplier in %s.\n", town);
    }
}


void assetsAbove(Asset list[], int count)
{
    int i;
    int found = 0;
    double amount;

    printf("Show assets worth more than: ");
    scanf("%lf", &amount);

    for (i = 0; i < count; i++)
    {
        if (list[i].value > amount)
        {
            printf("ID: %d | Description: %s | Value: N$%.2f\n",
                   list[i].id,
                   list[i].description,
                   list[i].value);
            found++;
        }
    }

    if (found == 0)
    {
        printf("No asset worth more than N$%.2f.\n", amount);
    }
}


void projectsEndingIn(Project list[], int count)
{
    int i;
    int found = 0;
    int year;

    printf("Year: ");
    scanf("%d", &year);

    for (i = 0; i < count; i++)
    {
        if (list[i].endDate.year == year)
        {
            printf("ID: %d | Title: %s | End: %d/%d/%d\n",
                   list[i].id,
                   list[i].title,
                   list[i].endDate.day,
                   list[i].endDate.month,
                   list[i].endDate.year);
            found++;
        }
    }

    if (found == 0)
    {
        printf("No project ends in %d.\n", year);
    }
}


// Week 12: find and update an employee

Employee *findEmployee(Employee list[], int count, int id)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (list[i].id == id)
        {
            return &list[i];
        }
    }

    return NULL;
}


void updateSalary(Employee *e, double newSalary)
{
    e->salary = newSalary;
}


void updateEmployeeSalary(Employee list[], int count)
{
    int id;
    double newSalary;
    Employee *found;

    printf("Employee ID: ");
    scanf("%d", &id);

    found = findEmployee(list, count, id);

    if (found == NULL)
    {
        printf("No employee with ID %d.\n", id);
        return;
    }

    printf("New salary for %s: ", found->name);
    scanf("%lf", &newSalary);

    updateSalary(found, newSalary);

    printf("Updated: ID: %d | Name: %s | Department: %s | Salary: N$%.2f\n",
           found->id,
           found->name,
           found->department,
           found->salary);
}


// Week 12 lab extensions

Employee *highestPaid(Employee list[], int count)
{
    int i;
    Employee *best;

    if (count == 0)
    {
        return NULL;
    }

    best = &list[0];

    for (i = 1; i < count; i++)
    {
        if (list[i].salary > best->salary)
        {
            best = &list[i];
        }
    }

    return best;
}


void showHighestPaid(Employee list[], int count)
{
    Employee *top;

    top = highestPaid(list, count);

    if (top == NULL)
    {
        printf("\nNo employee records.\n");
        return;
    }

    printf("Highest paid: %s (%s) | Salary: N$%.2f\n",
           top->name,
           top->department,
           top->salary);
}


void swapEmployees(Employee *a, Employee *b)
{
    Employee temp;

    temp = *a;
    *a = *b;
    *b = temp;
}


void sortEmployeesBySalary(Employee list[], int count)
{
    int i;
    int j;

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - 1 - i; j++)
        {
            if (list[j].salary < list[j + 1].salary)
            {
                swapEmployees(&list[j], &list[j + 1]);
            }
        }
    }

    printf("Employees sorted by salary (highest first).\n");
    displayEmployees(list, count);
}


void increaseBudget(Budget *b, double amount)
{
    b->allocated = b->allocated + amount;
}


void increaseBudgetMenu(Budget list[], int count)
{
    int i;
    char department[20];
    double amount;

    printf("Department (one word): ");
    scanf("%19s", department);

    for (i = 0; i < count; i++)
    {
        if (strcmp(list[i].department, department) == 0)
        {
            printf("Amount to add: ");
            scanf("%lf", &amount);

            increaseBudget(&list[i], amount);

            printf("%s now has N$%.2f allocated.\n",
                   list[i].department,
                   list[i].allocated);
            return;
        }
    }

    printf("No budget for %s.\n", department);
}


// Week 13: the employee list grows and shrinks on the heap

Employee *growEmployees(Employee *list, int *capacity, int needed)
{
    Employee *bigger;
    int newCapacity = *capacity;

    while (newCapacity < needed)
    {
        newCapacity = newCapacity * 2;
    }

    // Temporary pointer: if realloc fails, list is still valid
    bigger = realloc(list, newCapacity * sizeof(Employee));

    if (bigger == NULL)
    {
        printf("Out of memory!\n");
        return NULL;
    }

    *capacity = newCapacity;

    printf("(grown to %d slots)\n", *capacity);

    return bigger;
}


void searchEmployee(Employee list[], int count)
{
    int id;
    Employee *found;

    printf("Employee ID: ");
    scanf("%d", &id);

    found = findEmployee(list, count, id);

    if (found == NULL)
    {
        printf("Employee %d not found.\n", id);
        return;
    }

    printf("Found: ID: %d | Name: %s | Department: %s | Salary: N$%.2f\n",
           found->id,
           found->name,
           found->department,
           found->salary);
}


// Week 13 lab extensions

int removeEmployee(Employee list[], int count)
{
    int i;
    int id;
    int position = -1;

    printf("Employee ID to remove: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (list[i].id == id)
        {
            position = i;
            break;
        }
    }

    if (position == -1)
    {
        printf("Employee %d not found.\n", id);
        return count;
    }

    // Shift the others down to close the gap
    for (i = position; i < count - 1; i++)
    {
        list[i] = list[i + 1];
    }

    printf("Employee %d removed.\n", id);

    return count - 1;
}


Employee *shrinkToFit(Employee *list, int count, int *capacity)
{
    Employee *smaller;

    if (count == 0)
    {
        printf("No employees: nothing to shrink.\n");
        return list;
    }

    if (count == *capacity)
    {
        printf("The list is already full: capacity %d.\n", *capacity);
        return list;
    }

    smaller = realloc(list, count * sizeof(Employee));

    if (smaller == NULL)
    {
        printf("Could not shrink the list. Nothing changed.\n");
        return list;
    }

    *capacity = count;

    printf("Capacity reduced to %d.\n", *capacity);

    return smaller;
}
