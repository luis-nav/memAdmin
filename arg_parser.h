#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Args {
    FILE* file;
    int algorithm;
};

struct Args* parse_arguments(int, char**);