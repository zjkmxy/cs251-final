#ifndef _CONFIG_H
#define _CONFIG_H

#define EXIT_SYSCALL 93
#define WRITE_SYSCALL 64
#define STDOUT 1

#define STACK_TOP (_stack_end)
#define STACK_SIZE 4096

#ifndef __ASSEMBLER__
#ifdef __GNUC__

extern void _prog_exit(unsigned char);

#endif // __GNUC__
#endif // __ASSEMBLER__

#endif // _CONFIG_H
