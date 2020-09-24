.globl _syscallc, _syscall      

_syscall:       
pushl %edx          # push edx, ecx, ebx, eax
pushl %ecx
pushl %ebx
pushl %eax
call _syscallc      # call c trap routine in tunix.c
popl %eax   		# pop eax, ebx, ecx, edx
popl %ebx  
popl %ecx
popl %edx
iret

