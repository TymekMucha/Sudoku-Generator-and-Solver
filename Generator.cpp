#include "Generator.h"

Generator::Generator()
{

}

Board Generator::generateBoard()
{
	Board board;
	Solver solver;

	solver.solveBoard(board);

	return board;
}




