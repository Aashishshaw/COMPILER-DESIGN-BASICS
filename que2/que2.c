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

// Check if a string is a keyword
int isKeyword(char *str) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>' || ch == '!');
}

// Check if a character is a separator or special character
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
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n\n");

    while ((ch = fgetc(fp)) != EOF) {
        // Group alphanumeric and underscore into buffer
        if (isalnum(ch) || ch == '_') {
            buffer[i++] = ch;
        } else {
            buffer[i] = '\0';
            i = 0;

            // Process buffer if it contains a word
            if (strlen(buffer) > 0) {
                if (isKeyword(buffer))
                    printf("[Keyword]     : %s\n", buffer);
                else if (isdigit(buffer[0]))
                    printf("[Number]      : %s\n", buffer);
                else
                    printf("[Identifier]  : %s\n", buffer);
            }

            // Check for multi-character operators
            if (isOperator(ch)) {
                char next = fgetc(fp);
                if (next == '=') {
                    printf("[Operator]    : %c%c\n", ch, next);
                } else {
                    printf("[Operator]    : %c\n", ch);
                    ungetc(next, fp); // Put back the non-operator char
                }
            } else if (!isSeparator(ch) && ch != ' ' && ch != '\n') {
                printf("[Special Char]: %c\n", ch);
            }
        }
    }

    fclose(fp);
    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  # sample output :

  Lexical Analysis Output:

[Keyword]     : int
[Identifier]  : main
[Special Char]: (
[Special Char]: )
[Special Char]: {
[Keyword]     : int
[Identifier]  : x
[Operator]    : =
[Number]      : 10
[Special Char]: ;
[Keyword]     : float
[Identifier]  : y
[Operator]    : =
[Identifier]  : x
[Operator]    : +
[Number]      : 3
[Special Char]: .
[Number]      : 5
[Special Char]: ;
[Keyword]     : if
[Special Char]: (
[Identifier]  : x
[Operator]    : <
[Identifier]  : y
[Special Char]: )
[Special Char]: {
[Identifier]  : x
[Operator]    : =
[Identifier]  : x
[Operator]    : +
[Number]      : 1
[Special Char]: ;
[Special Char]: }
[Keyword]     : else
[Special Char]: {
[Identifier]  : y
[Operator]    : =
[Identifier]  : y
[Operator]    : -
[Number]      : 1
[Special Char]: .
[Number]      : 0
[Special Char]: ;
[Special Char]: }
[Keyword]     : return
[Number]      : 0
[Special Char]: ;
[Special Char]: }
