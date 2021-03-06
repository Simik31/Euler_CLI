#include <set>
#include <string>

#include "Problems.h"
#include "Utils.h"

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

int64_t Problem_033::solve()
{
    int64_t dp = 1, np = 1, gcd = 1;

    for (int64_t c = 1; c < 10; c++)
        for (int64_t d = 1; d < c; d++)
            for (int64_t n = 1; n < d; n++)
                if ((n * 10 + c) * d == (c * 10 + d) * n) 
                {
                    np *= n;
                    dp *= d;
                }

    for (int64_t i = 1; i <= np; i++)
        if (np % i == 0 && dp % i == 0)
            gcd = i;

    return dp / gcd;
}

int64_t Problem_034::solve()
{
    int64_t total = 0;

    for (int64_t num = 3; num < 41000; num++) 
    {
        std::string s_num = std::to_string(num);
        int64_t f_sum = 0;

        for (int64_t i = 0; num > f_sum && i < s_num.length(); i++)
            f_sum += utils::number::get_factorial((uint64_t) s_num[i] - '0').toUnsignedLong();

        if (num == f_sum)
            total += num;
    }

    return total;
}

int64_t Problem_035::solve()
{
    int64_t counter = 0;
    std::string s_num;

    for (int64_t num = 2; num < 1000001; num++) {
        s_num = std::to_string(num);

        bool arePrime = true;
        for (int64_t i = 0; arePrime && i < s_num.length(); i++)
            arePrime = utils::number::is_prime(std::stoll(s_num.substr(i) + s_num.substr(0, i)));

        if (arePrime)
            counter++;
    }

    return counter;
}

int64_t Problem_036::solve()
{
    int64_t sum = 0;

    for (int64_t num = 1; num < 1000001; num++)
        if (utils::number::is_palindromic(std::to_string(num)) && utils::number::is_palindromic(utils::number::dec_to_bin(num)))
            sum += num;

    return sum;
}

int64_t Problem_037::solve()
{
    int64_t sum = 0, counter = 0;

    for (int64_t num = 11; counter < 11; num++)
    {
        if (utils::number::is_prime(num))
        {
            std::string s_num = std::to_string(num);
            bool arePrime = true;

            for (int64_t i = 0; arePrime && i < s_num.length() - 1; i++)
                arePrime = utils::number::is_prime(std::stoll(s_num.substr(0, i + 1))) && utils::number::is_prime(std::stoll(s_num.substr(i + 1, s_num.length() - i)));

            if (arePrime)
            {
                sum += num;
                counter++;
            }
        }
    }

    return sum;
}

int64_t Problem_038::solve()
{
    int64_t biggest = 0;

    for (int64_t number = 1; number < 10000; number++) {
        std::string product;
        std::set<char> seen;

        for (int64_t i = 1; product.length() < 9; i++) {
            std::string mul = std::to_string(number * i);
            product += mul;

            if (product.find("0") != std::string::npos)
                break;

            for (char c : mul)
                seen.insert(c);
        }

        if (seen.size() == 9 && product.length() == 9 && std::stoll(product) > biggest)
            biggest = std::stoll(product);
    }

    return biggest;
}

int64_t Problem_039::solve()
{
    int64_t max = 0, max_count = 0, counter;

    for (int64_t p = 1; p < 1001; p++)
    {
        counter = 0;

        for (int64_t a = 1; a < 400; a++)
            for (int64_t b = 1; b < 400; b++)
                if (a + b + std::sqrt(a * a + b * b) == p)
                    counter++;

        if (counter > max_count)
        {
            max = p;
            max_count = counter;
        }
    }

    return max;
}

int64_t Problem_040::solve()
{
    std::string number;
    int64_t result = 1, pos = 0;

    for (int64_t i = 1; number.length() < 1000000; i++)
    {
        number += std::to_string(i);

        if (number.length() > pos)
        {
            result *= number[pos] - '0';
            pos = pos * 10 + 9;
        }
    }

    return result;
}