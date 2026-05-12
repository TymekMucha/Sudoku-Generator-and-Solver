#include "Board.h"

Board::Board(bool testBoard)
{
	if (testBoard)
	{
		board = { 7,0,4,9,0,0,2,3,0,
				0,0,0,0,6,0,9,0,1,
				1,8,9,0,3,2,0,4,0,
				0,0,3,1,7,0,5,0,0,
				5,0,7,6,0,8,0,0,3,
				0,1,2,3,0,4,0,9,7,
				0,7,8,0,1,0,0,5,0,
				0,5,1,7,0,3,0,0,0,
				0,2,6,0,9,0,0,7,0 };
	}
	else
	{
		createBoard();
	}

}

void Board::setCell(int index, int value)
{
	board.at(index) = value;
}

int Board::getCell(int index) const
{
	return board.at(index);
}

void Board::setCell(const std::pair<int, int>& coords, int value)
{
	board.at(coordsToIndex(coords)) = value;
}

int Board::getCell(const std::pair<int, int>& coords)
{
	return board.at(coordsToIndex(coords));
}

void Board::createBoard()
{
	board = { 0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0 };
}

void Board::printBoard()
{
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
		{
			std::cout << "-------------------------------\n";
		}

		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
			{
				std::cout << "|";
			}
			std::cout << " " << getCell({ j, i }) << " ";
		}
		std::cout << "|\n";
	}

	std::cout << "-------------------------------\n";
	std::cout << "\n";
}

std::pair<int, int> Board::indexToCoords(const int& index)
{
	int x = index % 9;
	int y = (index - x) / 9;
	return { x, y };
}

int Board::coordsToIndex(const std::pair<int, int>& coords)
{
	return coords.second * 9 + coords.first;
}
