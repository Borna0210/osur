/*! linker script for memory layout */

/* Its parsed as C before used in linking! */

ENTRY(arch_startup)

STACK_ADDR    = 0x800000-STACK_SIZE;
SECTIONS {
	.code 0x0:
	{
		kernel_code_addr = .;

		/* instructions */
		*?/boot/startup.asm.o ( .text* )
		*?/boot/premjesti.o ( .text* )

	}
	.instrukcije 0x200000 : AT(0x20000){
		kernel_instrukcije_addr = .;
		*( .text* )
	}

	size_i = SIZEOF(.instrukcije);
	.rodata 0x300000  : AT(0x30000)
	{
		kernel_rodata_addr = .;

		/* read only data (constants) */
		*( .rodata* )
	}
	size_r = SIZEOF(.rodata);
	.data 0x400000  : AT(0x40000)
	{
		kernel_data_addr = .;

		/* read only data (constants), initialized global variables */
		* ( .data* )
		. = ALIGN (4096);

		*( .bss* )
	}
	size_data = SIZEOF(.data);
	/* For stack, two options are shown here */
	/* 1. treat system_stack as a variable in special section and
	      mark it as such in kernel/startup.c */
	.stack_segment STACK_ADDR : AT (0x80000)
	{
		* ( .stack_section* )
	}

	/*
	 * what with other sections generated with gcc (various versions)?
	 * if optimizing for size discard them with: /DISCARD/ : { *(*) }
	 * if debugging with qemu/gdb they must be included
	 * - they can be included implicitly, without declaring them here
	 * - but they will be put behind "kernel_end_addr" so its best to use
	 *   multiboot loader (QEMU is that)
	 */

#ifndef DEBUG
	/DISCARD/ : { *(*) }
#endif
	kernel_end_addr = .;
}
