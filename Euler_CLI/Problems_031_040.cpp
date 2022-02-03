#include "Problems.h"

int64_t Problem_031::solve()
{
    int64_t sum = 0;

    for (int64_t pound2 = 200; pound2 >= 0; pound2 -= 200)
        for (int64_t pound1 = pound2; pound1 >= 0; pound1 -= 100)
            for (int64_t pence50 = pound1; pence50 >= 0; pence50 -= 50)
                for (int64_t pence20 = pence50; pence20 >= 0; pence20 -= 20)
                    for (int64_t pence10 = pence20; pence10 >= 0; pence10 -= 10)
                        for (int64_t pence5 = pence10; pence5 >= 0; pence5 -= 5)
                            for (int64_t pence2 = pence5; pence2 >= 0; pence2 -= 2)
                                sum++;

    return sum;
}