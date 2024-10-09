#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Block {
    char var_name;
    bool free;
    int start_index;
    int end_index;
};

struct MemoryTable {
    struct Block* blocks;
    size_t size;
    size_t capacity;
    char* buffer;
};

void init_table(struct MemoryTable*, int);
void set_data(char, char*, int , int);
void add_block(struct MemoryTable*, char, int, int, int);
void alloc_variable_best(struct MemoryTable*, char, int);
void alloc_variable_first(struct MemoryTable*, char, int);
void alloc_variable_worst(struct MemoryTable*, char, int);
void alloc_variable(struct MemoryTable*, char, int, int);
void realloc_variable(struct MemoryTable*, char, int, int);
void free_variable(struct MemoryTable*, char);
void print_table(struct MemoryTable*);