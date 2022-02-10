#include <string>

#include "Problems.h"
#include "Utils.h"

int64_t Problem_001::solve()
{
	int64_t sum = 0;
	for (int num = 1; num < 1000; num++)
		if (num % 5 == 0 || num % 3 == 0)
			sum += num;

	return sum;
}

int64_t Problem_002::solve()
{
	int64_t sum = 0, first = 0, second = 1, fibonacci_number;

	while (true)
	{
		fibonacci_number = first + second;

		if (fibonacci_number > 4000000)
			return sum;

		first = second;
		second = fibonacci_number;

		if (second % 2 == 0)
			sum += second;
	}
}

int64_t Problem_003::solve()
{
	return utils::number::get_biggest_prime_divisor(600851475143);
}

int64_t Problem_004::solve()
{
	int64_t multiple, highest_palindrome = -1;
	bool isPalindrome;

	for (int64_t number_1 = 999; number_1 >= 100; number_1--) {
		for (int64_t number_2 = number_1; number_2 >= 100; number_2--) {

			multiple = number_1 * number_2;

			if (multiple <= highest_palindrome)
				break;

			isPalindrome = true;

			std::string temp = std::to_string(multiple);

			for (int i = 0; isPalindrome && i < temp.length() / 2; i++)
				isPalindrome = temp[i] == temp[temp.length() - i - 1];

			if (isPalindrome)
				highest_palindrome = multiple;
		}
	}

	return highest_palindrome;
}

int64_t Problem_005::solve()
{
	for (int64_t number = 20;; number += 20)
		if (number % 19 == 0 && number % 17 == 0 && number % 13 == 0 && number % 11 == 0 && number % 9 == 0
			&& number % 18 == 0 && number % 7 == 0 && number % 16 == 0 && number % 15 == 0 && number % 8 == 0)
			return number;
}

int64_t Problem_006::solve()
{
	int64_t sum_of_squares = 0, sum = 0;

	for (int64_t number = 1; number <= 100; number++) {
		sum_of_squares += number * number;
		sum += number;
	}

	return sum * sum - sum_of_squares;
}

int64_t Problem_007::solve()
{
	return utils::number::get_nth_prime(10001);
}

int64_t Problem_008::solve()
{
	std::string data = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	int64_t greatest = -1;

	for (int64_t position = 0; position < data.length() - 13; position++) {
		int64_t multiple = 1;

		for (int64_t i = 0; i < 13 && multiple != 0; i++)
			multiple *= data[position + i] - '0';

		if (multiple > greatest)
			greatest = multiple;
	}

	return greatest;
}

int64_t Problem_009::solve()
{
	for (int64_t a = 1; a < 1000; a++)
		for (int64_t b = a + 1; b < 1000 - a + 1; b++)
			for (int64_t c = b + 1; c < 1000 - a - b + 1; c++)
				if (a + b + c == 1000 && a * a + b * b == c * c)
					return a * b * c;
}

int64_t Problem_010::solve()
{
	int64_t prime_sum = 0;

	for (int64_t prime : utils::number::get_primes_bellow(2000000))
		prime_sum += prime;

	return prime_sum;
}