#include <cpu.h>
#include <gates.h>
#include "tsyscall.h"
#include "tsystm.h"
#include <stdio.h>
#include "io_public.h"

extern IntHandler syscall;
extern void ustart(void);
extern void startup0exit(void);
extern void debug_log(char *msg);
extern void locate_idt(unsigned int *limitp, char ** idtp);

void kernal_init(void);
void set_trap_gate(int n, IntHandler *inthand_addr);
void syscallc( int user_eax, int devcode, char *buff , int bufflen);
int sysexit(int code);

void kernal_init() {
	ioinit();
	set_trap_gate(0x80, &syscall);
	ustart();
}

/*sets trap gate and fills in desc table */
void set_trap_gate(int n, IntHandler *inthand_addr) {

	char *idt_addrLinear;
	char *idt_addrVirtual;
	Gate_descriptor *idt, *desc;
	unsigned int val = 0;

	locate_idt(&val, &idt_addrLinear);
	idt_addrVirtual = idt_addrLinear - KERNEL_BASE_LA;

	idt = (Gate_descriptor *) idt_addrVirtual;
	desc = &idt[n];

	/*descriptor table*/
	desc->selector = KERNEL_CS;
	desc->addr_hi = ((unsigned int)inthand_addr) >> 16;
	desc->addr_lo = ((unsigned int)inthand_addr) & 0xffff;
	desc->flags = GATE_P | GATE_DPL_KERNEL | GATE_TRAPGATE;
	desc->zero = 0;
}

/* syscallc with case - SYS_exit, SYS_write, SYS_read */
void syscallc( int user_eax, int devcode, char *buff , int bufflen)
{
	int trap = user_eax;

	switch (trap) {
	case 1:
		sysexit(3);
		break;
	case 3:
		sysread(devcode, buff, bufflen);
		break;
	case 4:
		syswrite(devcode, buff, bufflen);
		break;
	default :
		kprintf("eax val not a reference to  trap-call");
	}
}

/* Print log and exit program */
int sysexit(int code) {
	kprintf("\nExit code is: %d\n", code);
	kprintf("Exiting back to Tutor\n\n");
	startup0exit();
	return 0;
}

