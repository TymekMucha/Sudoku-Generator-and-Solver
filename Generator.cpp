#include "Generator.h"

Generator::Generator()
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

void Generator::createBoard()
{
	std::set<int> possible_values = { 1,2,3,4,5,6,7,8,9 };
	fillCellWithRandomValueRecursive(0);
}

void Generator::printBoard()
{
	for (size_t i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
		{
			std::cout << "-------------------------------\n";
		}

		for (size_t j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
			{
				std::cout << "|";
			}
			std::cout << " " << getCellValue(j, i) << " ";
		}
		std::cout << "|\n";
	}

	std::cout << "-------------------------------\n";
	std::cout << "\n";
}

int Generator::getCellValue(int index)
{
	return 0;
}

int Generator::getCellValue(int x, int y)
{
	int index = y * 9 + x;
	 
	return board.at(index);
}

bool Generator::fillCellWithRandomValueRecursive(int index)
{
	if (index >= 81)
	{
		return true;
	}

	std::set<int> possible_values = { 1,2,3,4,5,6,7,8,9 };

	while (!possible_values.empty())
	{
		int value = selectAndDeleteRandomFromSet(possible_values);

		if (valueIsValid(value, index))
		{
			board[index] = value;
			printBoard();

			if (fillCellWithRandomValueRecursive(index + 1))
			{
				return true;
			}
			std::cout << "\n" << "------ BACKTRACKING ------" << "\n\n";
			board[index] = 0;
		}
	}

	return false;
}

int Generator::selectAndDeleteRandomFromSet(std::set<int> &s)
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

std::pair<int, int> Generator::indexToCoords(const int &index)
{
	int x = index % 9;
	int y = (index - x) / 9;
	return {x, y};
}

int Generator::coordsToIndex(const std::pair<int, int> &coords)
{
	return coords.second * 9 + coords.first;
}

bool Generator::valueIsValid(int value, int index)
{
	return checkBlock(value, index) && checkRow(value, index) && checkCollumn(value, index);
}

bool Generator::checkBlock(int value, int index)
{
	std::pair<int, int> coords = indexToCoords(index);
	std::pair<int, int> block_coords = { coords.first / 3, coords.second / 3 };

	for (size_t i = block_coords.first*3; i < block_coords.first * 3 + 3; i++)
	{
		for (size_t j = block_coords.second * 3; j < block_coords.second * 3 + 3; j++)
		{
			if (value == board.at(coordsToIndex({ i, j })))
			{
				return false;
			}
		}
	}
	return true;
}

bool Generator::checkRow(int value, int index)
{
	int edge_index = index - index % 9;

	for (size_t i = edge_index; i < edge_index + 9; i++)
	{
		if (value == board.at(i)) 
		{
			return false;
		}
	}
	return true;
}

bool Generator::checkCollumn(int value, int index)
{
	std::pair<int, int> coords = indexToCoords(index);

	for (size_t i = 0; i < 9; i++)
	{
		if (value == board.at(coordsToIndex({ coords.first, static_cast<int>(i) })))
		{
			return false;
		}
	}
	return true;
}

void Generator::setCell(int index, int value)
{
	board.at(index) = value;
}

int Generator::getCell(int index) const
{
	return board.at(index);
}
