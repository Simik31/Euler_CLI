#ifndef PROBLEMS_H
#define PROBLEMS_H

#include <chrono>

#include "Definitions.h"

struct ProblemResult {
	int problem_id;
	CLOCK::duration time;
	size_t result;
};

struct IProblem {
	virtual ProblemResult solve() = 0;
};

PROBLEM(Problem_001)
PROBLEM(Problem_002)
PROBLEM(Problem_003)
PROBLEM(Problem_004)
PROBLEM(Problem_005)

#endif // PROBLEMS_H


