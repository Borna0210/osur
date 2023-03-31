#include <types/basic.h>
#include <lib/string.h>
#include <api/stdio.h>

extern unsigned int kernel_code_addr;
extern unsigned int kernel_rodata_addr;
extern unsigned int kernel_data_addr;
extern unsigned int kernel_end_addr;
extern unsigned int stack_top;

void helper_premjesti(void)
{
    
    unsigned int code_size = kernel_rodata_addr - kernel_code_addr;
    unsigned int rodata_size = kernel_data_addr - kernel_rodata_addr;
    unsigned int data_size = kernel_end_addr - kernel_data_addr;
  

    unsigned int new_code_addr = 0x200000;
    unsigned int new_rodata_addr = 0x300000;
    unsigned int new_data_addr = 0x400000;
    unsigned int new_stack_top = 0x800000 - STACK_SIZE;

    memmove((void *)new_code_addr, (void *)kernel_code_addr, code_size);
    memmove((void *)new_rodata_addr, (void *)kernel_rodata_addr, rodata_size);
    memmove((void *)new_data_addr, (void *)kernel_data_addr, data_size);

    asm volatile("mov %0, %%esp" ::"r"(new_stack_top));
}

void premjesti()
{
    helper_premjesti();
}