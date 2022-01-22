#ifndef CMDARGUMENTS_H
#define CMDARGUMENTS_H

#include <string>
#include <vector>

#include "Usage.h"

class CmdArguments
{
public:
	CmdArguments(const int argc, const char* argv[]);
	void skip();
	bool next(std::string& arg);
private:
	int index, argc;
	std::vector<std::string> args;
};

#endif // CMDARGUMENTS_H