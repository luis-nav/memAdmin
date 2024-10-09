#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants of commands
#define ALLOC   0
#define REALLOC 1
#define FREE    2
#define PRINT   3
#define UNKNOWN 4

struct Command {
    int command;
    char variable;
    int size;
};

struct Command* parse_line(char*);
int parse_command(char*);