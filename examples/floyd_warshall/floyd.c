/**
 * This version is stamped on May 10, 2016
 *
 * Contact:
 *   Louis-Noel Pouchet <pouchet.ohio-state.edu>
 *   Tomofumi Yuki <tomofumi.yuki.fr>
 *
 * Web address: http://polybench.sourceforge.net
 */
/* floyd-warshall.c: this file is part of PolyBench/C */

#include "floyd.h"


/* Array initialization. */
static
void init_array (int n,
		 DATA_TYPE POLYBENCH_2D(path,N,N,n,n))
{
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      path[i][j] = i*j%7+1;
      if ((i+j)%13 == 0 || (i+j)%7==0 || (i+j)%11 == 0)
         path[i][j] = 999;
    }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
		 DATA_TYPE POLYBENCH_2D(path,N,N,n,n))

{
  extern int printf(char* fmt, void* arg);
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      if ((i * n + j) % 20 == 0) printf ("\n", 0);
      printf (DATA_PRINTF_MODIFIER, &path[i][j]);
    }

  printf ("\n", 0);
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_floyd_warshall(int n,
			   DATA_TYPE POLYBENCH_2D(path,N,N,n,n))
{
  int i, j, k;

#pragma scop
  for (k = 0; k < _PB_N; k++) {
    for(i = 0; i < _PB_N; i++) {
	    for (j = 0; j < _PB_N; j++) {
        path[i][j] = path[i][j] < path[i][k] + path[k][j] ?
                     path[i][j] : path[i][k] + path[k][j];
      }
    }
  }
#pragma endscop

}

static
void vector_floyd_warshall(int n,
			   DATA_TYPE POLYBENCH_2D(path,N,N,n,n))
{
  extern void dis_relax (int, int *, int, int *);
  extern void fdis_relax (int, float *, float, float *);
#ifdef DATA_TYPE_IS_FLOAT
#define DISRELAX fdis_relax
#else
#define DISRELAX dis_relax
#endif

  int i, j, k;

#pragma scop
  for (k = 0; k < _PB_N; k++) {
    for(i = 0; i < _PB_N; i++) {
	    DISRELAX(_PB_N, path[i], path[i][k], path[k]);
    }
  }
#pragma endscop

}


/* Variable declaration/allocation. */
POLYBENCH_2D_ARRAY_DECL(path, DATA_TYPE, N, N, n, n);

int cfile_main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int n = N;

  /* Initialize array(s). */
  init_array (n, POLYBENCH_ARRAY(path));

#ifdef USE_VECTOR
#define KFLOYD vector_floyd_warshall
#else
#define KFLOYD kernel_floyd_warshall
#endif

  /* Run kernel. */
  KFLOYD (n, POLYBENCH_ARRAY(path));

#ifdef PRINT_RESULTS
  print_array(n, path);
#endif

  return 0;
}
