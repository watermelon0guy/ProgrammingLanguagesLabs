#include "pch.h"
#include "CppUnitTest.h"
#include "../babichev_test_2_1/lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		TEST_METHOD(TestMethod1) {
			double** matr = nullptr;
			int rows = 3, cols = 3;
			matr = new double*[rows];
			matr[0] = new double[cols] { 1, 2, 3 };
			matr[1] = new double[cols] { 1, 2, 3 };
			matr[2] = new double[cols] { 1, 2, 3 };
			int answer = Func(matr, rows, cols);
			DeleteMatrix(matr, rows);
			Assert::AreEqual(0, answer);
		}

		TEST_METHOD(TestMethod2) {
			double** matr = nullptr;
			int rows = 3, cols = 3;
			matr = new double* [rows];
			matr[0] = new double[cols] { 1, 2, 0 };
			matr[1] = new double[cols] { 0, 2, 3 };
			matr[2] = new double[cols] { 1, 2, 0 };
			int answer = Func(matr, rows, cols);
			DeleteMatrix(matr, rows);
			Assert::AreEqual(2, answer);
		}

		TEST_METHOD(TestMethod3) {
			double** matr = nullptr;
			int rows = 3, cols = 3;
			matr = new double* [rows];
			matr[0] = new double[cols] { 0, 2, 0 };
			matr[1] = new double[cols] { 1, 0, 0 };
			matr[2] = new double[cols] { 0, 2, 0 };
			int answer = Func(matr, rows, cols);
			DeleteMatrix(matr, rows);
			Assert::AreEqual(3, answer);
		}
	};
}
