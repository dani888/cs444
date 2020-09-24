#include <stdio.h>
#include "io_public.h"
#include <cpu.h>
#include <gates.h>
#include "tsyscall.h"
#include "tsystm.h"
#include "tunistd.h"

#define MILLION 1000000
#define DELAYLOOPCOUNT (400 * MILLION)
#define BUFLEN 80


void delay(void);

int main(void) {
	char buf[BUFLEN];
	int got, i, ldev;
	ldev = TTY1;
	/* Determine the SAPC's "console" device, the serial port for user i/o */
	// lib_console_dev = sys_get_console_dev();  /* SAPC support lib fn */
	// switch (lib_console_dev) {
	// case COM1: ldev = TTY0; /* convert to our dev #'s */
	// 	break;
	// case COM2: ldev = TTY1;
	// 	break;
	// default: printf("Unknown console device\n");
	// return 1;
	// }
	kprintf("Running with device TTY%d\n", ldev);

	kprintf("\nTrying simple write(4 chars)...\n");
	got = write(ldev, "hi!\n", 4);
	kprintf("write of 4 returned %d\n", got);
	delay();

	kprintf("Trying longer write (9 chars)\n");
	got = write(ldev, "abcdefghi", 9);
	kprintf("write of 9 returned %d\n", got);
	delay();

	for (i = 0; i < BUFLEN; i++)
		buf[i] = 'A' + i / 2;
	kprintf("\nTrying write of %d-char string...\n", BUFLEN);
	got = write(ldev, buf, BUFLEN);
	kprintf("\nwrite returned %d\n", got);
	delay();

	kprintf("\ntype 10 chars\n");
	read(ldev, buf, 10);
	kprintf("\nReturning from read, trying write of buf...\n");
	write(ldev, buf, 10);
	return 0;
}


void delay() {
	int i;

	kprintf("<doing delay>\n");
	for (i = 0; i < DELAYLOOPCOUNT; i++)
		;
}

