/* commands.h */
#ifndef COMMANDS_H
#define COMMANDS_H

#include "complex.h"

complex *get_complex_var(char variable);
int is_valid_command(const char *command);
void trim_whitespace(char *str);
void handle_command(char *command);
complex *validate_complex_var(char variable);

#endif
