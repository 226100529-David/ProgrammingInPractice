#include <stdio.h>
#include <string.h>
int main() {

    // Declaring variables 
    char supplierName[100];
    char supplierEmail[100];
    char supplierNumber[20];
    char SupplierTown[100];

    // Supplier information 

    printf("Enter Supplier Name: ");
    fgets(supplierName, sizeof(supplierName), stdin);
    
    printf("Enter Supplier Email: ");
    fgets(supplierEmail, sizeof(supplierEmail), stdin);
   
    printf("Enter Supplier Number: ");
    fgets(supplierNumber, sizeof(supplierNumber), stdin);
   
    printf("Enter Supplier Town: ");
    fgets(SupplierTown, sizeof(SupplierTown), stdin);
    
    // Displaying supplier information
    printf("\n-----SUPPLIER DETAILS-----\n");
    printf("Name: %s\n", supplierName);
    printf("Email: %s\n", supplierEmail);
    printf("Number: %s\n", supplierNumber);
    printf("Town: %s\n", SupplierTown);

   
    return 0;
}