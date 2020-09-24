#include <timer.h>
#include <pic.h>
#include <cpu.h>
#include "timetest.h"
#include "proc.h"
#include "sched.h"
#include "tsystm.h"
extern IntHandler irq0inthand;

/* internal function prototypes */
void set_timer_count(int);
// void smalldelay(void);
void irq0inthandc(void);
void tick_handler(void);



void init_ticks()
{
  // tickcount = 0;
  // end_count = interval * TICKS_PER_SEC / MICROSECS_PER_SEC;
  // callback = app_tick_callback;
// #ifdef DEBUG
//   printf("Disabling interrupts in CPU while setting them up\n");
// #endif
//   cli();
// #ifdef DEBUG
//   printf("Setting interrupt gate for timer, irq 0\n");
// #endif
//   /* irq 0 maps to slot n = 0x20 in IDT for linux setup */
  set_intr_gate(TIMER0_IRQ + IRQ_TO_INT_N_SHIFT, &irq0inthand);
// #ifdef DEBUG
//   printf("Commanding PIC to interrupt CPU for irq 0\n");
// #endif
  pic_enable_irq(TIMER0_IRQ);
// #ifdef DEBUG
//   printf("Commanding timer to generate a pulse train using max count\n");
// #endif
  set_timer_count(0);
// #ifdef DEBUG
//   printf("Enabling interrupts in CPU\n");
// #endif
//   sti();
}


int set_timer(IntHandler *callback, int time, int runtime) {
  return 0;
}
// int stop_timer(IntHandler *function) {
//   return 0;
// }


void shutdown_ticks()
{
  pic_disable_irq(TIMER0_IRQ);  /* disallow irq 0 ints to get to CPU */
}

/* about 10 us on a SAPC (400Mhz Pentium) */
// void smalldelay(void)
// {
//   int i;

//   for (i = 0; i < 1000; i++)
//     ;
// }

/* Set up timer to count down from given count, then send a tick interrupt, */
/* over and over. A count of 0 sets max count, 65536 = 2**16 */
void set_timer_count(int count)
{
  outpt(TIMER_CNTRL_PORT, TIMER0 | TIMER_SET_ALL | TIMER_MODE_RATEGEN);
  outpt(TIMER0_COUNT_PORT, count & 0xff); /* set LSB here */
  outpt(TIMER0_COUNT_PORT, count >> 8); /* and MSB here */
  // smalldelay();                 /* give the timer a moment to init. */
}
void tick_handler() {
  nmb[0] = '*';
  // nmb[2] = '*2';
  nmb[2] = '\0';
  // increase tick count
  ++curproc->proc_tick;

  // switch curproc Numer process 1 or 2
  switch (curproc->pNumer) {
  case 1:
    nmb[1] = '1';
    break;
  case 2:
    nmb[1] = '2';
    break;
  }
  // check
  if (curproc->pNumer == 1 || curproc->pNumer == 2)
    debug_log(nmb);
  // decrement and check if = 0, if so change to quantumax
  if (--curproc->proc_quantum == 0) {    //decrement
    curproc->proc_quantum = Quantumax;
#ifdef DEBUG
#endif
    scheduler(3);
  }
}
/* timer interrupt handler */
void irq0inthandc(void)
{
  pic_end_int();                /* notify PIC that its part is done */
  tick_handler();
}

