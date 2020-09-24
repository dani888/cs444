#include <cpu.h>
#include <stdio.h>
#include "sched.h"
#include "proc.h"
#define BUFLEN 100

extern void debug_log(char *msg);
extern void asmswtch(PEntry *oldpentryp, PEntry *newpentryp);

typedef unsigned int byte;
void schedule(int entry) {
	byte saved_eflags;

	PEntry * past_process = curproc;
	PEntry *oldpro = curproc;
	if (proctab[entry].p_status == RUN)
		curproc = (PEntry *)proctab + entry;
	else
		curproc = (PEntry *)proctab;
	saved_eflags = get_eflags();
	printSwitch(oldpro);
	asmswtch(past_process, curproc);
	set_eflags(saved_eflags);
}
void sleep() {
	byte saved_eflags;
	saved_eflags = get_eflags();
	cli();
	curproc->p_status = BLOCKED;
	saved_eflags = get_eflags();
}
void wakeup() {
	int i;
	byte saved_eflags;
	saved_eflags = get_eflags();
	cli();
	for (i = 1; i < NPROC; i++) {
		if (proctab[i].p_status == BLOCKED)
			proctab[i].p_status == RUN;
	}
	set_eflags(saved_eflags);
}
void printSwitch(PEntry *oldpro) {
	char buf[BUFLEN] = "";
	if (oldpro->p_status == ZOMBIE) {
		sprintf(buf, "|(%dz-%d)", oldpro-proctab,curproc-proctab);
	} else if (oldpro->p_status == BLOCKED) {
		sprintf(buf, "|(%db-%d)", oldpro-proctab, curproc-proctab);
	}
	else {
		sprintf(buf, "|(%d-%d)", oldpro-proctab,curproc-proctab);
	}
	if (strlen(buf))
		debug_log(buf);
}

