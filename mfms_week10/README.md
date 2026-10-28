# MFMS – Week 10: Persistent Storage

## Modules

| File | Responsibility | Functions |
|------|----------------|-----------|
| `main.c` | Main menu, program flow, Save Data / Load Data | `main()`, `displayMenu()`, `saveData()`, `loadData()`, `savedDataExists()` |
| `employees.c` / `employees.h` | Employee records | `calculateSalary()`, `searchEmployee()`, `addEmployee()`, `listEmployees()`, `findEmployee()`, `saveEmployees()`, `loadEmployees()`, `saveEmployeesBinary()`, `loadEmployeesBinary()` |
| `suppliers.c` / `suppliers.h` | Supplier records | `addSupplier()`, `displaySupplier()`, `listSuppliers()`, `searchSupplier()`, `saveSuppliers()`, `loadSuppliers()` |
| `assets.c` / `assets.h` | Asset records | `searchAsset()`, `addAsset()`, `listAssets()`, `saveAssets()`, `loadAssets()` |
| `budget.c` / `budget.h` | VAT and budget calculations, budget records | `calculateVAT()`, `calculateBudget()`, `addBudget()`, `listBudgets()`, `saveBudgets()`, `loadBudgets()` |
| `reports.c` / `reports.h` | Reports (use the budget and employees modules) | `vatReport()`, `salaryReport()`, `budgetReport()` |
| `utilities.c` / `utilities.h` | Reusable helper functions | `displayWelcome()`, `readINT()`, `readDouble()`, `readFloat()`, `readString()`, `clearInputBuffer()`, `removeNewline()`, `fileExists()`, `isValidText()` |
| `config.h` | Shared constants | `MAX_RECORDS`, names of the data files |

## Data files

The records are saved in the `data` folder, so the program must be run from the `mfms_week10` folder.
Each text file has one record per line, with the fields separated by `|`:

- `data/employees.txt`: `id|name|grossSalary`
- `data/suppliers.txt`: `name|email|number|town`
- `data/assets.txt`: `id|name|value`
- `data/budgets.txt`: `department|revenue|expenses`
- `data/employees.dat` (binary): id (4 bytes), name (50 bytes), salary (4 bytes), so 58 bytes per employee

Because `|` separates the fields, it is not accepted inside a name.
"Save Data" rewrites the files (mode `"w"`). If saved data exists and has not been loaded yet, the program asks for confirmation first.

## Text vs binary

- `employees.txt` can be opened and read in Notepad. `employees.dat` shows unreadable characters (only the names can be read).
- In the text file each line has a different length (it depends on the name and the number of digits). In the binary file every employee takes exactly 58 bytes.
- The text file needs `fprintf()` / `fscanf()` to turn the numbers into characters and back. The binary file uses `fwrite()` / `fread()` to copy the bytes straight from memory.
- The text file is easy to check and correct by hand. The binary file depends on the computer (size of `int` and `float`), so it is less portable.

## How to build

```
gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c
gcc -std=c99 -Wall -Wextra -pedantic -c suppliers.c
gcc -std=c99 -Wall -Wextra -pedantic -c assets.c
gcc main.o employees.o budget.o utilities.o reports.o suppliers.o assets.o -o mfms
```
