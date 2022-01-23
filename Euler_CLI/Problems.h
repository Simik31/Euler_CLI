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

class Problem_001 PROBLEM
class Problem_002 PROBLEM
class Problem_003 PROBLEM

#endif // PROBLEMS_H


