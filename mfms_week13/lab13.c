#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[30];
    double salary;
} Employee;


int main(void)
{
    int capacity = 2;
    int count = 0;
    int i;
    Employee *employees = NULL;
    Employee *bigger;
    Employee e;

    // TODO 1: room for 'capacity' employees
    employees = malloc(capacity * sizeof(Employee));

    if (employees == NULL)
    {
        printf("Out of memory!\n");
        return 1;
    }

    printf("Employee ID (0 to stop): ");
    scanf("%d", &e.id);

    while (e.id != 0)
    {
        printf("Name (one word): ");
        scanf("%29s", e.name);

        printf("Salary: ");
        scanf("%lf", &e.salary);

        // TODO 2: full? double the capacity with the temporary pointer
        if (count == capacity)
        {
            bigger = realloc(employees, capacity * 2 * sizeof(Employee));

            if (bigger == NULL)
            {
                printf("Out of memory!\n");
                free(employees);
                return 1;
            }

            employees = bigger;
            capacity = capacity * 2;

            printf("  (grown to %d slots)\n", capacity);
        }

        // TODO 3: store the employee, then add 1 to count
        employees[count] = e;
        count++;

        printf("Employee ID (0 to stop): ");
        scanf("%d", &e.id);
    }

    // TODO 4: display every employee, then the count and the capacity
    printf("\n");

    for (i = 0; i < count; i++)
    {
        printf("ID: %d | Name: %s | Salary: N$%.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].salary);
    }

    printf("Employees: %d | Capacity: %d\n", count, capacity);

    // TODO 5: give the memory back
    free(employees);
    employees = NULL;

    return 0;
}
