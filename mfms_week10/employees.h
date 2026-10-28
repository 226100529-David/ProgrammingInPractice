#ifndef EMPLOYEES_H
#define EMPLOYEES_H

float calculateSalary(float basic, float housing, float transport);
int searchEmployee(int id, int ids[], int size);

void addEmployee(void);
void listEmployees(void);
void findEmployee(void);

void saveEmployees(void);
void loadEmployees(void);
void saveEmployeesBinary(void);
void loadEmployeesBinary(void);

#endif
