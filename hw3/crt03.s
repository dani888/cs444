.globl _ustart3
.text
			
_ustart3:	
call _main3                  # call main3
pushl %eax                   # 
call _exit                   # call sysycall exit
