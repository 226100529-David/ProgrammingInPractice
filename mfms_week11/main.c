#include <stdio.h>
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
int loadEmployees(Employee list[]);

void suppliersInTown(Supplier list[], int count);
void assetsAbove(Asset list[], int count);
void projectsEndingIn(Project list[], int count);


int main(void)
{
    Employee employees[MAX_RECORDS];
    Supplier suppliers[MAX_RECORDS];
    Asset assets[MAX_RECORDS];
    Budget budgets[MAX_RECORDS];
    Project projects[MAX_RECORDS];

    int employeeCount = 0;
    int supplierCount = 0;
    int assetCount = 0;
    int budgetCount = 0;
    int projectCount = 0;

    int choice;

    do
    {
        printf("\n--------------------------------\n");
        printf("          MFMS RECORDS\n");
        printf("--------------------------------\n");
        printf("Employees: %d, Suppliers: %d, Assets: %d, Budgets: %d, Projects: %d\n",
               employeeCount, supplierCount, assetCount, budgetCount, projectCount);
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
        printf("16. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
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
                employeeCount = loadEmployees(employees);
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
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 16);

    return 0;
}


// Employees

int addEmployee(Employee list[], int count)
{
    if (count >= MAX_RECORDS)
    {
        printf("The employee list is full.\n");
        return count;
    }

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


int loadEmployees(Employee list[])
{
    FILE *fp;
    int count = 0;

    fp = fopen("employees.dat", "rb");

    if (fp == NULL)
    {
        printf("No saved employees yet.\n");
        return 0;
    }

    if (fread(&count, sizeof(int), 1, fp) != 1 || count < 0 || count > MAX_RECORDS)
    {
        printf("The file is damaged.\n");
        fclose(fp);
        return 0;
    }

    count = fread(list, sizeof(Employee), count, fp);

    fclose(fp);

    printf("%d employee(s) loaded.\n", count);

    return count;
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
