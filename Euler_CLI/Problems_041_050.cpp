#include <set>
#include <string>

#include "Problems.h"
#include "Utils.h"

int64_t Problem_041::solve()
{
    for (int64_t num = 7654321;; num--)
    {
        if (utils::number::is_prime(num) == false)
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

int64_t Problem_042::solve()
{
    std::vector<int64_t> triangle_numbers;
    int64_t counter = 0;

    for (int64_t n = 1; n <= 26; n++)
        triangle_numbers.push_back(utils::number::get_triangle_number(n));

    std::vector<std::string> words;
    utils::string::split_by_char(utils::file::read_single_line("../data/042.txt"), ',', words);

    for (std::string word : words)
    {
        utils::string::remove_char(word, '"');

        int64_t word_sum = 0;

        for (int64_t i = 0; i < word.length(); i++)
            word_sum += word[i] - '@';

        if (utils::vector::contains(triangle_numbers, word_sum))
            counter++;
    }

    return counter;
}

int64_t Problem_043::solve()
{
    int64_t sum = 0, num;
    std::vector<int64_t> digits({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }), divisors({ 2, 3, 5, 7, 11, 13, 17 });

    for (std::vector<int64_t> number : utils::vector::get_all_combinations(digits))
    {
        if (number[0] == 0)
            continue;

        bool allDivs = true;

        for (int64_t k = 0; allDivs && k < divisors.size(); k++)
            allDivs = (number[k + 1] * 100 + number[k + 2] * 10 + number[k + 3]) % divisors[k] == 0;

        num = 0;

        if (allDivs)
            for (int64_t digit : number)
                num = num * 10 + digit;

        sum += num;
    }

    return sum;
}

int64_t Problem_044::solve()
{
    std::vector<int64_t> pentagonalNumbers;

    for (int64_t n = 1000; n <= 3250; n++)
        pentagonalNumbers.push_back(utils::number::get_pentagonal_number(n));

    for (int64_t j = 0;; j++)
    {
        int64_t a = pentagonalNumbers[j];

        for (int64_t k = j; k < pentagonalNumbers.size(); k++)
        {
            int64_t b = pentagonalNumbers[k];

            if (utils::vector::contains(pentagonalNumbers, a + b) && utils::vector::contains(pentagonalNumbers, b - a))
                return std::abs(b - a);
        }
    }
}

int64_t Problem_045::solve()
{
    std::set<int64_t> P, H;

    for (int64_t add = 1;; add++) {
        int64_t check = utils::number::get_triangle_number(285 + add);

        P.insert(utils::number::get_pentagonal_number(165 + add));
        H.insert(utils::number::get_hexagonal_number(143 + add));

        if (P.contains(check) && H.contains(check))
            return check;
    }
}

int64_t Problem_046::solve()
{
    std::vector<int64_t> primes;
    primes.push_back(2);

    for (int64_t num = 3;; num += 2) 
    {
        if (utils::number::is_prime(num))
            continue;

        std::vector<int64_t> extend = utils::number::get_primes_in_range(primes.size() - 1, num);
        primes.insert(primes.end(), extend.begin(), extend.end());
        bool res = true;

        for (int64_t i = 0; res && i < primes.size(); i++)
        {
            for (int64_t m = 1; res; m++)
            {
                int64_t composite = primes[i] + 2 * m * m;

                if (composite > num)
                    break;

                res = composite != num;
            }
        }

        if (res)
            return num;
    }
}

int64_t Problem_047::solve()
{
    for (int64_t i = 132951;; i += 3)
        if (utils::number::get_primes_divisors(i).size() == 4)
            if (utils::number::get_primes_divisors(i + 1).size() == 4)
                if (utils::number::get_primes_divisors(i + 2).size() == 4)
                    if (utils::number::get_primes_divisors(i + 3).size() == 4)
                        return i;
}

int64_t Problem_048::solve()
{
    BigInteger num = 0;

    for (int i = 1; i <= 1000; i++)
        num += utils::bigint::pow(i, i);

    int64_t result = 0;
    for (int digit : utils::bigint::get_last_n_digits(num, 10))
        result = result * 10 + digit;

    return result;
}

int64_t Problem_049::solve()
{
    std::vector<int64_t> digits[3];

    for (uint64_t num_1 = 1488;; num_1++)
    {
        std::set<int> seen;

        if (utils::number::is_prime(num_1) == false)
            continue;

        for (int digit : (digits[0] = utils::number::get_digits(num_1)))
            seen.insert(digit);

        uint64_t num_2 = num_1 + 3330;

        if (utils::number::is_prime(num_2) == false)
            continue;

        bool allOK_2 = true;

        for (int digit : (digits[1] = utils::number::get_digits(num_2)))
            if (!seen.contains(digit))
                allOK_2 = false;

        if (allOK_2 == false)
            continue;

        uint64_t num_3 = num_2 + 3330;

        if (utils::number::is_prime(num_3) == false)
            continue;

        bool allOK_3 = true;

        for (int digit : (digits[2] = utils::number::get_digits(num_3)))
            if (!seen.contains(digit))
                allOK_3 = false;

        if (allOK_3)
            break;
    }

    int64_t result = 0;

    for (int i = 0; i < 3; i++)
    {
        std::reverse(digits[i].begin(), digits[i].end());

        for (int digit : digits[i])
            result = result * 10 + digit;
    }

    return result;
}