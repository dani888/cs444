/* call startup from startup0.s*/
/* C startup file, called from startup0.s-- */
void clr_bss(void);
void init_devio(void);
void kernal_init(void);
void startupc(void);
void startupc()
{
	clr_bss();                    /* clear BSS area (uninitialized data) */
	init_devio();                 /* latch onto Tutor-supplied info, code */
	kernal_init();                	 /* calls k_init instead of user-supplied main */
}
