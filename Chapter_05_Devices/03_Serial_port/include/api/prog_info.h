/*! Program info */
#pragma once

#include <types/basic.h>

/* "programs" */
int hello_world();
int timer();
int timermonotonic();
int keyboard();
int segm_fault();

#define	hello_world_PROG_HELP	"Print 'Hello world'."
#define	timer_PROG_HELP		"Timer interface demonstration: "	\
				"periodic timer activations."

#define	timermonotonic_PROG_HELP		"Timermonotonic program interface demonstration: "	
#define	keyboard_PROG_HELP	"Print ASCII code for each keystroke. "	\
				"Press '.' to end."
#define	segm_fault_PROG_HELP	"Generate segmentation fault."
