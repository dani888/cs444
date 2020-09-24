# README
Group: Daniel Werminghausen, Sajana Wijesinghe (4/16/19)

hw2 Files from hw2 solutions :
tty_public.h: no change

tsyscall.h: no change

ioconf.h: no change

tty.h: no change

tsytem.h: no change

startup0.s: no change

startup1.c no change

sysentry.s: no change

io.c: no change

iconf.c: no change

tunistd.h: no change

uprog.c no change

ulibs.s no change

-----------------------------------------------------------------
tty.c: terminal driver, from hw2 but changed to block, unblock (sleep/wakeup)

tunix.c: extern ustart1/ustart2/ustart3 and schedulue. 
new functions added to tunix from hw2 solutions. processTable(), processzero(), added to sysexit.
typedef enum process_number created for 3 users programs of uprog initialized  SAVED_ESP and SAVED_PC
to process all 3 user programs. Many meathods used from proc.h

proc.h: esp1, esp2, esp3 memory locations initalized for exit codoes of uprog1.c / uprog2.c / uprog3.c

sched.c: sleep function 

Sched.h: functions schedule, wakeup, sleep initalized. 

crt01.s   same as crt0.s from hw2 solutions but main = main1 and _ustart1
crt02s		same as crt0.s from hw2 solutions but main = main2 and _ustart2
crt03.s 	same as crt0.s from hw2 solutions but main = main2 and _ustart3

uprog1.c 	given 
uprog2.c 	given
uprog3.c 	given


discussion: If sleep function called:

