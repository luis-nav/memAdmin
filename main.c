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
            printf("The command is: %d\n", cmd->command);
        }
    }

    return 0;
}