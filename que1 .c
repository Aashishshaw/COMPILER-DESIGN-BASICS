#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char keywords[32][10] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof",
    "static", "struct", "switch", "typedef", "union", "unsigned", "void",
    "volatile", "while"
};

// Check if string is a keyword
int isKeyword(char *str) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Check if character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || 
            ch == '=' || ch == '<' || ch == '>' || ch == '!');
}

// Check if character is a separator
int isSeparator(char ch) {
    return (ch == ' ' || ch == '\n' || ch == '\t' || ch == ';' || ch == ',' ||
            ch == '(' || ch == ')' || ch == '{' || ch == '}');
}

int main() {
    FILE *fp;
    char ch, buffer[100];
    int i = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n");

    while ((ch = fgetc(fp)) != EOF) {
        // Identifiers and numbers
        if (isalnum(ch) || ch == '_') {
            buffer[i++] = ch;
        } else {
            buffer[i] = '\0';
            i = 0;

            if (strlen(buffer) > 0) {
                if (isKeyword(buffer))
                    printf("[Keyword]     : %s\n", buffer);
                else if (isdigit(buffer[0]))
                    printf("[Number]      : %s\n", buffer);
                else
                    printf("[Identifier]  : %s\n", buffer);
            }

            // Handle multi-character operators
            if (isOperator(ch)) {
                char next = fgetc(fp);
                if ((ch == '=' || ch == '!' || ch == '<' || ch == '>') && next == '=') {
                    printf("[Operator]    : %c%c\n", ch, next);
                } else {
                    printf("[Operator]    : %c\n", ch);
                    ungetc(next, fp); // put back the character
                }
            } else if (!isSeparator(ch)) {
                printf("[Special Char]: %c\n", ch);
            }
        }
    }

    fclose(fp);
    return 0;
}
