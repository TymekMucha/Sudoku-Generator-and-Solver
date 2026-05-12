#pragma once
#include "Board.h"

class Constraints
{
public:
	static bool checkBlock(Board& board,int value, int index);
	static bool checkRow(Board& board, int value, int index);
	static bool checkCollumn(Board& board, int value, int index);

	static bool valueIsValid(Board& board, int value, int index);
};

