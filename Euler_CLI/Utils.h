#ifndef UTILS_H
#define UTILS_H

#include <chrono>
#include <iostream>
#include <Windows.h>

#include "Definitions.h"
#include "Problems.h"

class Utils
{
public:
	static double ns_to_ms(CLOCK::duration ns)
	{
		return ns.count() / NANOSECONDS_IN_SECOND;
	}

	static void print_problem_result(ProblemResult res)
	{
		printf("--- Problem %03d --- \n", res.problem_id);
		printf("    Result: %zu\n", res.result);
		printf("    Time:   %.6fs\n", Utils::ns_to_ms(res.time));
	}

	static void set_color(int foreground, int background)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreground + 16 * background);
	}

	static void reset_color()
	{
		Utils::set_color(COLOR_DARK_WHITE, COLOR_BLACK);
	}

	static void print_error(std::string message, bool error_wrap = true)
	{
		Utils::set_color(COLOR_RED, COLOR_BLACK);
		if (error_wrap) std::cerr << "--- ERROR---" << std::endl;
		std::cerr << message << std::endl;
		if (error_wrap) std::cerr << "--- ERROR---" << std::endl;
		Utils::reset_color();
	}
};

#endif // UTILS_H