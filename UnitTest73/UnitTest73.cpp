#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.1 rec/lab 7.1 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73
{
	TEST_CLASS(UnitTest73)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int rows = 3, cols = 3;
            int** matrix = new int* [rows];
            for (int i = 0; i < rows; ++i) {
                matrix[i] = new int[cols];
            }

            matrix[0][0] = 4; matrix[0][1] = 5; matrix[0][2] = 6;
            matrix[1][0] = 2; matrix[1][1] = 8; matrix[1][2] = 3;
            matrix[2][0] = 1; matrix[2][1] = 2; matrix[2][2] = 4;

            sortColumns(matrix, rows, cols);

            Assert::AreEqual(6, matrix[0][0]);
            Assert::AreEqual(5, matrix[0][1]);
            Assert::AreEqual(4, matrix[0][2]);

            Assert::AreEqual(3, matrix[1][0]);
            Assert::AreEqual(8, matrix[1][1]);
            Assert::AreEqual(2, matrix[1][2]);

            Assert::AreEqual(4, matrix[2][0]);
            Assert::AreEqual(2, matrix[2][1]);
            Assert::AreEqual(1, matrix[2][2]);

            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
		}
	};
}
