#include <stdio.h>

typedef struct
{
    int id;
    char name[30];
    double salary;
} Employee;


int main(void)
{
    Employee staff[3];

    printf("staff[0] is at %p\n", (void *)&staff[0]);
    printf("staff[1] is at %p\n", (void *)&staff[1]);
    printf("staff[2] is at %p\n", (void *)&staff[2]);

    printf("sizeof(Employee) = %zu\n", sizeof(Employee));

    return 0;
}
