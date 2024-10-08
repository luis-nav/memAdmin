#include "arg_parser.h"

struct Args {
    FILE* file;
    int algorithm;
} Args;

struct Args* parse_arguments(int argc, char** argv) {
    if (argc <= 2) {
        printf("Too few arguments: Usage: memAdmin [best|first|worst] [FILE]\n");
        exit(1);
    }
    if (argc >= 4) {
        printf("Too many arguments: Usage: memAdmin [best|first|worst] [FILE]\n");
        exit(1);
    }
    if (strncmp(argv[1], "best", 4) && strncmp(argv[1], "first", 5) && strncmp(argv[1], "worst", 5)) {
        printf("The assign algorithm must be either best, first or worst\n");
        exit(1);
    }

    FILE *file = fopen(argv[2], "r");

    if (!file) {
        printf("The given file does not exist\n");
        exit(1);
    }

    struct Args* args;
    args = malloc(sizeof(Args));

    return args;
}