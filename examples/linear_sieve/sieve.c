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
            flag[i] = prime_cnt;
        }
        for(j = 0; j < flag[i]; j ++){
            p = prime[j] * i;
            if(p >= N){
                break;
            }
            flag[p] = j + 1;
        }
    }
}

void vector_linear_sieve(){
    extern void sieve_with2 (int, int, int *, int, int *);

    int i, j, p;
    for(i = 2; i < N; i ++) {
        if(!flag[i]){
            prime[prime_cnt ++] = i;
            flag[i] = prime_cnt;
        }
        if (flag[i] > 3){
            sieve_with2(N, i, prime, flag[i], flag);
        }else{
            for(j = 0; j < flag[i]; j ++){
                p = prime[j] * i;
                if(p >= N){
                    break;
                }
                flag[p] = j + 1;
            }
        }
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
