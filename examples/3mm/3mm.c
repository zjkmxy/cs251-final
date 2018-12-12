/**
 * This version is stamped on May 10, 2016
 *
 * Contact:
 *   Louis-Noel Pouchet <pouchet.ohio-state.edu>
 *   Tomofumi Yuki <tomofumi.yuki.fr>
 *
 * Web address: http://polybench.sourceforge.net
 */
/* 3mm.c: this file is part of PolyBench/C */

/* Include benchmark-specific header. */
#include "3mm.h"


/* Array initialization. */
static
void init_array(int ni, int nj, int nk, int nl, int nm,
		DATA_TYPE POLYBENCH_2D(A,NI,NK,ni,nk),
		DATA_TYPE POLYBENCH_2D(B,NK,NJ,nk,nj),
		DATA_TYPE POLYBENCH_2D(C,NJ,NM,nj,nm),
		DATA_TYPE POLYBENCH_2D(D,NM,NL,nm,nl))
{
  int i, j;

  for (i = 0; i < ni; i++) {
    for (j = 0; j < nk; j++) {
      A[i][j] = (DATA_TYPE) ((i*j+1) % ni);
#ifdef DATA_TYPE_IS_FLOAT
      A[i][j] /= (DATA_TYPE) (5*ni);
#endif
    }
  }
  for (i = 0; i < nk; i++) {
    for (j = 0; j < nj; j++) {
      B[i][j] = (DATA_TYPE) ((i*(j+1)+2) % nj);
#ifdef DATA_TYPE_IS_FLOAT
      B[i][j] /= (DATA_TYPE) (5*nj);
#endif
    }
  }
  for (i = 0; i < nj; i++) {
    for (j = 0; j < nm; j++) {
      C[i][j] = (DATA_TYPE) (i*(j+3) % nl);
#ifdef DATA_TYPE_IS_FLOAT
      C[i][j] /= (DATA_TYPE) (5*nl);
#endif
    }
  }
  for (i = 0; i < nm; i++) {
    for (j = 0; j < nl; j++) {
      D[i][j] = (DATA_TYPE) ((i*(j+2)+2) % nk);
#ifdef DATA_TYPE_IS_FLOAT
      D[i][j] /= (DATA_TYPE) (5*nk);
#endif
    }
  }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int ni, int nl,
		 DATA_TYPE POLYBENCH_2D(G,NI,NL,ni,nl))
{
  extern int printf(char* fmt, void* arg);
  int i, j;

  for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j++) {
	if ((i * ni + j) % 20 == 0) printf ("\n", 0);
	printf (DATA_PRINTF_MODIFIER, &G[i][j]);
    }

  printf ("\n", 0);
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_3mm(int ni, int nj, int nk, int nl, int nm,
		DATA_TYPE POLYBENCH_2D(E,NI,NJ,ni,nj),
		DATA_TYPE POLYBENCH_2D(A,NI,NK,ni,nk),
		DATA_TYPE POLYBENCH_2D(B,NK,NJ,nk,nj),
		DATA_TYPE POLYBENCH_2D(F,NJ,NL,nj,nl),
		DATA_TYPE POLYBENCH_2D(C,NJ,NM,nj,nm),
		DATA_TYPE POLYBENCH_2D(D,NM,NL,nm,nl),
		DATA_TYPE POLYBENCH_2D(G,NI,NL,ni,nl))
{
  int i, j, k;

#pragma scop
  /* E := A*B */
  for (i = 0; i < _PB_NI; i++)
    for (j = 0; j < _PB_NJ; j++)
      {
	E[i][j] = SCALAR_VAL(0.0);
	for (k = 0; k < _PB_NK; ++k)
	  E[i][j] += A[i][k] * B[k][j];
      }
  /* F := C*D */
  for (i = 0; i < _PB_NJ; i++)
    for (j = 0; j < _PB_NL; j++)
      {
	F[i][j] = SCALAR_VAL(0.0);
	for (k = 0; k < _PB_NM; ++k)
	  F[i][j] += C[i][k] * D[k][j];
      }
  /* G := E*F */
  for (i = 0; i < _PB_NI; i++)
    for (j = 0; j < _PB_NL; j++)
      {
	G[i][j] = SCALAR_VAL(0.0);
	for (k = 0; k < _PB_NJ; ++k)
	  G[i][j] += E[i][k] * F[k][j];
      }
#pragma endscop

}

static
void vector_3mm(int ni, int nj, int nk, int nl, int nm,
		DATA_TYPE POLYBENCH_2D(E,NI,NJ,ni,nj),
		DATA_TYPE POLYBENCH_2D(A,NI,NK,ni,nk),
		DATA_TYPE POLYBENCH_2D(B,NK,NJ,nk,nj),
		DATA_TYPE POLYBENCH_2D(F,NJ,NL,nj,nl),
		DATA_TYPE POLYBENCH_2D(C,NJ,NM,nj,nm),
		DATA_TYPE POLYBENCH_2D(D,NM,NL,nm,nl),
		DATA_TYPE POLYBENCH_2D(G,NI,NL,ni,nl))
{
  extern int dotprod(int, int*, int*, int);
  extern float fdotprod(int, float*, float*, unsigned int);
#ifdef DATA_TYPE_IS_FLOAT
#define DOTPROD fdotprod
#else
#define DOTPROD dotprod
#endif
  int i, j, k;

#pragma scop
  /* E := A*B */
  for (i = 0; i < _PB_NI; i++) {
    for (j = 0; j < _PB_NJ; j++) {
	    E[i][j] = DOTPROD(_PB_NK, &A[i][0], &B[0][j], sizeof(B[0]));
    }
  }
  /* F := C*D */
  for (i = 0; i < _PB_NJ; i++) {
    for (j = 0; j < _PB_NL; j++) {
	    F[i][j] = DOTPROD(_PB_NM, &C[i][0], &D[0][j], sizeof(D[0]));
    }
  }
  /* G := E*F */
  for (i = 0; i < _PB_NI; i++) {
    for (j = 0; j < _PB_NL; j++) {
	    G[i][j] = DOTPROD(_PB_NJ, &E[i][0], &F[0][j], sizeof(F[0]));
    }
  }
#pragma endscop

}

/* Variable declaration/allocation. */
POLYBENCH_2D_ARRAY_DECL(E, DATA_TYPE, NI, NJ, ni, nj);
POLYBENCH_2D_ARRAY_DECL(A, DATA_TYPE, NI, NK, ni, nk);
POLYBENCH_2D_ARRAY_DECL(B, DATA_TYPE, NK, NJ, nk, nj);
POLYBENCH_2D_ARRAY_DECL(F, DATA_TYPE, NJ, NL, nj, nl);
POLYBENCH_2D_ARRAY_DECL(C, DATA_TYPE, NJ, NM, nj, nm);
POLYBENCH_2D_ARRAY_DECL(D, DATA_TYPE, NM, NL, nm, nl);
POLYBENCH_2D_ARRAY_DECL(G, DATA_TYPE, NI, NL, ni, nl);

int cfile_main()
{
  /* Retrieve problem size. */
  int ni = NI;
  int nj = NJ;
  int nk = NK;
  int nl = NL;
  int nm = NM;

  /* Initialize array(s). */
  init_array (ni, nj, nk, nl, nm,
	      POLYBENCH_ARRAY(A),
	      POLYBENCH_ARRAY(B),
	      POLYBENCH_ARRAY(C),
	      POLYBENCH_ARRAY(D));

#ifdef USE_VECTOR
#define K3MM vector_3mm
#else
#define K3MM kernel_3mm
#endif

  /* Run kernel. */
  K3MM (ni, nj, nk, nl, nm,
	      POLYBENCH_ARRAY(E),
	      POLYBENCH_ARRAY(A),
	      POLYBENCH_ARRAY(B),
	      POLYBENCH_ARRAY(F),
	      POLYBENCH_ARRAY(C),
	      POLYBENCH_ARRAY(D),
	      POLYBENCH_ARRAY(G));

#ifdef PRINT_RESULTS
  print_array(ni, nl, G);
#endif

  return 0;
}
