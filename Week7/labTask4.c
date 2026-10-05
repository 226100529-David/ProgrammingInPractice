#include <stdio.h>
#include <string.h>

int main() {

    // Declaring variables
    char supplierName[100];
    char backupSupplierName[100];

    // Supplier information

    printf("Enter Supplier Name: ");
    fgets(supplierName, sizeof(supplierName), stdin);

    supplierName[strcspn(supplierName, "\n")] = '\0';

    // Copying supplier name

    strcpy(backupSupplierName, supplierName);

    // Displaying supplier information

    printf("\n-----SUPPLIER INFORMATION-----\n");
    printf("Original Supplier Name: %s\n", supplierName);
    printf("Backup Supplier Name: %s\n", backupSupplierName);

    return 0;
}