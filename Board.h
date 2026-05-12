#pragma once
#include <array>
#include <iostream>

class Board
{
private:
	std::array<uint8_t, 81> board;

public:
	Board(bool testBoard = false);

	void setCell(int index, int value);
	int getCell(int index) const;

	void setCell(const std::pair<int,int>& coords, int value);
	int getCell(const std::pair<int, int>& coords);

	void createBoard();
	void printBoard();

	std::pair<int, int> indexToCoords(const int& index);
	int coordsToIndex(const std::pair<int, int>& coords);
};

