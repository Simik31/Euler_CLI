#include "Problems.h"
#include "Utils.h"

int64_t Problem_003::solve()
{
	return utils::prime::get_biggest_prime_divisor(600851475143);
}