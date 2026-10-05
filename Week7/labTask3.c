#include <stdio.h>
#include <string.h>

int main() {

    // Declaring variables
    char supplierName1[] = "ABC Office Supplies";
    char supplierName2[] = "Namibia Stationery";
    char searchSupplier[100];

    // Asking for supplier name to search

    printf("Enter Supplier Name to Search: ");
    fgets(searchSupplier, sizeof(searchSupplier), stdin);

    searchSupplier[strcspn(searchSupplier, "\n")] = '\0';

    // Searching for supplier

    if (strcmp(supplierName1, searchSupplier) == 0 ||
        strcmp(supplierName2, searchSupplier) == 0) {

        printf("Supplier found.\n");

    } else {

        printf("Supplier not found.\n");
    }

    return 0;
}