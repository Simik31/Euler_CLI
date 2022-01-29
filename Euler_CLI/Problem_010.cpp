#include "Problems.h"
#include "Utils.h"

int64_t Problem_010::solve()
{
    int64_t prime_sum = 0;

    for (int64_t prime : utils::prime::get_bellow(2000000))
        prime_sum += prime;

    return prime_sum;
}