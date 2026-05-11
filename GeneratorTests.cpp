// GeneratorTests.cpp
// Visual Studio unit tests for Generator helper functions

#include "pch.h"
#include "CppUnitTest.h"

#include "Generator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeneratorTests
{
	TEST_CLASS(GeneratorTests)
	{
	public:

		TEST_METHOD(IndexToCoords_0)
		{
			Generator gen;

			std::pair<int, int> coords = gen.indexToCoords(0);

			Assert::AreEqual(0, coords.first);
			Assert::AreEqual(0, coords.second);
		}

		TEST_METHOD(IndexToCoords_23)
		{
			Generator gen;

			std::pair<int, int> coords = gen.indexToCoords(23);

			Assert::AreEqual(5, coords.first);
			Assert::AreEqual(2, coords.second);
		}

		TEST_METHOD(CoordsToIndex_5_2)
		{
			Generator gen;

			int index = gen.coordsToIndex({ 5, 2 });

			Assert::AreEqual(23, index);
		}

		TEST_METHOD(IndexConversion_RoundTrip)
		{
			Generator gen;

			for (int i = 0; i < 81; i++)
			{
				std::pair<int, int> coords = gen.indexToCoords(i);

				int converted = gen.coordsToIndex(coords);

				Assert::AreEqual(i, converted);
			}
		}

		TEST_METHOD(CheckRow_Valid)
		{
			Generator gen;

			// row 0
			gen.board[0] = 1;
			gen.board[1] = 2;
			gen.board[2] = 3;

			bool result = gen.checkRow(4, 4);

			Assert::IsTrue(result);
		}

		TEST_METHOD(CheckRow_Invalid)
		{
			Generator gen;

			// row 0
			gen.board[0] = 1;
			gen.board[1] = 2;
			gen.board[2] = 3;

			bool result = gen.checkRow(2, 4);

			Assert::IsFalse(result);
		}

		TEST_METHOD(CheckColumn_Valid)
		{
			Generator gen;

			// column 0
			gen.board[0] = 1;
			gen.board[9] = 2;
			gen.board[18] = 3;

			bool result = gen.checkCollumn(4, 27);

			Assert::IsTrue(result);
		}

		TEST_METHOD(CheckColumn_Invalid)
		{
			Generator gen;

			// column 0
			gen.board[0] = 1;
			gen.board[9] = 2;
			gen.board[18] = 3;

			bool result = gen.checkCollumn(2, 27);

			Assert::IsFalse(result);
		}

		TEST_METHOD(CheckBlock_Valid)
		{
			Generator gen;

			// top-left 3x3 block
			gen.board[0] = 1;
			gen.board[1] = 2;
			gen.board[9] = 3;

			bool result = gen.checkBlock(4, 10);

			Assert::IsTrue(result);
		}

		TEST_METHOD(CheckBlock_Invalid)
		{
			Generator gen;

			// top-left 3x3 block
			gen.board[0] = 1;
			gen.board[1] = 2;
			gen.board[9] = 3;

			bool result = gen.checkBlock(2, 10);

			Assert::IsFalse(result);
		}
	};
}