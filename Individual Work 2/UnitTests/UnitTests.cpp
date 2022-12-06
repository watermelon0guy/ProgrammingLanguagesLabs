#include "pch.h"
#include "CppUnitTest.h"
#include "../Individual Work 2/lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ThreeInRowTests) {
	public:
		TEST_METHOD(TestMethod1) {
			int size = 5;
			int* arr = new int[size] { -1, 2, 3, -2, 3 };
			Assert::IsTrue(ThreeInRow<int>(arr, size));
			delete[] arr;
		}
		TEST_METHOD(TestMethod2) {
			int size = 5;
			int* arr = new int[size] { -1, 2, 3, 2, 3 };
			Assert::IsFalse(ThreeInRow<int>(arr, size));
			delete[] arr;
		}
		TEST_METHOD(TestMethod3) {
			int size = 2;
			int* arr = new int[size] { -1, 2 };
			Assert::IsTrue(ThreeInRow<int>(arr, size));
			delete[] arr;
		}
	};

	TEST_CLASS(DeleteBeforeZeroTests) {
	public:
		TEST_METHOD(TestMethod1) {
			int size = 5;
			int sizeAnsw = 3;
			int* arr = new int[size] { -1, 2, 0, -2, 3 };
			int* arrAnsw = new int[sizeAnsw] { 0, -2, 3 };
			DeleteBeforeZero<int>(arr, size);
			for (int i = 0; i < sizeAnsw; i++) {
				Assert::AreEqual(arrAnsw[i], arr[i]);
			}
			delete[] arr;
			delete[] arrAnsw;
		}
		TEST_METHOD(TestMethod2) {
			int size = 5;
			int sizeAnsw = 5;
			int* arr = new int[size] { 0, 2, 0, -2, 3 };
			int* arrAnsw = new int[sizeAnsw] { 0, 2, 0, -2, 3 };
			DeleteBeforeZero<int>(arr, size);
			for (int i = 0; i < sizeAnsw; i++) {
				Assert::AreEqual(arrAnsw[i], arr[i]);
			}
			delete[] arr;
			delete[] arrAnsw;
		}
		TEST_METHOD(TestMethod3) {
			int size = 5;
			int sizeAnsw = 5;
			int* arr = new int[size] { -1, 2, 1, -2, 3 };
			int* arrAnsw = new int[sizeAnsw] { -1, 2, 1, -2, 3 };
			DeleteBeforeZero<int>(arr, size);
			for (int i = 0; i < sizeAnsw; i++) {
				Assert::AreEqual(arrAnsw[i], arr[i]);
			}
			delete[] arr;
			delete[] arrAnsw;
		}
	};

	TEST_CLASS(MinusToPlusTests) {
	public:
		TEST_METHOD(TestMethod1) {
			int size = 5;
			int* arr = new int[size] { -1, 2, 0, -2, 3 };
			int* arrAnsw = new int[size] { 1, 2, 0, 2, 3 };
			MinusToPlus<int>(arr, size);
			for (int i = 0; i < size; i++) {
				Assert::AreEqual(arrAnsw[i], arr[i]);
			}
			delete[] arr;
		}
		TEST_METHOD(TestMethod2) {
			int size = 5;
			int* arr = new int[size] { -1, -2, 0, -2, -3 };
			int* arrAnsw = new int[size] { 1, 2, 0, 2, 3 };
			MinusToPlus<int>(arr, size);
			for (int i = 0; i < size; i++) {
				Assert::AreEqual(arrAnsw[i], arr[i]);
			}
			delete[] arr;
		}
		TEST_METHOD(TestMethod3) {
			int size = 5;
			int* arr = new int[size] { 1, 2, 0, 2, 3 };
			int* arrAnsw = new int[size] { 1, 2, 0, 2, 3 };
			MinusToPlus<int>(arr, size);
			for (int i = 0; i < size; i++) {
				Assert::AreEqual(arrAnsw[i], arr[i]);
			}
			delete[] arr;
		}
	};

	TEST_CLASS(SumPosEl4Tests) {
	public:
		TEST_METHOD(TestMethod1) {
			int rows = 3, cols = 3;
			int** m = new int* [rows] {
				new int[cols] { 1, 2, 3 },
				new int[cols] { 4, 5, 6 },
				new int[cols] { 7, 8, 9 }
			};
			int answ = SumPosEl4<int>(m, rows);
			Assert::AreEqual(29, answ);
			for (int i = 0; i < rows; ++i) delete[] m[i];
			delete[] m;
		}

		TEST_METHOD(TestMethod2) {
			int rows = 3, cols = 3;
			int** m = new int* [rows] {
				new int[cols] { 1, 2, 3 },
				new int[cols] { 4, -5, 6 },
				new int[cols] { 7, 8, 9 }
			};
			int answ = SumPosEl4<int>(m, rows);
			Assert::AreEqual(24, answ);
			for (int i = 0; i < rows; ++i) delete[] m[i];
			delete[] m;
		}

		TEST_METHOD(TestMethod3) {
			int rows = 4, cols = 4;
			int** m = new int* [rows] {
				new int[cols] { 1, 2, 3, 4 },
				new int[cols] { 4, 5, 6, 5 },
				new int[cols] { 7, 8, 9, 3 },
				new int[cols] { 7, -8, -9, 4 }
			};
			int answ = SumPosEl4<int>(m, rows);
			Assert::AreEqual(28, answ);
			for (int i = 0; i < rows; ++i) delete[] m[i];
			delete[] m;
		}

		TEST_METHOD(TestMethod4) {
			int rows = 1, cols = 1;
			int** m = new int* [rows] {
				new int[cols] { 1 }
			};
			int answ = SumPosEl4<int>(m, rows);
			Assert::AreEqual(1, answ);
			for (int i = 0; i < rows; ++i) delete[] m[i];
			delete[] m;
		}
	};

	TEST_CLASS(VecorFromMaxs4Tests) {
	public:
		TEST_METHOD(TestMethod1) {
			int rows = 3, cols = 3;
			int** m = new int* [rows] {
				new int[cols] { 1, 2, 3 },
				new int[cols] { 4, 5, 6 },
				new int[cols] { 7, 8, 9 }
			};
			int* v = new int[rows] { 3, 6, 8 };
			int num = 9;
			int* vAnsw = VectorFromMaxs<int>(m, rows, cols, num);
			for (size_t i = 0; i < rows; i++) {
				Assert::AreEqual(vAnsw[i], v[i]);
			}
			for (int i = 0; i < rows; ++i) delete[] m[i];
			delete[] m;
		}

		TEST_METHOD(TestMethod2) {
			int rows = 3, cols = 3;
			int** m = new int* [rows] {
				new int[cols] { 1, 2, 3 },
				new int[cols] { 4, 5, 6 },
				new int[cols] { 7, 8, 9 }
			};
			int* v = new int[rows] { 0, 0, 0 };
			int num = 0;
			int* vAnsw = VectorFromMaxs<int>(m, rows, cols, num);
			for (size_t i = 0; i < rows; i++) {
				Assert::AreEqual(vAnsw[i], v[i]);
			}
			for (int i = 0; i < rows; ++i) delete[] m[i];
			delete[] m;
		}
	};
}
