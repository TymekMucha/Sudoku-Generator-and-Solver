#include <iostream>

#include "Generator.h"

int main() 
{
	Generator gen = Generator();
	gen.createBoard();
	gen.printBoard();
}