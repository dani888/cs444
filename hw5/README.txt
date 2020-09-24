README.txt

Date:(5/15/19)
Group Names: Daniel Werminghausen, Sajana Wijesinghe 

uprog123.c -> main script test  main1,2,3

timetest.c -> created from timetest.c from $pcex/timetest.c.  
Similarity seen with cs341 mp5 file tickpack.c mentioned on Piazza
timetest.h -> header file 

proc.h -> initizations for counts of ticks and equenced chars, NPROC, process count
tunix.c -> inizalizations of counts and processes in init_proctab(), 
more prints to show counts in process0, shows number of calls to scheduler

tty.c -> add counter for chars enqueued and print out in tunix
int main1()
{
  int i;

  write(TTY1,"aaaaaaaaaa",10);
  write(TTY1, "zzz",3);
  for (i=0;i<DELAY;i++)	/* enough time to drain output q */
    ;
  write(TTY1,"AAAAAAAAAA",10);	/* see it start output again */
  return 2;
}

int main2()
{
  write(TTY1,"bbbbbbbbbb",10);
  return 4;
}

int main3()
{
  write(TTY1,"cccccccccc",10);
  return 6;
}
For (uprog123.c)
enqueCount for main one is 10+3+10 = 23
enqueCount for main two is 10 = 10
enqueCount for main three is 10 = 10
Process count in Sched function
Each call site to the scheduler should use a different integer for this parameter
(0,1,2,3)
tick counter in timetest.c

debuglog is working, printing out results before leaving back to tutor.
----------------------------------------------------------------------

Sched.c ->  scheduler set up, process count, scheduler function 
everything else the same
Sched.h -> given

fprintf.c -> given 
sequences.c -> given
script done with sequences.lnx

crt01.s -> given 
crt02.s -> given
crt03.s -> given
startuo0.s -> given
startup1.c -> given
ulibs.s -> given
sysentry.s -> given

tty.c -> enqueue count placed othewise same as given
tty.h -> header
tty_public.h -> header
tunistd.h -> header
tsystm.c -> header
tsyscall.h -> header

