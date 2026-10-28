#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "utilities.h"
#include "config.h"

// Declaring asset records (shared by the asset functions in this file)
int assetIDs[MAX_RECORDS];
char assetNames[MAX_RECORDS][50];
float assetValues[MAX_RECORDS];
int assetCount = 0;

// Returns the position of the asset ID, or -1 if not found
int searchAsset(int id) {
    for (int i = 0; i < assetCount; i++) {
        if (assetIDs[i] == id) {
            return i;
        }
    }

    return -1;
}

// Adds an asset of the municipality (for example a vehicle or a building)
void addAsset(void) {

    // Declaring variables
    int id;
    char name[50];
    float value;

    if (assetCount == MAX_RECORDS) {
        printf("The asset list is full.\n");
        return;
    }

    printf("Enter Asset ID: ");
    id = readINT();

    if (searchAsset(id) != -1) {
        printf("An asset with ID %d already exists.\n", id);
        return;
    }

    printf("Enter Asset Name: ");
    readString(name, sizeof(name));

    if (isValidText(name) == 0) {
        printf("Invalid name: it cannot be empty or contain |.\n");
        return;
    }

    printf("Enter Asset Value: ");
    value = readFloat();

    // Storing the asset at the next free position
    assetIDs[assetCount] = id;
    strcpy(assetNames[assetCount], name);
    assetValues[assetCount] = value;
    assetCount++;

    printf("Asset added.\n");
}

// Displays all the assets and their total value
void listAssets(void) {

    // Declaring variables
    float totalValue = 0;

    if (assetCount == 0) {
        printf("No assets yet.\n");
    } else {
        printf("\n-----ASSETS-----\n");

        for (int i = 0; i < assetCount; i++) {
            printf("ID: %d | Name: %s | Value: %.2f\n", assetIDs[i], assetNames[i], assetValues[i]);
            totalValue = totalValue + assetValues[i];
        }

        printf("Total: %d asset(s) | Total Value: %.2f\n", assetCount, totalValue);
    }
}

// Saves all the assets in the text file
// Format: one asset per line -> id|name|value
void saveAssets(void) {

    // Declaring variables
    FILE *fp = fopen(ASSETS_FILE, "w");

    if (fp == NULL) {
        perror(ASSETS_FILE);
        printf("Assets not saved (check that the data folder exists).\n");
        return;
    }

    for (int i = 0; i < assetCount; i++) {
        fprintf(fp, "%d|%s|%.2f\n", assetIDs[i], assetNames[i], assetValues[i]);
    }

    fclose(fp);
    printf("%d asset(s) saved to %s\n", assetCount, ASSETS_FILE);
}

// Loads the assets from the text file (replaces the assets in memory)
void loadAssets(void) {

    // Declaring variables
    FILE *fp = fopen(ASSETS_FILE, "r");
    int id;
    char name[50];
    float value;
    int duplicates = 0;

    if (fp == NULL) {
        perror(ASSETS_FILE);
        printf("No assets loaded.\n");
        return;
    }

    assetCount = 0;

    // fscanf returns 3 when the id, the name and the value of a line were read
    while (assetCount < MAX_RECORDS &&
           fscanf(fp, "%d|%49[^|\n]|%f\n", &id, name, &value) == 3) {

        if (searchAsset(id) != -1) {
            duplicates++;
        } else {
            assetIDs[assetCount] = id;
            strcpy(assetNames[assetCount], name);
            assetValues[assetCount] = value;
            assetCount++;
        }
    }

    // The loop stopped before the end of the file: a line is not in the right format
    if (assetCount < MAX_RECORDS && feof(fp) == 0) {
        printf("Warning: a line in %s is not in the right format, loading stopped there.\n",
               ASSETS_FILE);
    }

    if (duplicates > 0) {
        printf("Warning: %d asset(s) with a duplicate ID were skipped.\n", duplicates);
    }

    fclose(fp);
    printf("%d asset(s) loaded from %s\n", assetCount, ASSETS_FILE);
}
