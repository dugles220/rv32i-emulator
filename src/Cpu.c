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
