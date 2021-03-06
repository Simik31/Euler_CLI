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
	/* Problems 021 - 030 */ {
		this->problem_map.insert(std::make_pair(21, new Problem_021()));
		this->problem_map.insert(std::make_pair(22, new Problem_022()));
		this->problem_map.insert(std::make_pair(23, new Problem_023()));
		this->problem_map.insert(std::make_pair(24, new Problem_024()));
		this->problem_map.insert(std::make_pair(25, new Problem_025()));
		this->problem_map.insert(std::make_pair(26, new Problem_026()));
		this->problem_map.insert(std::make_pair(27, new Problem_027()));
		this->problem_map.insert(std::make_pair(28, new Problem_028()));
		this->problem_map.insert(std::make_pair(29, new Problem_029()));
		this->problem_map.insert(std::make_pair(30, new Problem_030()));
	}
	/* Problems 031 - 040 */ {
		this->problem_map.insert(std::make_pair(31, new Problem_031()));
		this->problem_map.insert(std::make_pair(32, new Problem_032()));
		this->problem_map.insert(std::make_pair(33, new Problem_033()));
		this->problem_map.insert(std::make_pair(34, new Problem_034()));
		this->problem_map.insert(std::make_pair(35, new Problem_035()));
		this->problem_map.insert(std::make_pair(36, new Problem_036()));
		this->problem_map.insert(std::make_pair(37, new Problem_037()));
		this->problem_map.insert(std::make_pair(38, new Problem_038()));
		this->problem_map.insert(std::make_pair(39, new Problem_039()));
		this->problem_map.insert(std::make_pair(40, new Problem_040()));
	}
	/* Problems 041 - 050 */ {
		this->problem_map.insert(std::make_pair(41, new Problem_041()));
		this->problem_map.insert(std::make_pair(42, new Problem_042()));
		this->problem_map.insert(std::make_pair(43, new Problem_043()));
		this->problem_map.insert(std::make_pair(44, new Problem_044()));
		this->problem_map.insert(std::make_pair(45, new Problem_045()));
		this->problem_map.insert(std::make_pair(46, new Problem_046()));
		this->problem_map.insert(std::make_pair(47, new Problem_047()));
		this->problem_map.insert(std::make_pair(48, new Problem_048()));
		this->problem_map.insert(std::make_pair(49, new Problem_049()));
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
