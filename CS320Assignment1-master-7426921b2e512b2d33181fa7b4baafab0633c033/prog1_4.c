#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "prog1.h"

int main() {
    char buff[256];
    printf("Assignment #1-4, Anas Khafagi, anas.khafagi@gmail.com\n");
    do {
        memset(buff, 0, 256);
        printf("> ");
        fgets(buff, 200, stdin);
        int tok_count = token_count(buff);
        if (strlen(buff) > 21) {
            printf("ERROR! Input string too long.\n");
            continue;
        }
        if (tok_count > 2 || tok_count == 0) {
            printf("ERROR! Incorrect number of tokens found.\n");
            continue;
        }
        if (strncasecmp(buff, "quit", 4) == 0)
            return 0;

        print_tokens(buff);
    } while (strncasecmp(buff, "quit", 4) != 0);
}

int token_count(char buff[]) {
    char tokens[256];
    strcpy(tokens, buff);
    int count = 0;
    char* end_line = strchr(tokens,'\n');
    if(end_line)
        *end_line = '\0';
    char *tok = strtok(tokens, " ");
    while (tok != NULL) {
        tok = strtok(NULL, " ");
        count++;
    }
    return count;
}

void print_tokens(char buff[]) {
    char *end_line = strchr(buff, '\n');
    if (end_line)
        *end_line = '\0';
    char *tok = strtok(buff, " ");
    while (tok != NULL) {
        if (is_digit(tok))
            printf("INT ");
        else
            printf("STR ");
        tok = strtok(NULL, " ");
    }
    printf("\n");
}

int is_digit(char *token) {
    while (*token) {
        if (isdigit(*token++) == 0)
            return 0;
    }
    return 1;
}
