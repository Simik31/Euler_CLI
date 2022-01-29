#include <conio.h>
#include <iostream>

#include "CmdArguments.h"
#include "ProblemFactory.h"
#include "Utils.h"

void run(CmdArguments& args);
void run_all();
void run_id(CmdArguments& args);
void run_problem(int problem_id, IProblem* problem);
void test();

std::string exe;
ProblemFactory problemFactory;


int main(const int argc, const char *argv[])
{
    CLOCK::time_point start = CLOCK::now();

    CmdArguments args(argc, argv);

    args.next(exe); // For Usage

    std::string command;
    args.next(command);

    if (command == COMMAND_RUN_LONG || command == COMMAND_RUN_SHORT) run(args);
    else if (command == COMMAND_TEST_LONG || command == COMMAND_TEST_SHORT) test();
    else
    {
        utils::print::error("Command '" + command + "' not recognized.");
        utils::print::usage(exe);
    }

    std::cout << "Program execution time: " << utils::convert::ns_to_s(CLOCK::now() - start) << " seconds" << std::endl;
    std::cout << "Press any key to close this window..." << std::flush;
    _getch();

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
        utils::print::error("RUN subcommand '" + subcommand + "' not recognized.");
        utils::print::usage(exe);
    }
}

void run_all()
{
    for (int id : problemFactory.get_problem_ids())
        run_problem(id, problemFactory.get_problem(id));
}

void run_id(CmdArguments& args)
{
    std::string id_string;
    if (args.next(id_string) == false)
    {
        utils::print::error("RUN --id <id>\n         ^~~~ not present.");
        utils::print::usage(exe);
    }

    try
    {
        int id = std::stoi(id_string);
        run_problem(id, problemFactory.get_problem(id));
    }
    catch (std::exception& exception)
    {
        utils::print::error("string -> int partsing error: " + std::string{ exception.what() });
        utils::print::usage(exe);
    }
}

void run_problem(int problem_id, IProblem* problem)
{
    CLOCK::time_point start = CLOCK::now();

    int64_t result = problem->solve();

    CLOCK::duration duration = CLOCK::now() - start;

    printf("Problem %3d | Result: %15zu | Time: %10.6fs\n", problem_id, result, utils::convert::ns_to_s(duration));
}

void test()
{
    std::cout << "Testing..." << std::endl;
}