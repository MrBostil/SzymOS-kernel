#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

typedef struct {
    uint32_t lower;  // KB below 1MB
    uint32_t upper;  // KB above 1MB
    uint32_t total;  // Total in KB
} memory_info_t;

void memory_init(uint32_t multiboot_info);
void memory_print_info(void);
uint32_t get_total_memory(void);

#endif