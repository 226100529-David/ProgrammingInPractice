#include <stdio.h>
#include <string.h>
#include "utilities.h"

// Displays the welcome message
void displayWelcome(void) {
    printf("Welcome to the Municipal Financial Management System\n");
}

// Returns the whole number entered
int readINT(void) {

    // Declaring variables
    int num = 0;

    scanf("%d", &num);
    clearInputBuffer();

    return num;
}

// Returns the decimal number entered (double)
double readDouble(void) {

    // Declaring variables
    double num = 0;

    scanf("%lf", &num);
    clearInputBuffer();

    return num;
}

// Returns the decimal number entered (float)
float readFloat(void) {

    // Declaring variables
    float num = 0;

    scanf("%f", &num);
    clearInputBuffer();

    return num;
}

// Reads the text entered and removes the Enter at the end
void readString(char text[], int size) {
    fgets(text, size, stdin);
    removeNewline(text);
}


void clearInputBuffer(void) {

    // Declaring variables
    int character;

    do {
        character = getchar();
    } while (character != '\n' && character != EOF);
}


void removeNewline(char text[]) {
    text[strcspn(text, "\n")] = '\0';
}
