#pragma once

#include <assert.h>

#include "Definitions.h"
#include "Utils.h"

namespace utils_tests
{
	// HOUSEKEEPING

	static int pass = 0, skip = 0, fail = 0;

	static void __info(const char* _namespace)
	{
		printf("\r[");
		utils::console::set_color(COLOR_GRAY, COLOR_BLACK);
		printf("INFO");
		utils::console::reset_color();
		printf("] Testing %s\n", _namespace);
	}

	static void __test(const char* message)
	{
		printf("\r[");
		utils::console::set_color(COLOR_GRAY, COLOR_BLACK);
		printf("----");
		utils::console::reset_color();
		printf("] Testing %s", message);
	}

	static void __skip(const char* message)
	{
		skip++;

		printf("\r[");
		utils::console::set_color(COLOR_DARK_YELLOW, COLOR_BLACK);
		printf("SKIP");
		utils::console::reset_color();
		printf("] Skipped %s\n", message);
	}

	static void __pass()
	{
		pass++;

		printf("\r[");
		utils::console::set_color(COLOR_GREEN, COLOR_BLACK);
		printf(" OK ");
		utils::console::reset_color();
		printf("]\n");
	}

	static void __fail()
	{
		fail++;

		printf("\r[");
		utils::console::set_color(COLOR_RED, COLOR_BLACK);
		printf("FAIL");
		utils::console::reset_color();
		printf("]\n");
	}

	static void __summary()
	{
		printf("\nTesting summary: [");
		utils::console::set_color(COLOR_GREEN, COLOR_BLACK);
		printf(" OK ");
		utils::console::reset_color();
		printf("] = %d | [", pass);
		utils::console::set_color(COLOR_DARK_YELLOW, COLOR_BLACK);
		printf("SKIP");
		utils::console::reset_color();
		printf("] = %d | [", skip);
		utils::console::set_color(COLOR_RED, COLOR_BLACK);
		printf("FAIL");
		utils::console::reset_color();
		printf("] = %d | ", fail);

		if (fail == 0)
		{
			printf("ALL TESTS ");
			utils::console::set_color(COLOR_GREEN, COLOR_BLACK);
			printf("PASSED");
			utils::console::reset_color();

		}
		else if (pass == 0)
		{
			printf("ALL TESTS ");
			utils::console::set_color(COLOR_RED, COLOR_BLACK);
			printf("FAILED");
			utils::console::reset_color();
		}
		else
		{
			printf("SOME TESTS ");
			utils::console::set_color(COLOR_RED, COLOR_BLACK);
			printf("FAILED");
			utils::console::reset_color();
		}

		printf("\n\n");
	}

	// TESTING METHODS

	static void __test_convert()
	{
		__info("utils::convert");

		{
			__test("utils::convert::ns_to_s() | Test: 1/1");
			utils::convert::ns_to_s(CLOCK::now() - CLOCK::now()) < 0.1 ? __pass() : __fail();
		}
	}

	static void __test_print()
	{
		__info("utils::print");
		
		{
			__test("utils::print::error() | Test: 1/1");
			__pass();
			utils::print::error("THIS IS TESTING ERROR MESSAGE!");
		}

		__skip("utils::print::usage()");
	}

	static void __test_string()
	{
		__info("utils::string");

		{
			{
				__test("utils::string::split_by_char() | Test: 1/2 (sep not in string)");
				std::vector<std::string> result;
				utils::string::split_by_char("abcd", ',', result);
				result == std::vector<std::string>({ "abcd" }) ? __pass() : __fail();
			}

			{
				__test("utils::string::split_by_char() | Test: 2/2 (sep is  in string)");
				std::vector<std::string> result;
				utils::string::split_by_char("a,b,c,d", ',', result);
				result == std::vector<std::string>({ "a", "b", "c", "d" }) ? __pass() : __fail();
			}
		}

		{
			{
				__test("utils::string::remove_char() | Test: 1/2 (char not in string)");
				std::string string = "nope";
				utils::string::remove_char(string, 'X');
				string == "nope" ? __pass() : __fail();
			}

			{
				__test("utils::string::remove_char() | Test: 2/2 (char is  in string)");
				std::string string = "noXpe";
				utils::string::remove_char(string, 'X');
				string == "nope" ? __pass() : __fail();
			}
		}
	}

	static void __test_vector()
	{
		__info("utils::vector");

		{
			{
				__test("utils::vector::sort() | Test: 1/2 (not sorted)");
				std::vector<int> vec({ 2, 3, 1, 5, 4 });
				utils::vector::sort(vec);
				vec == std::vector<int>({ 1, 2, 3, 4, 5 }) ? __pass() : __fail();
			}

			{
				__test("utils::vector::sort() | Test: 1/2 (pre-sorted)");
				std::vector<int> vec({ 1, 2, 3, 4, 5 });
				utils::vector::sort(vec);
				vec == std::vector<int>({ 1, 2, 3, 4, 5 }) ? __pass() : __fail();
			}
		}

		{
			{
				__test("utils::vector::contains() | Test: 1/2 (contains: no)");
				std::vector<int> vec({ 1, 2, 3, 4, 5 });
				utils::vector::contains(vec, 6) ? __fail() : __pass();
			}

			{
				__test("utils::vector::contains() | Test: 1/2 (contains: yes)");
				std::vector<int> vec({ 1, 2, 3, 4, 5 });
				utils::vector::contains(vec, 5) ? __pass() : __fail();
			}
		}

		{
			{
				__test("utils::vector::get_all_combinations() | Test: 1/1");

				std::vector<int> vec({ 1, 2, 3 });
				std::vector<std::vector<int>> expected(
					{
						std::vector<int>({1, 2, 3}),
						std::vector<int>({1, 3, 2}),
						std::vector<int>({2, 1, 3}),
						std::vector<int>({2, 3, 1}),
						std::vector<int>({3, 1, 2}),
						std::vector<int>({3, 2, 1})
					}
				);
				utils::vector::get_all_combinations(vec) == expected ? __pass() : __fail();
			}
		}
	}
	
	static void __test_number()
	{
		__info("utils::number");

		{
			{
				__test("utils::number::get_digits() | Test: 1/2 (Single digit number)");
				utils::number::get_digits(2) == std::vector<int64_t>({ 2 }) ? __pass() : __fail();
			}

			{
				__test("utils::number::get_digits() | Test: 2/2 (Multi digit number)");
				utils::number::get_digits(222) == std::vector<int64_t>({ 2, 2, 2 }) ? __pass() : __fail();
			}
		}

		{
			{
				__test("utils::number::is_palindromic() | Test: 1/4 (Yes, digits: even)");
				utils::number::is_palindromic("2112") ? __pass() : __fail();
			}

			{
				__test("utils::number::is_palindromic() | Test: 2/4 (Yes, digits: odd)");
				utils::number::is_palindromic("212") ? __pass() : __fail();
			}

			{
				__test("utils::number::is_palindromic() | Test: 3/4 (No, digits: even)");
				utils::number::is_palindromic("2132") ? __fail() : __pass();
			}

			{
				__test("utils::number::is_palindromic() | Test: 4/4 (No, digits: odd)");
				utils::number::is_palindromic("213") ? __fail() : __pass();
			}
		}

		{
			{
				__test("utils::number::is_prime() | Test: 1/2 (Yes)");
				utils::number::is_prime(13) ? __pass() : __fail();
			}

			{
				__test("utils::number::is_prime() | Test: 2/2 (No)");
				utils::number::is_prime(12) ? __fail() : __pass();
			}
		}

		{
			{
				__test("utils::number::is_pandigital() | Test: 1/2 (Yes)");
				utils::number::is_pandigital(102, 0, 2) ? __pass() : __fail();
			}

			{
				__test("utils::number::is_pandigital() | Test: 2/2 (No)");
				utils::number::is_pandigital(112, 0, 2) ? __fail() : __pass();
			}
		}

		{
			{
				__test("utils::number::dec_to_bin() | Test: 1/1 ");
				utils::number::dec_to_bin(5) == "101" ? __pass() : __fail();
			}
		}

		{
			{
				__test("utils::number::get_factorial() | Test: 1/1 ");
				utils::number::get_factorial(6) == BigNumber(720) ? __pass() : __fail();
			}
		}

		{
			{
				__test("utils::number::get_triangle_number() | Test: 1/1 ");
				utils::number::get_triangle_number(6) == 21 ? __pass() : __fail();
			}
		}

		{
			{
				__test("utils::number::get_biggest_prime_divisor() | Test: 1/1 ");
				utils::number::get_biggest_prime_divisor(123) == 41 ? __pass() : __fail();
			}
		}

		{
			{
				__test("utils::number::get_nth_prime() | Test: 1/1 ");
				utils::number::get_nth_prime(13) == 41 ? __pass() : __fail();
			}
		}

		{
			{
				__test("utils::number::get_primes_bellow() | Test: 1/1 ");
				std::vector<int64_t> expected({ 2, 3, 5, 7, 11, 13 });
				utils::number::get_primes_bellow(14) == expected ? __pass() : __fail();
			}
		}
	}

	// MAIN TESTING METHOD

	static void test_all()
	{
		__info("utils");
		__test_convert();
		// utils::console not testing - user can see if it works or not
		__test_print();
		__test_string();
		__test_vector();
		// utils::file   not testing - idk how withou adding another file, and I am too lazy to do that :p
		__test_number();
		__summary();
	}
}