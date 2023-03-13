#include "pch.h"
#include "CppUnitTest.h"
#include "../babichev_test_2_3/lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1) {
			const int n = 5;
			int arr[n] = { 1, 0, 3, 0, 5 };
			Assert::AreEqual(3, Func(arr, n));
		}

		TEST_METHOD(TestMethod2) {
			const int n = 6;
			int arr[n] = { 1, 0, 3, 6, 0, 6 };
			Assert::AreEqual(9, Func(arr, n));
		}

		TEST_METHOD(TestMethod3) {
			const int n = 5;
			int arr[n] = { 1, 3, 3, 3, 5 };
			Assert::AreEqual(0, Func(arr, n));
		}
	};
}
