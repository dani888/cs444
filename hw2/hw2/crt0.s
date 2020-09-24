.globl _ustart
.text
			
_ustart:
call _main            # call main
pushl %eax            # 
call _exit            # call sysycall exit
