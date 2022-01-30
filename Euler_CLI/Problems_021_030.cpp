#include "Problems.h"

int64_t Problem_021::solve()
{
    int64_t sum = 0, num1, num2;

    for (int64_t i = 1; i <= 10000; i++) {
        num1 = num2 = 0;

        for (int64_t j = 1; j < i; j++)
            if (i % j == 0)
                num1 += j;

        for (int64_t j = 1; j < num1; j++)
            if (num1 % j == 0)
                num2 += j;

        if (num1 != num2 && i == num2)
            sum += num2;
    }

    return sum;
}