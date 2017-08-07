#include <stdio.h>

int main() {
    char name[100] = "";
    printf("Assignment #0, Anas Khafagi, anas.khafagi@gmail.com\n");
    printf("What is your name?\n");
    scanf("%[^\n]s", name);
    printf("Hello %s\n", name);
    return 0;
}
