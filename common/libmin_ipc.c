#include "libmin_ipc.h"
#include "libmin.h"
#include "libtarg.h"

/* Read user-space performance counters */
/* and provide methods to calculate ipc */
/* using cycle, time and instret	*/

/* Don't use sdtint.h or inttypes.h to  */
/* stay within the scope of the 	*/
/* bringup-bench repository.		*/

/* Be aware this code will silently 	*/
/* fail in rv32 systems 		*/

typedef unsigned long long u64;

_Static_assert(sizeof(u64) == 8, "u64 must be 64-bit");

u64
read_cycles(void) {
	u64 cycles;
	asm volatile ("rdcycle %0" : "=r" (cycles));
	
	return cycles;
}

u64
read_time(void) {
	u64 time;
	asm volatile ("rdtime %0" : "=r" (time));
	
	return time;
}

u64
read_inst(void) {
	u64 inst;
	asm volatile ("rdinstret %0" : "=r" (inst));
	
	return inst;
}

double
ipc_calc(u64 inst, u64 cycles) {
	return cycles ? (double)inst / (double)cycles : 0.0;
}
