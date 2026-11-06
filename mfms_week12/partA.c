#include <stdio.h>

int main(void)
{
    int budgetCode = 7;
    int *p = &budgetCode;

    printf("Value: %d\n", budgetCode);
    printf("Address: %p\n", (void *)&budgetCode);
    printf("*p: %d\n", *p);

    // Change the value through the pointer
    *p = 9;

    printf("\nAfter *p = 9, budgetCode = %d\n", budgetCode);

    return 0;
}
