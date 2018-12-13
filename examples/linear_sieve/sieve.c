#include "sieve.h"

int flag[N];
int prime[N], prime_cnt;

static
void print_array()
{
  int i, j;

  for (i = 0; i < prime_cnt; i++) {
      printf("%d ", &prime[i]);
  }

  printf ("\n", 0);
}

void kernel_linear_sieve(){
    int i, j, p;

    for(i = 2; i < N; i ++) {
        if(!flag[i]){
            prime[prime_cnt ++] = i;
        }
        for(j = 0; j < prime_cnt; j ++){
            p = prime[j] * i;
            if(p >= N){
                break;
            }
            flag[p] = 1;
            if(i % prime[j] == 0){
                break;
            }
        }
    }
}

void vector_linear_sieve(){
extern void sieve_with (int, int, int *, int, int *);

    int i;
    for(i = 2; i < N; i ++) {
        if(!flag[i]){
            //printf("PRIME! %d\n", &i);
            prime[prime_cnt ++] = i;
        }
        //printf("ROUND FOR %d\n", &i);
        sieve_with(N, i, prime, prime_cnt, flag);
    }
}

int cfile_main(int argc, char** argv)
{

#ifdef USE_VECTOR
#define KSIEVE vector_linear_sieve
#else
#define KSIEVE kernel_linear_sieve
#endif

    /* Run kernel. */
  KSIEVE ();

#ifdef PRINT_RESULTS
  print_array();
#endif

  return 0;
}
