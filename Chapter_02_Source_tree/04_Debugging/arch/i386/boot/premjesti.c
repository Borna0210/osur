#include <types/basic.h>
#include <lib/string.h>
#include <api/stdio.h>

void premjesti_helper()
{

	extern unsigned int kernel_code_addr;
	extern unsigned int kernel_end_addr;
	extern unsigned int kernel_data_addr;


	unsigned int kernel_size = (unsigned int)&kernel_data_addr - (unsigned int)&kernel_code_addr;
	unsigned int data_size = (unsigned int)&kernel_end_addr - (unsigned int)&kernel_data_addr;

	unsigned int *src = (unsigned int *)0x100000;
	unsigned int *dst = (unsigned int *)0x200000;

	for (unsigned int i = 0; i < kernel_size; i++)
	{
		dst[i] = src[i];
	}

	unsigned int *src2 = (unsigned int *)0x102000;
	unsigned int *dst2 = (unsigned int *)0x300000;

	for (unsigned int i = 0; i < data_size; i++)
	{
		dst2[i] = src2[i];
	}
}

void premjesti()
{
	premjesti_helper();
}