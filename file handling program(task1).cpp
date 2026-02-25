#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char data[100];

    // 1. Create and Write to file
    fp = fopen("sample.txt", "w");   // "w" mode creates file
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter text to write into file: ");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);

    printf("\nData written successfully.\n");

    // 2. Append data to file
    fp = fopen("sample.txt", "a");   // "a" mode for append
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter text to append: ");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);

    printf("Data appended successfully.\n");

    // 3. Read from file
    fp = fopen("sample.txt", "r");   // "r" mode for read
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("\nReading data from file:\n");
    while (fgets(data, sizeof(data), fp) != NULL) {
        printf("%s", data);
    }

    fclose(fp);

    return 0;
}

