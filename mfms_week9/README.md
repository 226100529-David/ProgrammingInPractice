# MFMS – Week 9: Modular Version

## Modules

| File | Responsibility | Functions |
|------|----------------|-----------|
| `main.c` | Main menu and program flow | `main()`, `displayMenu()` |
| `employees.c` / `employees.h` | Employee calculations | `calculateSalary()`, `searchEmployee()` |
| `budget.c` / `budget.h` | Budget calculations | `calculateVAT()`, `calculateBudget()` |
| `utilities.c` / `utilities.h` | Reusable helper functions | `displayWelcome()`, `readInt()`, `readFloat()`, `clearInputBuffer()`, `removeNewline()` |
| `reports.c` / `reports.h` | Reports (use the budget and employees modules) | `vatReport()`, `salaryReport()`, `budgetReport()` |
| `suppliers.c` / `suppliers.h` | Supplier management (from Week 7) | `addSupplier()`, `displaySupplier()`, `searchSupplier()` |

## How to build

Each source file is compiled separately into an object file (`-c`),
then the object files are linked into one executable:

```
gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c
gcc -std=c99 -Wall -Wextra -pedantic -c suppliers.c
gcc main.o employees.o budget.o utilities.o reports.o suppliers.o -o mfms
```