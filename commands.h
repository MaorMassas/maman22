#ifndef COMMANDS_H
#define COMMANDS_H

#include "complex.h"

/* Function prototypes */
complex *get_complex_var(char variable);
void trim_whitespace(char *str);
int is_valid_command(const char *command);
void handle_command(char *command);
void error(const char *message);

#endif /* COMMANDS_H */
