#include <stdio.h>
 
// Function prototype
int searchEmployee(int id, int ids[], int size);
 
int main() {
 
    // Declaring variables
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int size = 5;
    int employeeID;
    int position;
 
    // Get the employee ID from the user
    printf("Enter employee ID: ");
    scanf("%d", &employeeID);
 
    // Calling the function
    position = searchEmployee(employeeID, employeeIDs, size);
 
    // Displaying the result
    if (position != -1) {
        printf("Employee found at position %d.\n", position);
    } else {
        printf("Employee not found.\n");
    }
 
    return 0;
}
 
// Search the employee ID
int searchEmployee(int id, int ids[], int size) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;
        }
    }
 
    return -1;
}