#include <stdint.h>
#include <stdio.h>

#define MEM_SIZE (1024 * 1024) /* 1mb */
#define INSTRUCTION_SIZE 4 /* in bytes */
#define BYTE_SIZE 8 /* in bits */

#define ADDI_OP 0x13

typedef struct {

    uint32_t regs[32];
    uint32_t pc;

    uint8_t memory[MEM_SIZE];

} CPU;

uint32_t read_instruction(CPU* cpu);
void cpu_step(CPU* cpu);
void cpu_dump_registers(CPU* cpu);
void write_addi(CPU* cpu, uint32_t offset, uint8_t rd, uint8_t rs1, int16_t imm);