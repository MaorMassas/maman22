#include <stdio.h>
#include <string.h>
#include "commands.h"

int main(void) {
    char input[100];
    char *newline;

    printf("Complex Numbers Calculator\n");

    while (1) {
        printf("Enter command: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input\n");
            continue;
        }

        /* Remove trailing newline character */
        newline = strchr(input, '\n');
        if (newline) *newline = '\0';

        /* Handle the command */
        handle_command(input);
    }

    return 0;
}
