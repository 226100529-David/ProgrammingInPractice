#include <stdio.h> 
int main () {
    //Declaring variables
    double budjet = 5000.00;
    double price [10];
    char name [10] [50];
    int qualified [10];
    int registeredValid[10];
    int documentsValid[10];
    int preferedSupplier = -1;
    double lowestPrice = 0;

    // Ask information for 4 suppliers

    for(int i=0; i < 4; i++) { 
    //1.ask user to enter supplier name
     printf("Enter the name of the supplier");
     scanf("%49s", name[i]);

     //.2 ask user if registration is valid
     printf("Is the registration valid, 1=yes 0=no");
     scanf("%d", &registeredValid[i]);

     //3. aks if the documents are valid 
     printf("Are the documents Valid, 1=yes 0=no: ");
     scanf("%d", &documentsValid[i]);

     //4. ask for supplier pirce
     printf("What is the price of the supplier:");
     scanf("%lf", &price[i]);

     //5. Determine if the supplier is qualified 
     if (registeredValid[i]==1 && documentsValid[i]==1 && price[i] <=budjet){
    
      qualified[i] = 1;
      printf("Supplier is qualified\n");

      //Determine the prefered supplier
      if (preferedSupplier == -1 || price[i] < lowestPrice) {
         lowestPrice = price[i];
         preferedSupplier = i;

      }

   } else {
      qualified[i] = 0;
      printf("Supplier is Disqualified\n");

   }

}

//6. Display the prefered Supplier
if (preferedSupplier != -1) {

   printf("\nPrefered Supplier: %s\n" , name[preferedSupplier]);

}

return 0;

}