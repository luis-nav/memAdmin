#include "line_parser.h"

// Delimiters
const char *delimiters = " \n";

int parse_command(char *token) {
    if (strcmp(token, "ALLOC") == 0)
        return ALLOC;
    else if (strcmp(token, "FREE") == 0)
        return FREE;
    else if (strcmp(token, "PRINT") == 0)
        return PRINT;
    else
        return UNKNOWN;
}

struct Command* parse_line(char* line) {
    // Ignore comments
    if (!strncmp(line, "#", 1)) return NULL;

    char* token = strtok(line, delimiters);
    
    // Ignore blank lines
    if (token == NULL) {
        return NULL;
    }

    struct Command* cmd;
    cmd = malloc(sizeof(struct Command));
    
    // Define command type
    cmd->command = parse_command(token);

    // If it is not print or unknown, it must have a var name
    if (cmd->command < 3) {
        token = strtok(NULL, delimiters);
        if (token != NULL) {
            cmd->variable = token[0];
        } else {
            printf("Expected variable name after ALLOC, REALLOC or FREE\nLine: %s", line);
            exit(2);
        }
    }
    // If it ALLOC or REALLOC a size must be provided
    if (cmd->command < 2) {
        token = strtok(NULL, delimiters);
        if (token != NULL) {
            cmd->size = atoi(token);
        } else {
            printf("Expected size after ALLOC or REALLOC\nLine: %s", line);
            exit(2);
        }
    }
    return cmd;
}