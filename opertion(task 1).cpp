#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int choice;
    char data[200];
    char filename[] = "file.txt";

    while (1) {
        printf("\n===== FILE OPERATIONS MENU =====\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read from File\n");
        printf("4. Append to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();   // clear newline

        switch (choice) {

        case 1:
            fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("Error creating file!\n");
                break;
            }
            printf("File created successfully.\n");
            fclose(fp);
            break;

        case 2:
            fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("Error opening file!\n");
                break;
            }
            printf("Enter text to write: ");
            fgets(data, sizeof(data), stdin);
            fputs(data, fp);
            printf("Data written successfully.\n");
            fclose(fp);
            break;

        case 3:
            fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("File not found!\n");
                break;
            }
            printf("\n--- File Contents ---\n");
            while (fgets(data, sizeof(data), fp) != NULL) {
                printf("%s", data);
            }
            fclose(fp);
            break;

        case 4:
            fp = fopen(filename, "a");
            if (fp == NULL) {
                printf("Error opening file!\n");
                break;
            }
            printf("Enter text to append: ");
            fgets(data, sizeof(data), stdin);
            fputs(data, fp);
            printf("Data appended successfully.\n");
            fclose(fp);
            break;

        case 5:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

