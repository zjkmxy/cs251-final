#ifndef _CONFIG_H
#define _CONFIG_H

#define EXIT_SYSCALL 93
#define WRITE_SYSCALL 64
#define STDOUT 1

#define STACK_TOP (_stack_end)
#define STACK_SIZE 4096

#ifndef __ASSEMBLER__

extern void _prog_exit(unsigned char);

/* POLYBENCH common macros */
# define POLYBENCH_2D(var, dim1, dim2, ddim1, ddim2) var[dim1][dim2]
# define POLYBENCH_ARRAY(x) (x)
# define POLYBENCH_2D_ARRAY_DECL(var, type, dim1, dim2, ddim1, ddim2) type var[dim1][dim2]
# define POLYBENCH_LOOP_BOUND(x, y) (y)

#ifdef DATA_TYPE_IS_INT
#  define DATA_TYPE int
#  define DATA_PRINTF_MODIFIER "%d "
#  define SCALAR_VAL(x) (int)(x)
#endif 

#ifdef DATA_TYPE_IS_FLOAT
#  define DATA_TYPE float
#  define DATA_PRINTF_MODIFIER "%f "
#  define SCALAR_VAL(x) x##f
#  define SQRT_FUN(x) sqrtf(x)
#  define EXP_FUN(x) expf(x)
#  define POW_FUN(x,y) powf(x,y)
# endif

#endif // __ASSEMBLER__

#endif // _CONFIG_H
