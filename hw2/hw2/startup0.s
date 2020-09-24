# asm startup file
.globl _startup0exit

movl $0x3ffff0, %esp  
movl $0, %ebp
call _startupc         
_startup0exit:  
int $3                
