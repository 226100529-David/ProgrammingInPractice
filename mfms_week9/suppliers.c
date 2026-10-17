#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utilities.h"

// Declaring supplier variables 
char supplierName[100];
char supplierEmail[100];
char supplierNumber[20];
char supplierTown[100];
int supplierAdded = 0;

// Add the supplier information
void addSupplier(void) {

    // Supplier information
    printf("Enter Supplier Name: ");
    readString(supplierName, sizeof(supplierName));

    printf("Enter Supplier Email: ");
    readString(supplierEmail, sizeof(supplierEmail));

    printf("Enter Supplier Number: ");
    readString(supplierNumber, sizeof(supplierNumber));

    printf("Enter Supplier Town: ");
    readString(supplierTown, sizeof(supplierTown));

    supplierAdded = 1;
    printf("Supplier added.\n");
}

// Displays the supplier information
void displaySupplier(void) {
    if (supplierAdded == 0) {
        printf("No supplier added yet.\n");
    } else {
        // Displaying supplier information
        printf("\n-----SUPPLIER DETAILS-----\n");
        printf("Name: %s\n", supplierName);
        printf("Email: %s\n", supplierEmail);
        printf("Number: %s\n", supplierNumber);
        printf("Town: %s\n", supplierTown);
    }
}

// Searches for the supplier by name
void searchSupplier(void) {

    // Declaring variables
    char searchName[100];

    if (supplierAdded == 0) {
        printf("No supplier added yet.\n");
    } else {
        printf("Enter Supplier Name To Search: ");
        readString(searchName, sizeof(searchName));

        if (strcmp(supplierName, searchName) == 0) {
            printf("Supplier found.\n");
            displaySupplier();
        } else {
            printf("Supplier not found.\n");
        }
    }
}
