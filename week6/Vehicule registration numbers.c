#include <stdio.h>
#include <string.h>

int main() {

    //Declaring variables

    char registrations[20][20];
    char searchRegistration[20];
    int found = 0;

    //Capture registration numbers

    for (int i = 0; i < 20; i++) {

        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    //Display registration numbers

    printf("Vehicle Registrations\n");

    for (int i = 0; i < 20; i++) {
        printf("Vehicle %d: %s\n", i + 1, registrations[i]);
    }

    //Searching registration number

    printf("Enter a registration number to search:\n ");
    scanf("%19s", searchRegistration);

    for (int i = 0; i < 20; i++) {

        if (strcmp(registrations[i], searchRegistration) == 0) {

            printf("Registration found %d.\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Registration not found\n");
    }

    return 0;
}