#pragma once

#include <map>
#include <vector>

#include "Problems.h"
#include "Utils.h"

class ProblemFactory
{
public:
	ProblemFactory();
	~ProblemFactory();

	IProblem* get_problem(int problem_id);
	std::vector<int> get_problem_ids();

private:
	std::map<int, IProblem*> problem_map;
};
