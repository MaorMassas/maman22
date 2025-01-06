#include <stdio.h>
#include <string.h>
#include "commands.h"

int main(void) {
    char input[100];
    char *newline;

    printf("Complex Numbers Calculator\n");

    while (fgets(input, sizeof(input), stdin) != NULL) {
        newline = strchr(input, '\n');
        if (newline) *newline = '\0';

        handle_command(input);
    }

    return 0;
}
