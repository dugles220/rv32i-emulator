#include "Cpu.h"

uint32_t read_instruction(CPU* cpu){

    uint32_t instruction = 0;

    for(uint32_t i = 0; i < INSTRUCTION_SIZE; i++){
        instruction |= ((uint32_t)cpu->memory[cpu->pc + i]) << (i * BYTE_SIZE);
    }

    return instruction;
}

void cpu_step(CPU* cpu){

    uint32_t instruction = read_instruction(cpu);

    uint8_t opcode = instruction & 0x7F; /* bits 0-6 */
    uint8_t rd = (instruction >> 7) & 0x1F; /* bits 7-11 */
    uint8_t funct3 = (instruction >> 12) & 0x07; /* bits 12-14 */
    uint8_t rs1 = (instruction >> 15) & 0x1F; /* bits 15-19 */
    uint16_t imm = instruction >> 20; /* bits 20-31 */

    /* ADDI */
    if(opcode == ADDI_OP && funct3 == 0x00){
        cpu->regs[rd] = cpu->regs[rs1] + imm;
    }

    cpu->regs[0] = 0;
    cpu->pc += INSTRUCTION_SIZE;

}

void cpu_dump_registers(CPU* cpu){

    printf("%-10s %8d\n\n", "pc", cpu->pc);

    printf("%-10s %8d\n", "zero",cpu->regs[0]);
    printf("%-10s %8d\n", "ra", cpu->regs[1]);
    printf("%-10s %8d\n", "sp", cpu->regs[2]);
    printf("%-10s %8d\n", "gp", cpu->regs[3]);
    printf("%-10s %8d\n", "Tp", cpu->regs[4]);
    printf("%-10s %8d\n", "t0", cpu->regs[5]);
    printf("%-10s %8d\n", "t1", cpu->regs[6]);
    printf("%-10s %8d\n", "t2", cpu->regs[7]);

    printf("%-10s %8d\n", "s0", cpu->regs[8]);
    printf("%-10s %8d\n", "s1", cpu->regs[9]);
    printf("%-10s %8d\n", "a0", cpu->regs[10]);

    for(int i = 0; i < 8; i++){
        printf("%s%-9d %8d\n", "a", i, cpu->regs[i + 10]);
    }
    for(int i = 2; i < 12; i++){
        printf("%s%-9d %8d\n", "s", i, cpu->regs[i + 16]);
    }
    for(int i = 3; i < 7; i++){
        printf("%s%-9d %8d\n", "t", i, cpu->regs[i + 25]);
    }
}