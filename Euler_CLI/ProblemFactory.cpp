#include "ProblemFactory.h"

ProblemFactory::ProblemFactory()
{
	this->itop.insert(std::make_pair(1, new Problem_001()));
	this->itop.insert(std::make_pair(2, new Problem_002()));
	this->itop.insert(std::make_pair(3, new Problem_003()));
	this->itop.insert(std::make_pair(4, new Problem_004()));
	this->itop.insert(std::make_pair(5, new Problem_005()));
}

ProblemFactory::~ProblemFactory()
{
	for (const auto& [_, value] : this->itop)
		delete value;
}

IProblem* ProblemFactory::get_problem(int problem_id)
{
	if (this->itop.find(problem_id) == this->itop.end())
	{
		utils::print::error("ProblemFactory::get_problem(" + std::to_string(problem_id) + ")\n                            ^" + (problem_id > 10 ? (problem_id > 100 ? "~~" : "~") : "") + " not found in ProblemFactory problem map!");
		exit(EXIT_FAILURE);
	}

	return this->itop[problem_id];
}

std::vector<int> ProblemFactory::get_problem_ids()
{
	std::vector<int> keys;
	for (const auto& [key, _] : this->itop) keys.push_back(key);
	return keys;
}
