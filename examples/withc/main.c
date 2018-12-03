#include "config.h"

char global_arr[] = "hello,world\n";

int cfile_main()
{
    extern void say_hello_world_in_asm();
    extern int print_line(void*, char*, unsigned int);
    print_line(0, "HELLO WORLD\n", 12);
    say_hello_world_in_asm();
    print_line(0, global_arr, sizeof(global_arr));
    return 5253; // This will show 133 in gem5
}
