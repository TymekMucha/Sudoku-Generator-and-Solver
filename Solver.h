#pragma once
#include <set>
#include <random>

#include "Constraints.h"
#include "Board.h"

class Solver
{
public:
	Solver();

	bool solveBoard(Board& board);
	bool fillCellWithRandomValueRecursive(Board& board, int index);
	int selectAndDeleteRandomFromSet(std::set<int>& s);

	int findNextEmptyCell(Board& board, int index); // finds empty cell to the right of a given index
};

