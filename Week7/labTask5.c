#include <stdio.h>
#include <string.h>

int main() {

    // Declaring variables

    char supplierName[100];
    char SupplierTown[100];
    char supplierDescription[200] = "";

    // Supplier information

    printf("Enter Supplier Name: ");
    fgets(supplierName, sizeof(supplierName), stdin);

    supplierName[strcspn(supplierName, "\n")] = '\0';

    printf("Enter Supplier Town: ");
    fgets(SupplierTown, sizeof(SupplierTown), stdin);

    SupplierTown[strcspn(SupplierTown, "\n")] = '\0';

    // Supplier description

    strcat(supplierDescription, supplierName);
    strcat(supplierDescription, " operates in ");
    strcat(supplierDescription, SupplierTown);
    strcat(supplierDescription, ".");

    // Display supplier description

    printf("%s\n", supplierDescription);

    return 0;
}