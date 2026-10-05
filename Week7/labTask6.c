#include <stdio.h>
#include <string.h>

int main() {

    // Declaring variables
    char supplierName[100];
    char supplierEmail[100];
    char supplierNumber[20];
    char SupplierTown[100];
    char searchSupplierName[100];

    int choice;

    // Supplier information

    do {

        printf("\n----------------------------\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("-----------------------------\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);
        getchar();

        if (choice == 1) {

            // Adding supplier

            printf("Enter Supplier Name: ");
            fgets(supplierName, sizeof(supplierName), stdin);
            supplierName[strcspn(supplierName, "\n")] = '\0';

            printf("Enter Supplier Email: ");
            fgets(supplierEmail, sizeof(supplierEmail), stdin);
            supplierEmail[strcspn(supplierEmail, "\n")] = '\0';

            printf("Enter Supplier Number: ");
            fgets(supplierNumber, sizeof(supplierNumber), stdin);
            supplierNumber[strcspn(supplierNumber, "\n")] = '\0';

            printf("Enter Supplier Town: ");
            fgets(SupplierTown, sizeof(SupplierTown), stdin);
            SupplierTown[strcspn(SupplierTown, "\n")] = '\0';

            printf("Supplier added successfully.\n");

        } else if (choice == 2) {

            // Displaying supplier information

            printf("\n-----SUPPLIER DETAILS-----\n");
            printf("Name: %s\n", supplierName);
            printf("Email: %s\n", supplierEmail);
            printf("Number: %s\n", supplierNumber);
            printf("Town: %s\n", SupplierTown);

        } else if (choice == 3) {

            // Searching for supplier

            printf("Enter Supplier Name to Search: ");
            fgets(searchSupplierName, sizeof(searchSupplierName), stdin);

            searchSupplierName[strcspn(searchSupplierName, "\n")] = '\0';

            if (strcmp(supplierName, searchSupplierName) == 0) {

                printf("Supplier found.\n");

            } else {

                printf("Supplier not found.\n");
            }

        } else if (choice == 4) {

            // Displaying supplier name length

            printf("Length of supplier name: %zu\n", strlen(supplierName));

        } else if (choice == 5) {

            printf("Goodbye.\n");

        } else {

            printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}