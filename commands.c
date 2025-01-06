#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "commands.h"

/* Declare the global complex variables */
complex A, B, C, D, E, F;

/* Function to map a variable character to its respective complex variable */
complex *get_complex_var(char variable) {
    switch (variable) {
        case 'A': return &A;
        case 'B': return &B;
        case 'C': return &C;
        case 'D': return &D;
        case 'E': return &E;
        case 'F': return &F;
        default: return NULL;
    }
}

/* Function to trim leading and trailing spaces */
void trim_whitespace(char *str) {
    char *end;

    /* Trim leading spaces */
    while (isspace((unsigned char)*str)) str++;

    /* If the string is all spaces, return an empty string */
    if (*str == 0) {
        str[0] = '\0';
        return;
    }

    /* Trim trailing spaces */
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    /* Write null terminator */
    *(end + 1) = '\0';
}

/* Function to check if a command is valid */
int is_valid_command(const char *command) {
    static const char *valid_commands[] = {
        "read_comp", "print_comp", "add_comp", "sub_comp",
        "mult_comp_real", "mult_comp_img", "mult_comp_comp", "abs_comp", "stop"
    };
    int i;
    for (i = 0; i < 9; i++) {
        if (strncmp(command, valid_commands[i], strlen(valid_commands[i])) == 0) {
            return 1;
        }
    }
    return 0;
}

/* Function to handle errors */
void error(const char *message) {
    printf("%s\n", message);
}

/* Function to handle user commands */
void handle_command(char *command) {
    double real, imag;
    char variable, variable2;
    complex *var1 = NULL, *var2 = NULL;
    complex result;
    char extra[10];

    /* Trim the input command */
    trim_whitespace(command);

    /* Extract the command name */
    char command_name[20];
    if (sscanf(command, "%s", command_name) != 1 || !is_valid_command(command_name)) {
        error("Invalid command or parameters");
        return;
    }

    /* Read complex command */
    if (sscanf(command, "read_comp %c , %lf , %lf %s", &variable, &real, &imag, extra) == 4) {
        error("Invalid command or parameters");
        return;
    }
    if (sscanf(command, "read_comp %c , %lf , %lf", &variable, &real, &imag) == 3) {
        var1 = get_complex_var(variable);
        if (!var1) {
            error("Undefined complex variable");
            return;
        }
        read_comp(var1, &real, &imag);
        return;
    }

    /* Print complex command */
    if (sscanf(command, "print_comp %c %s", &variable, extra) == 2) {
        error("Invalid command or parameters");
        return;
    }
    if (sscanf(command, "print_comp %c", &variable) == 1) {
        var1 = get_complex_var(variable);
        if (!var1) {
            error("Undefined complex variable");
            return;
        }
        print_comp(var1);
        return;
    }

    /* Add complex command */
    if (sscanf(command, "add_comp %c , %c %s", &variable, &variable2, extra) == 3) {
        error("Invalid command or parameters");
        return;
    }
    if (sscanf(command, "add_comp %c , %c", &variable, &variable2) == 2) {
        var1 = get_complex_var(variable);
        var2 = get_complex_var(variable2);
        if (!var1 || !var2) {
            error("Undefined complex variable");
            return;
        }
        result = add_comp(var1, var2);
        print_comp(&result);
        return;
    }

    /* Handle other commands similarly... */

    /* Stop command */
    if (strncmp(command, "stop", 4) == 0) {
        if (strlen(command) > 4 && !isspace(command[4])) {
            error("Invalid command or parameters");
            return;
        }
        printf("Program stopped\n");
        exit(0);
    }

    /* Invalid command */
    error("Invalid command or parameters");
}
