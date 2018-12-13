#ifndef _3MM_H
# define _3MM_H

#define SMALL_DATASET
#define DATA_TYPE_IS_FLOAT
#define USE_VECTOR
//#define PRINT_RESULTS

#include "config.h"

# if !defined(NI) && !defined(NJ) && !defined(NK) && !defined(NL) && !defined(NM)
/* Define sample dataset sizes. */
#  ifdef MINI_DATASET
#   define NI 16
#   define NJ 18
#   define NK 20
#   define NL 22
#   define NM 24
#  endif 

#  ifdef SMALL_DATASET
#   define NI 40
#   define NJ 50
#   define NK 60
#   define NL 70
#   define NM 80
#  endif 

#  ifdef MEDIUM_DATASET
#   define NI 180
#   define NJ 190
#   define NK 200
#   define NL 210
#   define NM 220
#  endif 

#  ifdef LARGE_DATASET
#   define NI 800
#   define NJ 900
#   define NK 1000
#   define NL 1100
#   define NM 1200
#  endif 

#  ifdef EXTRALARGE_DATASET
#   define NI 1600
#   define NJ 1800
#   define NK 2000
#   define NL 2200
#   define NM 2400
#  endif 


#endif /* !(NI NJ NK NL NM) */

# define _PB_NI POLYBENCH_LOOP_BOUND(NI,ni)
# define _PB_NJ POLYBENCH_LOOP_BOUND(NJ,nj)
# define _PB_NK POLYBENCH_LOOP_BOUND(NK,nk)
# define _PB_NL POLYBENCH_LOOP_BOUND(NL,nl)
# define _PB_NM POLYBENCH_LOOP_BOUND(NM,nm)

#endif /* !_3MM_H */
