#include <iostream>

#include "Generator.h"
#include "Solver.h"
#include "Board.h"

int main() 
{
	Generator gen = Generator();
	Board board = gen.generateBoard();
	board.printBoard();

	//Board board = Board(true);
	//Solver sol = Solver();
	//if (sol.solveBoard(board))
	//{
	//	std::cout << "Solved" << "\n";
	//}
	//else 
	//{
	//	std::cout << "No solution found" << "\n";
	//}
	//board.printBoard();
}