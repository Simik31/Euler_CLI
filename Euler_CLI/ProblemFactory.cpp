#include "ProblemFactory.h"

ProblemFactory::ProblemFactory()
{
	/* Problems 001 - 010 */ {
		this->problem_map.insert(std::make_pair( 1, new Problem_001()));
		this->problem_map.insert(std::make_pair( 2, new Problem_002()));
		this->problem_map.insert(std::make_pair( 3, new Problem_003()));
		this->problem_map.insert(std::make_pair( 4, new Problem_004()));
		this->problem_map.insert(std::make_pair( 5, new Problem_005()));
		this->problem_map.insert(std::make_pair( 6, new Problem_006()));
		this->problem_map.insert(std::make_pair( 7, new Problem_007()));
		this->problem_map.insert(std::make_pair( 8, new Problem_008()));
		this->problem_map.insert(std::make_pair( 9, new Problem_009()));
		this->problem_map.insert(std::make_pair(10, new Problem_010()));
	}
	/* Problems 011 - 020 */ {
		this->problem_map.insert(std::make_pair(11, new Problem_011()));
		this->problem_map.insert(std::make_pair(12, new Problem_012()));
		this->problem_map.insert(std::make_pair(13, new Problem_013()));
		this->problem_map.insert(std::make_pair(14, new Problem_014()));
		this->problem_map.insert(std::make_pair(15, new Problem_015()));
		this->problem_map.insert(std::make_pair(16, new Problem_016()));
		this->problem_map.insert(std::make_pair(17, new Problem_017()));
		this->problem_map.insert(std::make_pair(18, new Problem_018()));
		this->problem_map.insert(std::make_pair(19, new Problem_019()));
		this->problem_map.insert(std::make_pair(20, new Problem_020()));
	}

}

ProblemFactory::~ProblemFactory()
{
	for (const auto& [_, value] : this->problem_map)
		delete value;
}

IProblem* ProblemFactory::get_problem(int problem_id)
{
	if (this->problem_map.find(problem_id) == this->problem_map.end())
	{
		utils::print::error("ProblemFactory::get_problem(" + std::to_string(problem_id) + ")\n                            ^" + (problem_id > 10 ? (problem_id > 100 ? "~~" : "~") : "") + " not found in ProblemFactory problem map!");
		exit(EXIT_FAILURE);
	}

	return this->problem_map[problem_id];
}

std::vector<int> ProblemFactory::get_problem_ids()
{
	std::vector<int> keys;
	for (const auto& [key, _] : this->problem_map) keys.push_back(key);
	return keys;
}
