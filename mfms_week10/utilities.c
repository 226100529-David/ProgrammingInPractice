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
    if (fgets(text, size, stdin) == NULL) {
        text[0] = '\0';
        return;
    }

    // If the text was too long, the rest of the line is still waiting: remove it
    if (strchr(text, '\n') == NULL) {
        clearInputBuffer();
    }

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

// Returns 1 if the file exists (it can be opened for reading), otherwise 0
int fileExists(char fileName[]) {

    // Declaring variables
    FILE *fp = fopen(fileName, "r");

    if (fp == NULL) {
        return 0;
    }

    fclose(fp);
    return 1;
}

// Returns 1 if the text can be saved in a data file:
// it must not be empty and must not contain the separator |
int isValidText(char text[]) {
    if (text[0] == '\0' || strchr(text, '|') != NULL) {
        return 0;
    }

    return 1;
}
