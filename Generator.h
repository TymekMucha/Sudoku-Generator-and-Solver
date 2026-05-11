#pragma once

#include <utility>
#include <deque>
#include <set>
#include <iostream>
#include <random>

class Generator
{
private:
	std::deque<int> board;

public:
	Generator();
	void createBoard();
	void printBoard();

	int getCellValue(int index);
	int getCellValue(int x, int y);

	bool fillCellWithRandomValueRecursive(int index);

	int selectAndDeleteRandomFromSet(std::set<int> &s);
	std::pair<int, int> indexToCoords(const int &index);
	int coordsToIndex(const std::pair<int, int>& coords);

	bool valueIsValid(int value, int index);
	bool checkBlock(int value, int index);
	bool checkRow(int value, int index);
	bool checkCollumn(int value, int index);

	void setCell(int index, int value);
	int getCell(int index) const;
};

