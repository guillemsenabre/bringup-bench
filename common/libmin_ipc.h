/* libmin_ipc.h */
typedef unsigned long long u64;

u64 read_cycles(void);
u64 read_time(void);
u64 read_inst(void);
double ipc_calc(u64 inst, u64 cycles);

