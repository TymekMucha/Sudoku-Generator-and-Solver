#include "Solver.h"

Solver::Solver()
{
}

bool Solver::solveBoard(Board& board)
{
	return fillCellWithRandomValueRecursive(board, 0);
}

bool Solver::fillCellWithRandomValueRecursive(Board& board, int index)
{
	if (index >= 81 || index == -1)
	{
		return true;
	}

	if (board.getCell(index) != 0)
	{
		int next_index = findNextEmptyCell(board, index);
		return fillCellWithRandomValueRecursive(board, next_index);
	}

	std::set<int> possible_values = { 1,2,3,4,5,6,7,8,9 };

	while (!possible_values.empty())
	{
		int value = selectAndDeleteRandomFromSet(possible_values);

		if (Constraints::valueIsValid(board, value, index))
		{
			board.setCell(index, value);

			if (fillCellWithRandomValueRecursive(board, index + 1))
			{
				return true;
			}
			board.setCell(index, 0);
		}
	}

	return false;
}

int Solver::selectAndDeleteRandomFromSet(std::set<int>& s)
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<size_t> dist(0, s.size() - 1);
	size_t idx = dist(rng);

	auto it = s.begin();
	std::advance(it, idx);

	int value = *it;

	s.erase(it);

	return value;
}

int Solver::findNextEmptyCell(Board& board, int index)
{
	while (index < 81)
	{
		if (board.getCell(index) == 0)
		{
			return index;
		}
		index++;
	} 

	return -1; // no empty cells
} 
