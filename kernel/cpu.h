#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct {
    char vendor[13];
    uint32_t signature;
    uint32_t features;
    int has_cpuid;
} cpu_info_t;

void cpu_detect(cpu_info_t* info);
void cpu_print_info(void);

#endif