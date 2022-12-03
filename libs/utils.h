#ifndef __UTILS_H__
#define __UTILS_H__

#include <time.h>
#include <stdint.h>

void utils_timespec_diff ( 
        struct timespec * t2, 
        struct timespec * t1, 
        char* func );

#endif /*__UTILS_H__*/
