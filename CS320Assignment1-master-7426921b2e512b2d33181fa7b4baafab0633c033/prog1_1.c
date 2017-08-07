#include <stdio.h>
#include <string.h>
#include "prog1.h"

int main() {
    char buff[256];
    printf("Assignment #1-1, Anas Khafagi, anas.khafagi@gmail.com\n");
    fgets(buff, 65, stdin);
    print_tokens(buff);
}

void print_tokens(char buff[]) {
    char *end_line = strchr(buff, '\n');
    if (end_line)
        *end_line = '\0';
    char *tok = strtok(buff, " ");
    while (tok != NULL) {
        printf("=%s=\n", tok);
        tok = strtok(NULL, " ");
    }
}
