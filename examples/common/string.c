#include "config.h"

char formatbuf[300];

void reverse(char* st, char* ed){
    for(; st < ed; st ++, ed --) {
        *st ^= *ed;
        *ed ^= *st;
        *st ^= *ed;
    }
}

unsigned int itoa(char* p, int i) {
    char *ret = p;
    unsigned int sign = 0;

    if(i < 0){
        *ret = '-';
        ret ++;
        p ++;
        sign = 1;
        i = -i;
    }
    do{
        *ret = '0' + (i % 10);
        ret ++;
        i /= 10;
    } while(i > 0);
    reverse(p, ret - 1);
    return ret - p + sign;
}

unsigned int ftoa(char* p, float f) {
    char *ret = p;
    ret += itoa(ret, (int)f);
    *ret = '.';
    ret ++;
    if(f < 0) {
        f = -f;
    }
    f -= (int)f;
    f *= 10.0f;
    ret += itoa(ret, (int)(f));
    f -= (int)f;
    f *= 10.0f;
    ret += itoa(ret, (int)(f + 0.5f));
    return ret - p;
}

// VA_ARG seems to behave differently in RISC-V
int printf(char* fmt, void* arg) {
    extern int print (void*, char*, unsigned int);
    
    char *ret = formatbuf;
    int flag = 0;

    for(; *fmt; fmt ++) {
        if(*fmt != '%' && !flag) {
            *ret = *fmt;
            ret ++;
        } else if(flag) {
            flag = 0;
            if (*fmt == 'f'){
                ret += ftoa(ret, *(float*)arg);
            }else if(*fmt == 'd'){
                ret += itoa(ret, *(int*)arg);
            }else{
                *ret = *fmt;
                ret ++;
            }
        } else {
            flag = 1;
        }
    }

    return print(0, formatbuf, ret - formatbuf);
}