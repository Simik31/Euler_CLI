#include <set>
#include <string>

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

int64_t Problem_032::solve()
{
    std::set<int64_t> set;
    int64_t result = 0, mult;

    for (int64_t a = 1; a < 10000 + 1; a++)
    {
        for (int64_t b = 1; b < (10000 / a) + 1; b++)
        {
            mult = a * b;

            if (set.contains(mult))
                continue;

            std::string whole_number = std::to_string(a) + std::to_string(b) + std::to_string(mult);

            if (whole_number.length() != 9 || whole_number.find("0") != std::string::npos)
                continue;

            bool fail = false;
            for (int i = 1; !fail && i < 10; i++)
                fail = whole_number.find(i + '0') == std::string::npos;

            if (fail)
                continue;

            set.insert(mult);
            result += mult;
        }
    }

    return result;
}