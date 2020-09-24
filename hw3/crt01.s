.globl _ustart1
.text
			
_ustart1:	
call _main1                  # call main1
pushl %eax                   # 
call _exit                   # call sysycall exit
