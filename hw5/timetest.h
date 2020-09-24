#include <cpu.h>

#define TEN_MS 0x2e9d
// #define TEN_MIL_SEC 0x2e9a
#define Quantumax 5

extern int total_time;
char *nmb;
/* Start ticking service */
void init_ticks(void);

/* Activate time */
int set_timer(IntHandler *function, int time, int runtime);

/* Shut down ticking service */
void shutdown_ticks(void);
