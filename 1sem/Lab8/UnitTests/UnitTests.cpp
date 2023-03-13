#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(CountRowsWithZerosTests) {
	public:
		TEST_METHOD(TestMethod0) {
			int rows = 3;
			int cols = 4;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3, 4 },
				{ 5, 6, 7, 8 },
				{ 9, 10, 11, 12 }
			};
			Assert::AreEqual(0, CountRowsWithZeros(matr, rows, cols));
		}

		TEST_METHOD(TestMethod1) {
			int rows = 3;
			int cols = 4;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3, 4 },
				{ 5, 6, 7, 8 },
				{ 9, 10, 0, 12 }
			};
			Assert::AreEqual(1, CountRowsWithZeros(matr, rows, cols));
		}

		TEST_METHOD(TestMethodAll) {
			int rows = 3;
			int cols = 4;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 0, 3, 4 },
				{ 5, 0, 7, 8 },
				{ 9, 0, 11, 12 }
			};
			Assert::AreEqual(3, CountRowsWithZeros(matr, rows, cols));
		}
	};

	TEST_CLASS(IsSymmetricTests) {
	public:
		TEST_METHOD(TestMethod1) {
			int rows = 3;
			int cols = 4;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3, 4 },
				{ 5, 6, 7, 8 },
				{ 9, 10, 11, 12 }
			};
			Assert::IsFalse(IsSymmetric(matr, rows));
		}

		TEST_METHOD(TestMethod2) {
			int rows = 3;
			int cols = 3;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 4, 7 },
				{ 4, 5, 8 },
				{ 7, 8, 9 }
			};
			Assert::IsTrue(IsSymmetric(matr, rows));
		}

		TEST_METHOD(TestMethod3) {
			int rows = 4;
			int cols = 4;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 4, 7, 8 },
				{ 4, 5, 8, 9 },
				{ 7, 8, 3, 1 },
				{ 8, 9, 1, 3 }
			};
			Assert::IsTrue(IsSymmetric(matr, rows));
		}
	};

	TEST_CLASS(TransposeMatrixTests) {
	public:
		TEST_METHOD(TestMethod1) {
			int rows = 2;
			int cols = 3;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 1, 4 },
				{ 2, 5 },
				{ 3, 6 }
			};
			TransposeMatrix(matr, rows, cols);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}

		TEST_METHOD(TestMethod2) {
			int rows = 3;
			int cols = 3;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 1, 4, 7 },
				{ 2, 5, 8 },
				{ 3, 6, 9 }
			};
			TransposeMatrix(matr, rows, cols);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}

		TEST_METHOD(TestMethod3) {
			int rows = 1;
			int cols = 3;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 1 },
				{ 2 },
				{ 3 }
			};
			TransposeMatrix(matr, rows, cols);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}
	};

	TEST_CLASS(DeleteRowTests) {
	public:
		TEST_METHOD(TestMethod1) {
			int rows = 3;
			int cols = 3;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 }
			};
			DeleteRow(matr, rows, cols, 2);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}

		TEST_METHOD(TestMethod2) {
			int rows = 3;
			int cols = 3;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};
			DeleteRow(matr, rows, cols, 0);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}

		TEST_METHOD(TestMethod3) {
			int rows = 3;
			int cols = 3;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 7, 8, 9 }
			};
			DeleteRow(matr, rows, cols, 1);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}
	};

	TEST_CLASS(DeleteColTests) {
	public:
		TEST_METHOD(TestMethod1) {
			int rows = 3;
			int cols = 3;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 1, 2 },
				{ 4, 5 },
				{ 7, 8 }
			};
			DeleteCol(matr, rows, cols, 2);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}

		TEST_METHOD(TestMethod2) {
			int rows = 3;
			int cols = 3;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 2, 3 },
				{ 5, 6 },
				{ 8, 9 }
			};
			DeleteCol(matr, rows, cols, 0);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}

		TEST_METHOD(TestMethod3) {
			int rows = 3;
			int cols = 3;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 1, 3 },
				{ 4, 6 },
				{ 7, 9 }
			};
			DeleteCol(matr, rows, cols, 1);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}
	};

	TEST_CLASS(DeleteRowColTests) {
	public:
		TEST_METHOD(TestMethod1) {
			int rows = 3;
			int cols = 3;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 1, 2 },
				{ 4, 5 }
			};
			DeleteRowCol(matr, rows, cols, 2, 2);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}

		TEST_METHOD(TestMethod2) {
			int rows = 3;
			int cols = 3;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 2, 3 },
				{ 5, 6 }
			};
			DeleteRowCol(matr, rows, cols, 2, 0);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}

		TEST_METHOD(TestMethod3) {
			int rows = 3;
			int cols = 3;
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 5, 6 },
				{ 8, 9 }
			};
			DeleteRowCol(matr, rows, cols, 0, 0);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}
	};

	TEST_CLASS(AddRowTests) {
	public:
		TEST_METHOD(TestMethod1) {
			int rows = 3;
			int cols = 3;
			int arr[3] = { 1, 2, 3 };
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 1, 2, 3 },
				{ 7, 8, 9 }
			};
			AddRow(matr, rows, cols, 2, arr);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}

		TEST_METHOD(TestMethod2) {
			int rows = 3;
			int cols = 3;
			int arr[3] = { 1, 2, 3 };
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};
			AddRow(matr, rows, cols, 1, arr);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}

		TEST_METHOD(TestMethod3) {
			int rows = 3;
			int cols = 3;
			int arr[3] = { 1, 2, 3 };
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};
			AddRow(matr, rows, cols, 0, arr);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}

		TEST_METHOD(TestMethod4) {
			int rows = 3;
			int cols = 3;
			int arr[3] = { 1, 2, 3 };
			int matr[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};

			int answ[MAX_ROWS][MAX_COLS] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 },
				{ 1, 2, 3 }
			};
			AddRow(matr, rows, cols, 3, arr);

			for (size_t i = 0; i < rows; i++) {
				for (size_t j = 0; j < cols; j++) {
					Assert::AreEqual(answ[i][j], matr[i][j]);
				}
			}
		}
	};
}
