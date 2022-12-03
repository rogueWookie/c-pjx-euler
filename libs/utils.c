#include <stdio.h>

#include "utils.h"

void utils_timespec_diff ( 
        struct timespec * t2, 
        struct timespec * t1, 
        char* func)
{
    struct timespec dl;

    dl.tv_sec  = t1->tv_sec - t2->tv_sec;
    dl.tv_nsec = t1->tv_nsec - t2->tv_nsec;
    
    if (dl.tv_nsec < 0)
    {
        --dl.tv_sec;
        dl.tv_nsec += 1000000000L;
    }

    printf("\t%s: %lds, %ldns\n", func, dl.tv_sec, dl.tv_nsec);
}
