#include <stdio.h>
#include <string.h>

void main() {
    char string1[] = "Hello";
    printf("%s\n", strrev(string1));
};

char *strrev (char *string)
{
    for (int i = 0; i < strlen(string) / 2; i++) {
        char temp = string[i];
        string[i] = string[strlen(string) - 1 - i];
        string[strlen(string) - 1 - i] = temp;
    };
    return string;
};