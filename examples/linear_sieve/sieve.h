#ifndef _SIEVE_H
# define _SIEVE_H

#define MINI_DATASET
#define DATA_TYPE_IS_INT
//#define USE_VECTOR
#define PRINT_RESULTS

#include "config.h"

# if !defined(N)
/* Define sample dataset sizes. */
#  ifdef MINI_DATASET
#   define N 100
#  endif

#  ifdef SMALL_DATASET
#   define N 1000
#  endif

#  ifdef MEDIUM_DATASET
#   define N 10000
#  endif

#  ifdef LARGE_DATASET
#   define N 1000000
#  endif

#  ifdef EXTRALARGE_DATASET
#   define N 10000000
#  endif


#endif /* !N */

#endif /* !_FLOYD_H */
