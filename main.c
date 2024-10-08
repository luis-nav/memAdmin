#include "memAdmin.h"

int main(int argc, char** argv) {
    struct Args* args;
    args = parse_arguments(argc, argv);

    char* memory = malloc(1024);

    char line[256];
    while (fgets(line, sizeof(line), args->file) != NULL) {
        struct Command* cmd = parse_line(line);
        if (cmd != NULL) {
            printf("The command is: %d\n", cmd->command);
        }
    }

    return 0;
}