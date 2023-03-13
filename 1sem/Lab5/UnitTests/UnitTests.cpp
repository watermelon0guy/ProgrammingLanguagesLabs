#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5/lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(SumArrayTests) {
	public:
		TEST_METHOD(sumArrayTest) {
			int arr1[3] = { 4, 4, 4 };
			int arr2[5] = { 5, 5, 5, 0, 0 };
			int arr3[2] = { 4, 4 };
			int arr4[1] = { 25 };

			Assert::AreEqual(sumArray(arr1, 3), 12);
			Assert::AreEqual(sumArray(arr2, 5), 15);
			Assert::AreEqual(sumArray(arr3, 2), 8);
			Assert::AreEqual(sumArray(arr4, 1), 25);
		}
	};

	TEST_CLASS(ProductOfTwoArraysTests) {
	public:
		TEST_METHOD(productOfTwoArraysTest) {
			int arr1[5] = { 1, 4, 3, 2, 7 };
			int arr2[5] = { 4, 2, 7, 4, 8 };
			int arr3[5];
			int arrCorrect[5] = { 4, 8, 21, 8, 56 };
			productOfTwoArrays(arr1, arr2, arr3, 5);
			for (int i = 0; i < 5; i++) {
				Assert::AreEqual(arr3[i], arrCorrect[i]);
			}
		}
	};

	TEST_CLASS(InsertionSortTests) {
	public:
		TEST_METHOD(insertionSortTest) {
			int arr[5] = { 4, -2, 1, 5, 3 };
			int arrCorrect[5] = { -2, 1, 3, 4, 5 };
			insertionSort(arr, 5);
			for (int i = 0; i < 5; i++) {
				Assert::AreEqual(arr[i], arrCorrect[i]);
			}
		}
	};

	TEST_CLASS(AnyZeroTests) {
	public:
		TEST_METHOD(anyZeroTest) {
			int arr1[5] = { 4, -2, 0, 5, 3 };
			int arr2[5] = { -2, 1, 3, 4, 5 };
			int arr3[5] = { 4, 2, 0, 4, 5 };
			int arr4[5] = { -2, 1, 3, 4, 5 };

			Assert::IsTrue(anyZero(arr2, 5));
			Assert::IsTrue(anyZero(arr4, 5));

			Assert::IsFalse(anyZero(arr1, 5));
			Assert::IsFalse(anyZero(arr3, 5));
		}
	};

	TEST_CLASS(AnyDuplNeighboursTests) {
	public:
		TEST_METHOD(anyDuplNeighboursTest) {
			int arr1[5] = { 4, -2, 5, 5, 3 };
			int arr2[5] = { -2, 1, 3, 4, 5 };
			int arr3[5] = { 4, 2, 0, 4, 5 };
			int arr4[5] = { -2, 1, 3, 4, 4 };

			Assert::IsTrue(anyDuplNeighbours(arr2, 5));
			Assert::IsTrue(anyDuplNeighbours(arr3, 5));

			Assert::IsFalse(anyDuplNeighbours(arr1, 5));
			Assert::IsFalse(anyDuplNeighbours(arr4, 5));
		}
	};

	TEST_CLASS(AnyPredicateTests) {
	public:
		TEST_METHOD(isPositiveTest) {
			int arr1[5] = { 4, 2, 5, 5, 3 };
			int arr2[5] = { 4, -2, 5, 5, 3 };
			Assert::IsTrue(anyPredicate(arr1, 5, isPositive));
			Assert::IsFalse(anyPredicate(arr2, 5, isPositive));
		}
		TEST_METHOD(isEvenTest) {
			int arr1[5] = { 4, 2, 6, 8, 4 };
			int arr2[5] = { 4, -2, 5, 5, 3 };
			Assert::IsTrue(anyPredicate(arr1, 5, isEven));
			Assert::IsFalse(anyPredicate(arr2, 5, isEven));
		}
		TEST_METHOD(isContains5Test) {
			int arr1[5] = { 45, 52, 55, 854, 44544 };
			int arr2[5] = { 4, -2, 3, 2, 3 };
			Assert::IsTrue(anyPredicate(arr1, 5, isContains5));
			Assert::IsFalse(anyPredicate(arr2, 5, isContains5));
		}
		TEST_METHOD(sameSignsTest) {
			int arr1[5] = { -4, -2, -5, -8, -4 };
			int arr2[5] = { 4, 2, 3, 2, 3 };
			int arr3[5] = { 4, -2, 3, 2, 3 };
			Assert::IsTrue(anyPredicate(arr1, 5, sameSigns));
			Assert::IsTrue(anyPredicate(arr2, 5, sameSigns));
			Assert::IsFalse(anyPredicate(arr3, 5, sameSigns));
		}
		TEST_METHOD(differentSignsTest) {
			int arr1[5] = { 4, -2, 5, -8, 4 };
			int arr2[5] = { -4, 2, -3, 2, -3 };
			int arr3[5] = { 4, -2, 3, 2, 3 };
			Assert::IsTrue(anyPredicate(arr1, 5, differentSigns));
			Assert::IsTrue(anyPredicate(arr2, 5, differentSigns));
			Assert::IsFalse(anyPredicate(arr3, 5, differentSigns));
		}
		TEST_METHOD(nonDecreasingPairTest) {
			int arr1[5] = { -21, -2, 5, 8, 10 };
			int arr2[5] = { 2, 2, 2, 2, 2 };
			int arr3[5] = { 4, -2, 3, 2, 3 };
			Assert::IsTrue(anyPredicate(arr1, 5, nonDecreasingPair));
			Assert::IsTrue(anyPredicate(arr2, 5, nonDecreasingPair));
			Assert::IsFalse(anyPredicate(arr3, 5, nonDecreasingPair));
		}
	};
}
