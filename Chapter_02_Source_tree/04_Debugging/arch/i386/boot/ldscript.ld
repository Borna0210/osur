/*! linker script for memory layout */

/* Its parsed as C before used in linking! */

ENTRY(arch_startup)
STACK_ADDR = 0x800000 - STACK_SIZE;

SECTIONS {
	.code 0x200000 : AT (0x100000)
	{
		kernel_code_addr = .;

		/* instructions */
		*?/boot/startup.asm.o ( .text* )
		*?/boot/premjesti.o ( .text* )

		*( .text* .rodata*)
	}
	.data 0x300000: AT (0x102000)
	{
		kernel_data_addr = .;

		/* read only data (constants), initialized global variables */
		* ( .data* )
	}
	.bss :
	{
		*( .bss* COMMON* )

		. = ALIGN (4096);
	}
	.stack_segment STACK_ADDR :
	{
		*(.stack_section*)
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
