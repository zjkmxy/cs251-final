#ifndef _SIEVE_H
# define _SIEVE_H

#define N 100000
#define USE_VECTOR
//#define PRINT_RESULTS

#include "config.h"

# if !defined(N)
/* Define sample dataset sizes. */
#  ifdef MINI_DATASET
#   define N 200
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
