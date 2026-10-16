#include <stdio.h>
#include <string.h>
#include "utilities.h"

// Displays the welcome message
void displayWelcome(void) {
    printf("Welcome to the Municipal Financial Management System\n");
}

// Displays a prompt and returns the whole number entered
int readInt(char prompt[]) {

    // Declaring variables
    int value = 0;

    printf("%s", prompt);
    scanf("%d", &value);
    clearInputBuffer();

    return value;
}

// Displays a prompt and returns the decimal number entered
float readFloat(char prompt[]) {

    // Declaring variables
    float value = 0;

    printf("%s", prompt);
    scanf("%f", &value);
    clearInputBuffer();

    return value;
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
