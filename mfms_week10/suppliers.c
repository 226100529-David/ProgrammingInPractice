#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utilities.h"
#include "config.h"

// Declaring supplier records (shared by the supplier functions in this file)
char supplierNames[MAX_RECORDS][100];
char supplierEmails[MAX_RECORDS][100];
char supplierNumbers[MAX_RECORDS][20];
char supplierTowns[MAX_RECORDS][100];
int supplierCount = 0;

// Add the supplier information
void addSupplier(void) {

    if (supplierCount == MAX_RECORDS) {
        printf("The supplier list is full.\n");
        return;
    }

    // Supplier information (stored at the next free position)
    printf("Enter Supplier Name: ");
    readString(supplierNames[supplierCount], sizeof(supplierNames[supplierCount]));

    printf("Enter Supplier Email: ");
    readString(supplierEmails[supplierCount], sizeof(supplierEmails[supplierCount]));

    printf("Enter Supplier Number: ");
    readString(supplierNumbers[supplierCount], sizeof(supplierNumbers[supplierCount]));

    printf("Enter Supplier Town: ");
    readString(supplierTowns[supplierCount], sizeof(supplierTowns[supplierCount]));

    if (isValidText(supplierNames[supplierCount]) == 0 ||
        isValidText(supplierEmails[supplierCount]) == 0 ||
        isValidText(supplierNumbers[supplierCount]) == 0 ||
        isValidText(supplierTowns[supplierCount]) == 0) {
        printf("Supplier not added: a field is empty or contains |.\n");
    } else {
        supplierCount++;
        printf("Supplier added.\n");
    }
}

// Displays the supplier at the given position
void displaySupplier(int position) {
    printf("\n-----SUPPLIER DETAILS-----\n");
    printf("Name: %s\n", supplierNames[position]);
    printf("Email: %s\n", supplierEmails[position]);
    printf("Number: %s\n", supplierNumbers[position]);
    printf("Town: %s\n", supplierTowns[position]);
}

// Displays all the suppliers
void listSuppliers(void) {
    if (supplierCount == 0) {
        printf("No supplier added yet.\n");
    } else {
        for (int i = 0; i < supplierCount; i++) {
            displaySupplier(i);
        }

        printf("Total: %d supplier(s)\n", supplierCount);
    }
}

// Searches for a supplier by name
void searchSupplier(void) {

    // Declaring variables
    char searchName[100];
    int found = 0;

    if (supplierCount == 0) {
        printf("No supplier added yet.\n");
    } else {
        printf("Enter Supplier Name To Search: ");
        readString(searchName, sizeof(searchName));

        for (int i = 0; i < supplierCount; i++) {
            if (strcmp(supplierNames[i], searchName) == 0) {
                printf("Supplier found.\n");
                displaySupplier(i);
                found = 1;
            }
        }

        if (found == 0) {
            printf("Supplier not found.\n");
        }
    }
}

// Saves all the suppliers in the text file
// Format: one supplier per line -> name|email|number|town
void saveSuppliers(void) {

    // Declaring variables
    FILE *fp = fopen(SUPPLIERS_FILE, "w");

    if (fp == NULL) {
        perror(SUPPLIERS_FILE);
        printf("Suppliers not saved (check that the data folder exists).\n");
        return;
    }

    for (int i = 0; i < supplierCount; i++) {
        fprintf(fp, "%s|%s|%s|%s\n",
                supplierNames[i], supplierEmails[i], supplierNumbers[i], supplierTowns[i]);
    }

    fclose(fp);
    printf("%d supplier(s) saved to %s\n", supplierCount, SUPPLIERS_FILE);
}

// Loads the suppliers from the text file (replaces the suppliers in memory)
void loadSuppliers(void) {

    // Declaring variables
    FILE *fp = fopen(SUPPLIERS_FILE, "r");

    if (fp == NULL) {
        perror(SUPPLIERS_FILE);
        printf("No suppliers loaded.\n");
        return;
    }

    supplierCount = 0;

    // fscanf returns 4 when the 4 fields of a line were read
    while (supplierCount < MAX_RECORDS &&
           fscanf(fp, "%99[^|\n]|%99[^|\n]|%19[^|\n]|%99[^\n]\n",
                  supplierNames[supplierCount], supplierEmails[supplierCount],
                  supplierNumbers[supplierCount], supplierTowns[supplierCount]) == 4) {
        supplierCount++;
    }

    // The loop stopped before the end of the file: a line is not in the right format
    if (supplierCount < MAX_RECORDS && feof(fp) == 0) {
        printf("Warning: a line in %s is not in the right format, loading stopped there.\n",
               SUPPLIERS_FILE);
    }

    fclose(fp);
    printf("%d supplier(s) loaded from %s\n", supplierCount, SUPPLIERS_FILE);
}
