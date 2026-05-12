#pragma once
#include <utility>
#include <deque>
#include <set>
#include <iostream>
#include <random>

#include "Board.h"
#include "Constraints.h"
#include "Solver.h"

class Generator
{
private:

public:
	Generator();
	Board generateBoard();

};

