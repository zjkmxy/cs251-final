#ifndef _FLOYD_H
# define _FLOYD_H

#define LARGE_DATASET
#define DATA_TYPE_IS_FLOAT
#define USE_VECTOR
//#define PRINT_RESULTS

#include "config.h"

# if !defined(N)
/* Define sample dataset sizes. */
#  ifdef MINI_DATASET
#   define N 60
#  endif

#  ifdef SMALL_DATASET
#   define N 180
#  endif

#  ifdef MEDIUM_DATASET
#   define N 500
#  endif

#  ifdef LARGE_DATASET
#   define N 2800
#  endif

#  ifdef EXTRALARGE_DATASET
#   define N 5600
#  endif


#endif /* !N */

# define _PB_N POLYBENCH_LOOP_BOUND(N,n)

#endif /* !_FLOYD_H */
