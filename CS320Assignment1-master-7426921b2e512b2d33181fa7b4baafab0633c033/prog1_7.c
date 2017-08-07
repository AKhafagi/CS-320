#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "prog1.h"
#include <math.h>

int main() {
    char buff[256];
    char *op;
    int number_1;
    int number_2;
    printf("Assignment #1-7, Anas Khafagi, anas.khafagi@gmail.com\n");
    -printf("> ");
    fgets(buff, 65, stdin);
    int j = 0;
    char *tok = strtok(buff, " ");
    while (tok != NULL) {
        switch (j) {
            case 0:
                op = tok;
                break;
            case 1:
                if (tok)
                    number_1 = atoi(tok);
                break;
            case 2:
                if (tok)
                    number_2 = atoi(tok);
                break;
        }

        tok = strtok(NULL, " ");
        j++;
    }

    switch (*op) {
        case '+':
            printf("%d", number_1 + number_2);
            break;
        case '-':
            printf("%d", number_1 - number_2);
            break;
        case '*':
            printf("%d", number_1 * number_2);
            break;
        case '/':
            printf("%d", number_1 / number_2);
            break;
        case 's':
            printf("%0.3f", sin(M_PI * number_1 / 180));
            break;
        case 'c':
            printf("%f", cos(M_PI * number_1 / 180));
            break;

    }
}