/*! Printing on stdout/stderr */
#pragma once

int printf(char *format, ...);
int PRINTF(char *text);
void warn(char *format, ...);

int stdio_init();
