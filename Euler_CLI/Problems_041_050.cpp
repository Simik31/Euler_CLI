#include <set>
#include <string>

#include "Problems.h"
#include "Utils.h"

int64_t Problem_041::solve()
{
    for (int64_t num = 7654321;; num--)
    {
        if (utils::prime::is_prime(num) == false)
            continue;

        std::vector<int64_t> digits = utils::number::get_digits(num);

        if (utils::vector::contains(digits, 0i64) == true)
            continue;

        std::set<int64_t> seen;

        for (int64_t digit : digits)
        {
            if (digit > digits.size())
                break;

            seen.insert(digit);
        }

        if (seen.size() == digits.size())
            return num;
    }
}