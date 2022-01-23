#ifndef UTILS_H
#define UTILS_H

#include <chrono>
#include <iostream>
#include <Windows.h>

#include "Definitions.h"
#include "Problems.h"

namespace utils
{
	namespace convert
	{
		static double ns_to_ms(CLOCK::duration ns)
		{
			return ns.count() / NANOSECONDS_IN_SECOND;
		}
	}

	namespace console
	{
		static void set_color(int foreground, int background)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreground + 16 * background);
		}

		static void reset_color()
		{
			utils::console::set_color(COLOR_DARK_WHITE, COLOR_BLACK);
		}
	}

	namespace print
	{
		static void problem_result(ProblemResult res)
		{
			printf("--- Problem %03d --- \n", res.problem_id);
			printf("    Result: %zu\n", res.result);
			printf("    Time:   %.6fs\n", utils::convert::ns_to_ms(res.time));
		}

		static void error(std::string message, bool error_wrap = true)
		{
			utils::console::set_color(COLOR_RED, COLOR_BLACK);
			if (error_wrap) std::cerr << "--- ERROR---" << std::endl;
			std::cerr << message << std::endl;
			if (error_wrap) std::cerr << "--- ERROR---" << std::endl;
			utils::console::reset_color();
		}

		static void usage(const std::string exe) {
			std::cerr <<
				"NAME:\n" <<
				"    " << NAME << " by " << ME << " / " << GITHUB_BASE_URL << ME << " / " << ME << EMAIL_DOMAIN << "\n" <<
				"\n" <<
				"USAGE:\n" <<
				"    " << exe << " COMMAND [subcommand]\n" <<
				"\n" <<
				"COMMANDS:\n" <<
				"    " << COMMAND_RUN_LONG << ", " << COMMAND_RUN_SHORT << "\n" <<
				"        Run project euler problem solver\n" <<
				"\n" <<
				"        subcommands:\n" <<
				"            " << SUBCOMMAND_RUN_ALL_LONG << ", " << SUBCOMMAND_RUN_ALL_SHORT << "    Solve all prolbems\n" <<
				"            " << SUBCOMMAND_RUN_ID << " <id>    Solve problem with ID <id> (<id> must de valid integer)\n" <<
				"    " << COMMAND_TEST_LONG << ", " << COMMAND_TEST_SHORT << "\n" <<
				"        Test UTILS class for incorrect results" << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	namespace prime
	{
		static size_t biggestPrimeDivisor(size_t n)
		{
			for (size_t number = 2; number < std::sqrt(n); number++) if (n % number == 0) n /= number;
			return n;
		}
	}
}

#endif // UTILS_H