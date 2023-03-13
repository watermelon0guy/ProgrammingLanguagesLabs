#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab\lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(InsertMidTests)
	{
	public:
		
		TEST_METHOD(InsertMidEvenTest)
		{
			int size = 4;
			int answerSize = 5;
			int* arr = new int[size]{1, 2, 4, 5};
			int* anwerArr = new int[answerSize] { 1, 2, 3, 4, 5 };
			int element = 3;
			InsertMid(arr, size, element);
			for (size_t i = 0; i < size; i++) {
				try {
					Assert::AreEqual(arr[i], anwerArr[i]);
				}
				catch (const std::exception&) {
					delete[] arr;
					delete[] anwerArr;
					Assert::IsTrue(false);
				}
			}
			Assert::AreEqual(size, answerSize);
			delete[] arr;
			delete[] anwerArr;
		}

		TEST_METHOD(InsertMidOddTest)
		{
			int size = 5;
			int answerSize = 6;
			int* arr = new int[size] { 1, 2, 3, 5, 6 };
			int* anwerArr = new int[answerSize] { 1, 2, 3, 4, 5, 6 };
			int element = 4;
			InsertMid(arr, size, element);
			for (size_t i = 0; i < size; i++) {
				try {
					Assert::AreEqual(arr[i], anwerArr[i]);
				}
				catch (const std::exception&) {
					delete[] arr;
					delete[] anwerArr;
					Assert::IsTrue(false);
				}
			}
			Assert::AreEqual(size, answerSize);
			delete[] arr;
			delete[] anwerArr;
		}
	};

	TEST_CLASS(DeleteDuplicteTests)
	{
	public:

		TEST_METHOD(DeleteDuplicteTest)
		{
			int size = 5;
			int answerSize = 4;
			int* arr = new int[size] {1, 2, 1, 4, 5};
			int* anwerArr = new int[answerSize] { 1, 2, 5, 4 };
			DeleteDuplicate(arr, size);
			for (size_t i = 0; i < size; i++) {
				try {
					Assert::AreEqual(arr[i], anwerArr[i]);
				}
				catch (const std::exception&) {
					delete[] arr;
					delete[] anwerArr;
					Assert::IsTrue(false);
				}
			}
			Assert::AreEqual(size, answerSize);
			delete[] arr;
			delete[] anwerArr;
		}

		TEST_METHOD(DeleteDuplicteFalseTest)
		{
			int size = 5;
			int answerSize = 5;
			int* arr = new int[size] {1, 2, 3, 4, 5};
			int* anwerArr = new int[answerSize] { 1, 2, 3, 4, 5 };
			DeleteDuplicate(arr, size);
			for (size_t i = 0; i < size; i++) {
				try {
					Assert::AreEqual(arr[i], anwerArr[i]);
				}
				catch (const std::exception&) {
					delete[] arr;
					delete[] anwerArr;
					Assert::IsTrue(false);
				}
			}
			Assert::AreEqual(size, answerSize);
			delete[] arr;
			delete[] anwerArr;
		}
	};
}
