#include "Constraints.h"

bool Constraints::checkBlock(Board& board, int value, int index)
{
	std::pair<int, int> coords = board.indexToCoords(index);
	std::pair<int, int> block_coords = { coords.first / 3, coords.second / 3 };

	for (size_t i = block_coords.first * 3; i < block_coords.first * 3 + 3; i++)
	{
		for (size_t j = block_coords.second * 3; j < block_coords.second * 3 + 3; j++)
		{
			if (value == board.getCell({ i, j }))
			{
				return false;
			}
		}
	}
	return true;
}

bool Constraints::checkRow(Board& board, int value, int index)
{
	int edge_index = index - index % 9;

	for (size_t i = edge_index; i < edge_index + 9; i++)
	{
		if (value == board.getCell(i))
		{
			return false;
		}
	}
	return true;
}

bool Constraints::checkCollumn(Board& board, int value, int index)
{
	std::pair<int, int> coords = board.indexToCoords(index);

	for (int i = 0; i < 9; i++)
	{
		if (value == board.getCell({ coords.first, i }))
		{
			return false;
		}
	}
	return true;
}

bool Constraints::valueIsValid(Board& board, int value, int index)
{
	return checkBlock(board, value, index) && checkRow(board, value, index) && checkCollumn(board, value, index);
}
