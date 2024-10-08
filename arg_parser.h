#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants of algorithms
#define BEST  0
#define FIRST 1
#define WORST 2

struct Args {
    FILE* file;
    int algorithm;
};

struct Args* parse_arguments(int, char**);