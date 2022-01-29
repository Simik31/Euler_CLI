#ifndef PROBLEMS_H
#define PROBLEMS_H

#include <stdint.h>

#include "Definitions.h"

struct IProblem { virtual int64_t solve() = 0; };

class Problem_001 : public IProblem { public: int64_t solve(); };
class Problem_002 : public IProblem { public: int64_t solve(); };
class Problem_003 : public IProblem { public: int64_t solve(); };
class Problem_004 : public IProblem { public: int64_t solve(); };
class Problem_005 : public IProblem { public: int64_t solve(); };
class Problem_006 : public IProblem { public: int64_t solve(); };
class Problem_007 : public IProblem { public: int64_t solve(); };
class Problem_008 : public IProblem { public: int64_t solve(); };
class Problem_009 : public IProblem { public: int64_t solve(); };
class Problem_010 : public IProblem { public: int64_t solve(); };
class Problem_011 : public IProblem { public: int64_t solve(); };
class Problem_012 : public IProblem { public: int64_t solve(); };
class Problem_013 : public IProblem { public: int64_t solve(); };
class Problem_014 : public IProblem { public: int64_t solve(); };
class Problem_015 : public IProblem { public: int64_t solve(); };
class Problem_016 : public IProblem { public: int64_t solve(); };
class Problem_017 : public IProblem { public: int64_t solve(); };

#endif // PROBLEMS_H


