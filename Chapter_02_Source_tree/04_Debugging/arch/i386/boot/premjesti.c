#include <types/basic.h>
#include <lib/string.h>
#include <api/stdio.h>

extern unsigned int kernel_code_addr;
extern unsigned int kernel_rodata_addr;
extern unsigned int kernel_data_addr;
extern unsigned int kernel_end_addr;
extern unsigned int stack_top;

void premjesti_helper()
{
	extern char size_data;
	extern size_t size_i, size_r;
	size_t size_d = (size_t) &size_data;
	size_t i;
	char *od = (char *) 0x40000;
	char *kamo = (char *) 0x400000;

	//for ( i = 0; i< size_d; i++ )
	//	kamo[i] = od[i];

	for ( i = 0; i< size_d; i++ )
		*kamo++ = *od++;

	od = (char *) 0x20000;
	kamo = (char *) 0x200000;
	size_d = (size_t) &size_i;

	for ( i = 0; i< size_d; i++ )
		*kamo++ = *od++;
    
    od = (char *) 0x30000;
	kamo = (char *) 0x300000;
	size_d = (size_t) &size_r;

	for ( i = 0; i< size_d; i++ )
		*kamo++ = *od++;

    unsigned int new_stack_top = 0x800000 - STACK_SIZE;
    asm volatile("mov %0, %%esp" ::"r"(new_stack_top));
}

void premjesti()
{
    premjesti_helper();
}