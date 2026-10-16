#include "employees.h"

// Calculate the gross salary
float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

// Returns the position of the employee ID
int searchEmployee(int id, int ids[], int size) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;
        }
    }

    return -1;
}
