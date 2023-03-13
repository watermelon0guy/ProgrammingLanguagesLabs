#include "pch.h"
#include "CppUnitTest.h"
#include "../babichev_2_2/lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int size = 5;
			int* arr = new int[size] {1, 2, 3, 4, 5};
			int* answer = new int[size - 1] {1, 3, 4, 5};
			Func(arr, size, 2);
			for (size_t i = 0; i < size; i++) {
				Assert::AreEqual(answer[i], arr[i]);
			}
			Assert::AreEqual(4, size);
			delete[] arr;
			delete[] answer;
		}

		TEST_METHOD(TestMethod2)
		{
			int size = 5;
			int* arr = new int[size] {1, 2, 3, 2, 5};
			int* answer = new int[size - 2] {1, 3, 5};
			Func(arr, size, 2);
			for (size_t i = 0; i < size; i++) {
				Assert::AreEqual(answer[i], arr[i]);
			}
			Assert::AreEqual(3, size);
			delete[] arr;
			delete[] answer;
		}

		TEST_METHOD(TestMethod3)
		{
			int size = 5;
			int* arr = new int[size] {1, 3, 3, 4, 5};
			int* answer = new int[size] {1, 3, 3, 4, 5};
			Func(arr, size, 2);
			for (size_t i = 0; i < size; i++) {
				Assert::AreEqual(answer[i], arr[i]);
			}
			Assert::AreEqual(5, size);
			delete[] arr;
			delete[] answer;
		}
	};
}
