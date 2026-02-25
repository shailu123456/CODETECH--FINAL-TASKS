#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to compress file using RLE
void compressFile() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("compressed.txt", "w");

    if (input == NULL || output == NULL) {
        printf("Error opening files!\n");
        return;
    }

    char ch, prev;
    int count = 1;

    prev = fgetc(input);

    while ((ch = fgetc(input)) != EOF) {
        if (ch == prev) {
            count++;
        } else {
            fprintf(output, "%c%d", prev, count);
            prev = ch;
            count = 1;
        }
    }

    fprintf(output, "%c%d", prev, count);

    fclose(input);
    fclose(output);

    printf("Compression completed ? compressed.txt\n");
}

// Function to decompress file
void decompressFile() {
    FILE *input = fopen("compressed.txt", "r");
    FILE *output = fopen("decompressed.txt", "w");

    if (input == NULL || output == NULL) {
        printf("Error opening files!\n");
        return;
    }

    char ch;
    int count;

    while ((ch = fgetc(input)) != EOF) {
        fscanf(input, "%d", &count);

        for (int i = 0; i < count; i++) {
            fputc(ch, output);
        }
    }

    fclose(input);
    fclose(output);

    printf("Decompression completed ? decompressed.txt\n");
}

int main() {
    int choice;

    printf("===== DATA COMPRESSION TOOL (RLE) =====\n");
    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            compressFile();
            break;
        case 2:
            decompressFile();
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

