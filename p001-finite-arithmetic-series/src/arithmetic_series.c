#include <stdio.h>
#include <time.h>
#include <math.h>

#include "arithmetic_series.h"


//  ---------------------------------------------------------------------------
//  Their solution is not divide by zero safe
static uint32_t sum_divisible_by ( uint32_t n, uint32_t m )
{
    uint32_t p = m / n;
    return n * (p * (p + 1)) / 2;
}

uint32_t project_eulers_solution ( 
        uint32_t n1, uint32_t n2, uint32_t n3, uint32_t m )
{
    return sum_divisible_by ( n1, m ) +
           sum_divisible_by ( n2, m ) -
           sum_divisible_by ( n3, m );
}

//  ---------------------------------------------------------------------------
//  This is not divide by zero safe
uint32_t loop_solution ( uint32_t mult1, uint32_t mult2, uint32_t maxi )
{
    //  mult1   -   first term to find all multiples of
    //  mult2   -   second term to find all multiples of
    //  maxi    -   max multiplier to not exceed

    uint32_t sum = 0;

    //  If multiples are zero, sum is zero, if maxi is bigger than mult1 
    //  and/or mult2 sum is also zero

    if ( (mult1 == 0) || (mult2 == 0) || (maxi < mult1) || (maxi < mult2) )
    {
        return 0;
    }

    //  We grab multiples of both terms at the same time. Therefore, no need 
    //  to find multiple of the product of both terms (e.g. 15). 

    for ( uint32_t i = 0; i <= maxi; i++ )
    {
        if ( (i % mult1 == 0) || (i % mult2 == 0) )
        {
            sum+=i;
        }
    }

    return sum;
}

//  ---------------------------------------------------------------------------
static uint32_t arithmetic_series_calculate ( 
        const uint32_t mult, const uint32_t maxi )
{
    //  mult    -   the first term in the finite arithmetic progression
    //  maxi    -   max multiplier to not exceed

    if ( (mult == 0) || (maxi < mult) )
    {
        return 0;
    }

    const uint32_t nterms = maxi / mult;
    const uint32_t lterm = mult + (nterms - 1) * mult;

    //  nterms  -   total number of terms in finite arithmetic progression
    //  leterm  -   the last term in the finite arithmetic progression

    return nterms * (mult + lterm) / 2;
}

uint32_t arithmetic_series_solution ( 
        uint32_t mult1, uint32_t mult2, uint32_t mult3, uint32_t maxi )
{
    return arithmetic_series_calculate ( mult1, maxi ) + 
           arithmetic_series_calculate ( mult2, maxi ) -
           arithmetic_series_calculate ( mult3, maxi );
}
