#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "prog1.h"
#include <errno.h>

int main(int argc, char *argv[]) {
    char buff[256];
    printf("Assignment #1-6, Anas Khafagi, anas.khafagi@gmail.com\n");
    if (argc != 2) {
        printf("ERROR! Program 6 accepts 1 command line argument.");
        return 1;
    }
    errno = 0;
    int max_inputs = (int)strtol(argv[1], NULL, 10);
    if (errno != 0) {
        printf("ERROR! Expected Integer argument.");
        return 1;
    }
    int num_inputs;
    do {
        if (num_inputs == max_inputs)
            return 0;
        memset(buff, 0, 256);
        printf("> ");
        fgets(buff, 200, stdin);
        int tok_count = token_count(buff);
        int flag = set_flag(buff, tok_count);
        if (strlen(buff) > 66) {
            printf("ERROR! Input string too long.\n");
            num_inputs++;
            continue;
        }
        if (tok_count > 2) {
            printf("ERROR! Incorrect number of tokens found.\n");
            num_inputs++;
            continue;
        }
        switch (flag) {
            case 0:
                printf("ERROR! Expected STR.\n");
                num_inputs++;
                continue;

            case 1:
                printf("ERROR! Expected STR INT.\n");
                num_inputs++;
                continue;
        }

        if (strncasecmp(buff, "quit", strlen(buff)-1) == 0)
            return 0;
        print_tokens(buff);
        num_inputs++;

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
    int flag;
    char tokens[256];
    strcpy(tokens, buff);
    char *tok = strtok(tokens, " ");
    while (tok != NULL) {
        if (flag == -1 && isdigit(*tok))
            break;
        else if (flag == -1 && !isdigit(*tok)) {
            flag = 1;
            break;
        }

        if (isdigit(*tok) && count == 2) {
            flag = 1;
        } else if (isdigit(*tok) && count == 1) {
            flag = 0;

        } else
            flag = -1;
        tok = strtok(NULL, " ");
    }
    return flag;
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