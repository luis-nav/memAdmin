#include "memory_table.h"

void init_table(struct MemoryTable* table, int capacity) {
    table->blocks = malloc(capacity * sizeof(struct Block));
    table->buffer = malloc(capacity);
    table->size = 0;
    table->capacity = capacity;
    struct Block initial_block = {' ', true, 0, capacity}; 
    table->blocks[0] = initial_block;
}

void set_data(char var_name, char* buffer, int start_index, int end_index) {
    for (int i = start_index; i < end_index; i++) {
        buffer[i] = var_name;
    }
}

bool contains(struct Block* block1, struct Block* block2) {
    return block1->start_index <= block2->start_index && block1->end_index >= block2->end_index;
}

void add_block(struct MemoryTable* table, char var_name, int start_index, int end_index) {
    // New block
    struct Block block = {var_name, false, start_index, end_index};
    // Find index to add the new block
    int added_index = -1;
    for (int i = 0; i < table->size; i++) {
        if (contains(&(table->blocks[i]), &block)) {
            added_index = i;
            table->size++;
            break;            
        }
    }
    // There isnt a containing block
    if (added_index == -1) return;

    // Move the rest of the blocks to the "right"
    for (int i = table->size-1; i > added_index; i--) {
        table->blocks[i] = table->blocks[i-1];
    }
    table->blocks[added_index] = block;

}

void free_block(struct MemoryTable* table, int start_index) {
    // Set block as free 
    for (int i = 0; i <= table->size; i++) {
        if (table->blocks[i].start_index == start_index) {
            table->blocks[i].free = true;
            table->blocks[i].var_name = ' ';
            set_data(table->blocks[i].var_name, table->buffer, table->blocks[i].start_index, table->blocks[i].end_index);
        }
    }

    // Unite free blocks
    bool past_block_free_flag = false;
    int offset_counter = 0;
    for (int i = 0; i < table->size; i++) {
        // If there was an offset caused by the elimination of one block, the rest of the array should be reassigned
        if (offset_counter && i < table->size) {
            table->blocks[i] = table->blocks[i+offset_counter];
        }

        // If past and current blocks are both free, unite them
        if (table->blocks[i].free && past_block_free_flag) {
            table->blocks[i-1].end_index = table->blocks[i].end_index; 
            offset_counter++;
            table->size--;
            i--;
        }

        past_block_free_flag = table->blocks[i].free;
    }
}