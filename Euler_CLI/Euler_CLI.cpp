#include <iostream>

#include "CmdArguments.h"
#include "ProblemFactory.h"
#include "Usage.h"
#include "Utils.h"

void run(CmdArguments& args);
void run_all();
void run_id(CmdArguments& args);
void test();

std::string exe;
ProblemFactory problemFactory;


int main(const int argc, const char *argv[])
{
    CmdArguments args(argc, argv);

    args.next(exe); // For Usage

    std::string command;
    args.next(command);

    if (command == COMMAND_RUN_LONG || command == COMMAND_RUN_SHORT) run(args);
    else if (command == COMMAND_TEST_LONG || command == COMMAND_TEST_SHORT) test();
    else
    {
        Utils::print_error("Command '" + command + "' not recognized.");
        Usage(exe.c_str());
    }

    return EXIT_SUCCESS;
}

void run(CmdArguments& args)
{
    std::string subcommand;
    args.next(subcommand);

    if (subcommand == SUBCOMMAND_RUN_ALL_LONG || subcommand == SUBCOMMAND_RUN_ALL_SHORT) run_all();
    else if (subcommand == SUBCOMMAND_RUN_ID) run_id(args);
    else
    {
        Utils::print_error("RUN subcommand '" + subcommand + "' not recognized.");
        Usage(exe.c_str());
    }
}

void run_all()
{
    for (int id : problemFactory.get_problem_ids()) Utils::print_problem_result(problemFactory.get_problem(id)->solve());
}

void run_id(CmdArguments& args)
{
    std::string id_string;
    if (args.next(id_string) == false)
    {
        Utils::print_error("RUN --id <id>\n         ^~~~ not present.");
        Usage(exe.c_str());
    }

    try
    {
        int id = std::stoi(id_string);
        Utils::print_problem_result(problemFactory.get_problem(id)->solve());
    }
    catch (std::exception& exception)
    {
        Utils::print_error("string -> int partsing error: " + std::string{ exception.what() });
        Usage(exe.c_str());
    }
}

void test()
{
    std::cout << "Testing..." << std::endl;
}