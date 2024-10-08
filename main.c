#include "memAdmin.h"

int main(int argc, char** argv) {
    struct Args* args;
    args = parse_arguments(argc, argv);

    char* memory = malloc(1024);

    char line[256];
    while (fgets(line, sizeof(line), args->file) != NULL) {
        printf("%s", line);  // Process each line, here we just print it
    }

    return 0;
}