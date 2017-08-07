#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "prog1.h"

int main() {

    char buff[256];
    printf("Assignment #1-5, Anas Khafagi, anas.khafagi@gmail.com\n");
    do {
        memset(buff, 0, 256);
        printf("> ");
        fgets(buff, 255, stdin);
        int tok_count = token_count(buff);
        int error_flag = set_flag(buff, tok_count);
        if (strlen(buff) > 66) {
            printf("ERROR! Input string too long.\n");
            continue;
        }
        if (tok_count > 2 || tok_count == 0) {
            printf("ERROR! Incorrect number of tokens found.\n");
            continue;
        }
        switch (error_flag) {
            case 0:
                printf("ERROR! Expected STR.\n");
                continue;

            case 1:
                printf("ERROR! Expected STR INT.\n");
                continue;
        }

        if (strncasecmp(buff, "quit", strlen(buff)-1) == 0)
            return 0;
        print_tokens(buff);

    } while (strncasecmp(buff, "quit", strlen(buff)-1) != 0);


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

int set_flag(char buff[], int count) {
    int error_flag;
    char tokens[256];
    strcpy(tokens, buff);
    char *tok = strtok(tokens, " ");
    while (tok != NULL) {
        if (error_flag == -1 && isdigit(*tok))
            break;
        else if (error_flag == -1 && !isdigit(*tok)) {
            error_flag = 1;
            break;
        }

        if (isdigit(*tok) && count == 2) {
            error_flag = 1;
        } else if (isdigit(*tok) && count == 1) {
            error_flag = 0;

        } else
            error_flag = -1;
        tok = strtok(NULL, " ");
    }
    return error_flag;
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