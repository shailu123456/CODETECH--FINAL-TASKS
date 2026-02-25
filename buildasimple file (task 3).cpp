#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char *keywords[] = {
    "int", "float", "char", "double", "if", "else",
    "while", "for", "return", "void", "break", "continue"
};

int isKeyword(char buffer[]) {
    int size = sizeof(keywords) / sizeof(keywords[0]);
    int i;

    for(i = 0; i < size; i++) {
        if(strcmp(buffer, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[1000];
    char buffer[MAX];
    int i = 0, j = 0;

    printf("Enter a C statement:\n");
    fgets(input, sizeof(input), stdin);

    printf("\nLexical Analysis Output:\n\n");

    while(input[i] != '\0') {

        // IDENTIFIERS & KEYWORDS
        if(isalpha(input[i]) || input[i] == '_') {
            j = 0;

            while(isalnum(input[i]) || input[i] == '_') {
                if(j < MAX - 1)
                    buffer[j++] = input[i];
                i++;
            }

            buffer[j] = '\0';

            if(isKeyword(buffer))
                printf("Keyword: %s\n", buffer);
            else
                printf("Identifier: %s\n", buffer);
        }

        // NUMBERS
        else if(isdigit(input[i])) {
            j = 0;

            while(isdigit(input[i])) {
                if(j < MAX - 1)
                    buffer[j++] = input[i];
                i++;
            }

            buffer[j] = '\0';
            printf("Number: %s\n", buffer);
        }

        // OPERATORS
        else if(input[i] == '+' || input[i] == '-' ||
                input[i] == '*' || input[i] == '/' ||
                input[i] == '=' || input[i] == '<' ||
                input[i] == '>') {
            printf("Operator: %c\n", input[i]);
            i++;
        }

        // SPECIAL SYMBOLS
        else if(input[i] == ';' || input[i] == ',' ||
                input[i] == '(' || input[i] == ')' ||
                input[i] == '{' || input[i] == '}') {
            printf("Special Symbol: %c\n", input[i]);
            i++;
        }

        else {
            i++;
        }
    }

    return 0;
}



