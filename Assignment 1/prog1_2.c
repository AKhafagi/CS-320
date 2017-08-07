#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "prog1.h"

int main() {
    char buff[256];
    printf("Assignment #1-2, Anas Khafagi, anas.khafagi@gmail.com\n");
    printf("> ");
    fgets(buff, 65, stdin);
    print_tokens(buff);

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
}
int is_digit(char * token){
    while (*token) {
        if (isdigit(*token++) == 0)
            return 0;
    }
    return 1;
}
