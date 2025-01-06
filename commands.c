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

/* Helper function to validate and fetch a complex variable */
complex *validate_complex_var(char variable) {
    complex *var = get_complex_var(variable);
    if (!var) {
        printf("Undefined complex variable\n");
        return NULL;
    }
    return var;
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
void handle_command(char *command) {
    double real, imag;
    char variable, variable2;
    complex *var1 = NULL, *var2 = NULL;
    complex result;
    char extra[10];
    char command_name[20];

    /* Trim the input command */
    trim_whitespace(command);

    /* Extract the command name */
    if (sscanf(command, "%s", command_name) != 1 || !is_valid_command(command_name)) {
        printf("Invalid command or parameters\n");
        return;
    }

    /* Handle specific commands */
    if (strstr(command, "read_comp") != NULL) {
        if (sscanf(command, "read_comp %c , %lf , %lf %s", &variable, &real, &imag, extra) == 4) {
            printf("Extraneous text after end of command\n");
            return;
        }
        if (sscanf(command, "read_comp %c , %lf , %lf", &variable, &real, &imag) == 3) {
            var1 = validate_complex_var(variable);
            if (!var1) return;
            read_comp(var1, &real, &imag);
            print_comp(var1);
            return;
        }
        if (strstr(command, ", ,")) {
            printf("Multiple consecutive commas\n");
            return;
        }
        if (sscanf(command, "read_comp %c , %lf", &variable, &real) == 2) {
            printf("Missing parameter\n");
            return;
        }
        if (sscanf(command, "read_comp %c %lf", &variable, &real) == 2) {
            printf("Missing comma\n");
            return;
        }
        printf("Invalid command or parameters\n");
        return;
    }

    if (strstr(command, "print_comp") != NULL) {
        if (sscanf(command, "print_comp %c %s", &variable, extra) == 2) {
            printf("Extraneous text after end of command\n");
            return;
        }
        if (sscanf(command, "print_comp %c", &variable) == 1) {
            var1 = validate_complex_var(variable);
            if (!var1) return;
            print_comp(var1);
            return;
        }
        printf("Invalid command or parameters\n");
        return;
    }

    if (strstr(command, "add_comp") != NULL) {
        if (sscanf(command, "add_comp %c , %c %s", &variable, &variable2, extra) == 3) {
            printf("Extraneous text after end of command\n");
            return;
        }
        if (sscanf(command, "add_comp %c , %c", &variable, &variable2) == 2) {
            var1 = validate_complex_var(variable);
            var2 = validate_complex_var(variable2);
            if (!var1 || !var2) return;
            result = add_comp(var1, var2);
            print_comp(&result);
            return;
        }
        printf("Invalid command or parameters\n");
        return;
    }

    if (strstr(command, "sub_comp") != NULL) {
        if (sscanf(command, "sub_comp %c , %c %s", &variable, &variable2, extra) == 3) {
            printf("Extraneous text after end of command\n");
            return;
        }
        if (sscanf(command, "sub_comp %c , %c", &variable, &variable2) == 2) {
            var1 = validate_complex_var(variable);
            var2 = validate_complex_var(variable2);
            if (!var1 || !var2) return;
            result = sub_comp(var1, var2);
            print_comp(&result);
            return;
        }
        printf("Invalid command or parameters\n");
        return;
    }

    if (strstr(command, "mult_comp_real") != NULL) {
        if (sscanf(command, "mult_comp_real %c , %lf %s", &variable, &real, extra) == 3) {
            printf("Extraneous text after end of command\n");
            return;
        }
        if (sscanf(command, "mult_comp_real %c , %lf", &variable, &real) == 2) {
            var1 = validate_complex_var(variable);
            if (!var1) return;
            result = mult_comp_real(var1, &real);
            print_comp(&result);
            return;
        }
        printf("Invalid command or parameters\n");
        return;
    }

    if (strstr(command, "mult_comp_img") != NULL) {
        if (sscanf(command, "mult_comp_img %c , %lf %s", &variable, &imag, extra) == 3) {
            printf("Extraneous text after end of command\n");
            return;
        }
        if (sscanf(command, "mult_comp_img %c , %lf", &variable, &imag) == 2) {
            var1 = validate_complex_var(variable);
            if (!var1) return;
            result = mult_comp_img(var1, &imag);
            print_comp(&result);
            return;
        }
        if (sscanf(command, "mult_comp_img %c , %s", &variable, extra) == 2) {
            printf("Invalid parameter – not a number\n");
            return;
        }
        printf("Invalid command or parameters\n");
        return;
    }

    if (strstr(command, "mult_comp_comp") != NULL) {
        if (sscanf(command, "mult_comp_comp %c , %c %s", &variable, &variable2, extra) == 3) {
            printf("Extraneous text after end of command\n");
            return;
        }
        if (sscanf(command, "mult_comp_comp %c , %c", &variable, &variable2) == 2) {
            var1 = validate_complex_var(variable);
            var2 = validate_complex_var(variable2);
            if (!var1 || !var2) return;
            result = mult_comp_comp(var1, var2);
            print_comp(&result);
            return;
        }
        printf("Invalid command or parameters\n");
        return;
    }

    if (strstr(command, "abs_comp") != NULL) {
        if (sscanf(command, "abs_comp %c %s", &variable, extra) == 2) {
            printf("Extraneous text after end of command\n");
            return;
        }
        if (sscanf(command, "abs_comp %c", &variable) == 1) {
            var1 = validate_complex_var(variable);
            if (!var1) return;
            printf("%.2f\n", abs_comp(var1));
            return;
        }
        printf("Invalid command or parameters\n");
        return;
    }

    if (strncmp(command, "stop", 4) == 0) {
        if (strlen(command) > 4 && !isspace(command[4])) {
            printf("Extraneous text after end of command\n");
            return;
        }
        printf("Program stopped\n");
        exit(0);
    }

    printf("Invalid command or parameters\n");
}
