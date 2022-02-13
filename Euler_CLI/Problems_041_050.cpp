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