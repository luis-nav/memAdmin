#include "memAdmin.h"

#define CAPACITY 1024

int main(int argc, char** argv) {
    struct Args* args;
    args = parse_arguments(argc, argv);

    // Elements to be managed
    struct MemoryTable table;
    init_table(&table, CAPACITY);

    char line[256];
    while (fgets(line, sizeof(line), args->file) != NULL) {
        struct Command* cmd = parse_line(line);
        if (cmd != NULL) {
            if (cmd->command == ALLOC) {
                alloc_variable(&table, cmd->variable, cmd->size, args->algorithm);
            } else if (cmd->command == REALLOC) {
                realloc_variable(&table, cmd->variable, cmd->size, args->algorithm);
            } else if (cmd->command == FREE) {
                free_variable(&table, cmd->variable);
            } else if (cmd->command == PRINT) {
                print_table(&table);
            } else {
                printf("Could not read command... Exiting app...");
                exit(2);
            }
        }
    }
    return 0;
}