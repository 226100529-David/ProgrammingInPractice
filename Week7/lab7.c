#include <stdio.h>
#include <string.h>

int main() {

    // Declaring variables
    char supplierName[5][100];
    char supplierEmail[5][100];
    char supplierNumber[5][20];
    char SupplierTown[5][100];

    char searchSupplierName[100];

    int found = 0;

    // Supplier information

    for (int i = 0; i < 5; i++) {

        printf("SUPPLIER %d\n", i + 1);

        printf("Enter Supplier Name: ");
        fgets(supplierName[i], sizeof(supplierName[i]), stdin);
        supplierName[i][strcspn(supplierName[i], "\n")] = '\0';

        printf("Enter Supplier Email: ");
        fgets(supplierEmail[i], sizeof(supplierEmail[i]), stdin);
        supplierEmail[i][strcspn(supplierEmail[i], "\n")] = '\0';

        printf("Enter Supplier Number: ");
        fgets(supplierNumber[i], sizeof(supplierNumber[i]), stdin);
        supplierNumber[i][strcspn(supplierNumber[i], "\n")] = '\0';

        printf("Enter Supplier Town: ");
        fgets(SupplierTown[i], sizeof(SupplierTown[i]), stdin);
        SupplierTown[i][strcspn(SupplierTown[i], "\n")] = '\0';
    }

    // Searching for supplier

    printf("Enter Supplier Name to Search:\n ");
    fgets(searchSupplierName, sizeof(searchSupplierName), stdin);

    searchSupplierName[strcspn(searchSupplierName, "\n")] = '\0';

    for (int i = 0; i < 5; i++) {

        if (strcmp(supplierName[i], searchSupplierName) == 0) {

            printf("\nSupplier found.\n");

            printf("Name: %s\n", supplierName[i]);
            printf("Email: %s\n", supplierEmail[i]);
            printf("Number: %s\n", supplierNumber[i]);
            printf("Town: %s\n", SupplierTown[i]);

            found = 1;
            break;
        }
    }

    if (found == 0) {

        printf("Supplier not found\n");
    }

    return 0;
}