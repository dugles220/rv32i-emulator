#include <stdint.h>

#define MEM_SIZE (1024 * 1024)

typedef struct {

    uint32_t regs[32];
    uint32_t pc;

    uint32_t memory[MEM_SIZE];

} CPU;