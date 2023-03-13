#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab\lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(SumRecursionTests) {
	public:
		
		TEST_METHOD(sumRecursionTest) {
			for (size_t i = 0; i < 10; i++)
			{
				int size = 5;
				int* arr = randomArray(size);
				Assert::AreEqual(sumRecursion(arr, size), sumArray(arr, size));
				delete[] arr;
			}
		}
	};

	TEST_CLASS(CountPropertyRecursionTests) {
	public:
		int size = 5;
		int* arr;
		TEST_METHOD(CountPropertyPositiveRecursionTest) {

			arr = new int[5] {-1, 1, -1, -1};
			try {
				Assert::AreEqual(countPropertyRecurcion(arr, size, isPositive), 1);
			}
			catch (const std::exception&) {
				delete[] arr;
				Assert::IsTrue(false);
			}
			delete[] arr;


			arr = new int[5] {-1, 1, 1, 1};
			try {
				Assert::AreEqual(countPropertyRecurcion(arr, size, isPositive), 3);
			}
			catch (const std::exception&) {
				delete[] arr;
				Assert::IsTrue(false);
			}
			delete[] arr;


			arr = new int[5] {-1, 1, -1, -1};
			try {
				Assert::AreEqual(countPropertyRecurcion(arr, size, isPositive), 1);
			}
			catch (const std::exception&) {
				delete[] arr;
				Assert::IsTrue(false);
			}
			delete[] arr;


			arr = new int[5] {-1, -1, -1, -1};
			try {
				Assert::AreEqual(countPropertyRecurcion(arr, size, isPositive), 0);
			}
			catch (const std::exception&) {
				delete[] arr;
				Assert::IsTrue(false);
			}
			delete[] arr;
		}
	};
	bool f(int a, int b) {
		return a < b;
	}
	TEST_CLASS(maxInSermentRecursionTests) {
	public:
		int* arr;
		TEST_METHOD(maxInSermentRecursionTest) {
			int size = 5;
			try {
				arr = new int[5] { 1, 2, 3, 4, 5 };
				Assert::AreEqual(maxInSegmentRecursion(arr + 2, arr + 4), 4);
			}
			catch (const std::exception&)
			{
				delete[] arr;
				Assert::IsTrue(false);
			}
			delete[] arr;
		}
	};

	TEST_CLASS(arrWithoutZerosTests) {
	public:
		int* arr;
		TEST_METHOD(arrWithoutZerosTest) {
			int size = 5;
			try {
				arr = new int[5] { 1, 2, 3, 4, 5 };
				Assert::IsTrue(arrWithoutZeros(arr, 5));
			}
			catch (const std::exception&)
			{
				delete[] arr;
				Assert::IsTrue(false);
			}
			delete[] arr;

			try {
				arr = new int[5] { 1, 2, 0, 4, 5 };
				Assert::IsFalse(arrWithoutZeros(arr, 5));
			}
			catch (const std::exception&)
			{
				delete[] arr;
				Assert::IsTrue(false);
			}
			delete[] arr;

			try {
				arr = new int[5] { 1, -4, 3, 4, 5 };
				Assert::IsTrue(arrWithoutZeros(arr, 5));
			}
			catch (const std::exception&)
			{
				delete[] arr;
				Assert::IsTrue(false);
			}
			delete[] arr;
		}
	};

	TEST_CLASS(ArithmeticMeanTests) {
	public:
		int* arr;
		TEST_METHOD(ArithmeticMeanTest) {
			int size = 5;
			try {
				arr = new int[size] { 1, 2, 0, 4, 5 };
				Assert::AreEqual(ArithmeticMean(arr, 5), 0.333333, 0.0001);
			}
			catch (const std::exception&)
			{
				delete[] arr;
				Assert::IsTrue(false);
			}
			delete[] arr;
		}
	};

}
