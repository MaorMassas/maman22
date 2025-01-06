#include "complex.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* הגדרה של ששת המשתנים מטיפוס complex */
complex A, B, C, D, E, F;

/* פונקציה לניקוי שורות קלט */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* ממשיך לקרוא עד סוף השורה */
    }
}

/* פונקציה לפענוח פקודות */
void handle_command(char *command) {
    char name[10];
    double real, imag;
    char variable, variable2;
    complex *var1 = NULL, *var2 = NULL;
    complex result; // משתנה זמני לאחסון התוצאות

    /* בדיקת הפקודה */
    if (sscanf(command, "read_comp %c , %lf , %lf", &variable, &real, &imag) == 3) {
        switch (variable) {
            case 'A': var1 = &A; break;
            case 'B': var1 = &B; break;
            case 'C': var1 = &C; break;
            case 'D': var1 = &D; break;
            case 'E': var1 = &E; break;
            case 'F': var1 = &F; break;
            default:
                printf("Undefined complex variable\n");
                return;
        }
        read_comp(var1, &real, &imag);
    } else if (sscanf(command, "print_comp %c", &variable) == 1) {
        switch (variable) {
            case 'A': var1 = &A; break;
            case 'B': var1 = &B; break;
            case 'C': var1 = &C; break;
            case 'D': var1 = &D; break;
            case 'E': var1 = &E; break;
            case 'F': var1 = &F; break;
            default:
                printf("Undefined complex variable\n");
                return;
        }
        print_comp(var1);
    } else if (sscanf(command, "add_comp %c , %c", &variable, &variable2) == 2) {
        switch (variable) {
            case 'A': var1 = &A; break;
            case 'B': var1 = &B; break;
            case 'C': var1 = &C; break;
            case 'D': var1 = &D; break;
            case 'E': var1 = &E; break;
            case 'F': var1 = &F; break;
            default:
                printf("Undefined complex variable\n");
                return;
        }
        switch (variable2) {
            case 'A': var2 = &A; break;
            case 'B': var2 = &B; break;
            case 'C': var2 = &C; break;
            case 'D': var2 = &D; break;
            case 'E': var2 = &E; break;
            case 'F': var2 = &F; break;
            default:
                printf("Undefined complex variable\n");
                return;
        }
        result = add_comp(var1, var2); // שימוש במשתנה זמני
        print_comp(&result);
    } else if (sscanf(command, "sub_comp %c , %c", &variable, &variable2) == 2) {
        switch (variable) {
            case 'A': var1 = &A; break;
            case 'B': var1 = &B; break;
            case 'C': var1 = &C; break;
            case 'D': var1 = &D; break;
            case 'E': var1 = &E; break;
            case 'F': var1 = &F; break;
            default:
                printf("Undefined complex variable\n");
                return;
        }
        switch (variable2) {
            case 'A': var2 = &A; break;
            case 'B': var2 = &B; break;
            case 'C': var2 = &C; break;
            case 'D': var2 = &D; break;
            case 'E': var2 = &E; break;
            case 'F': var2 = &F; break;
            default:
                printf("Undefined complex variable\n");
                return;
        }
        result = sub_comp(var1, var2); // שימוש במשתנה זמני
        print_comp(&result);
    } else if (strncmp(command, "stop", 4) == 0) {
        printf("Program stopped\n");
        exit(0);
    } else {
        printf("Invalid command or parameters\n");
    }
}

int main() {
    char input[100];

    printf("Complex Numbers Calculator\n");
    while (1) {
        printf("Enter command: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input\n");
            continue;
        }

        /* הסרת תווי רווח ותווים לבנים נוספים */
        char *newline = strchr(input, '\n');
        if (newline) *newline = '\0';

        /* ניתוח הפקודה */
        handle_command(input);
    }

    return 0;
}
