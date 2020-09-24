.globl _ustart2
.text
			
_ustart2:	
call _main2                  # call main2
pushl %eax                   # 
call _exit                   # call sysycall exit
