#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "arithmetic_series.h"

int main()
{
    //  Test against inputs of the problem

    assert( project_eulers_solution(3, 5, 15, 999) == 
            loop_solution(3, 5, 999) );

    assert( project_eulers_solution(3, 5, 15, 999) ==
            arithmetic_series_solution(3, 5, 15, 999) );

    assert( loop_solution(3, 5, 999) ==
            arithmetic_series_solution(3, 5, 15, 999) );

}
