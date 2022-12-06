#include "pch.h"
#include <cmath>
#include "CppUnitTest.h"
#include "..\Lab\lib1.h"
#include "..\Lab\lib2.h"
#include "..\Lab\lib3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Ex1) {
	public:
		TEST_METHOD(IsLastDigitNotRepeatTest) {
			Assert::IsTrue(IsLastDigitNotRepeat(1234));
			Assert::IsTrue(IsLastDigitNotRepeat(1));
			Assert::IsTrue(IsLastDigitNotRepeat(-1987654));

			Assert::IsFalse(IsLastDigitNotRepeat(-1343211));
			Assert::IsFalse(IsLastDigitNotRepeat(654345));
			Assert::IsFalse(IsLastDigitNotRepeat(22));
		}

		TEST_METHOD(CountLastDigitNotRepeatTest) {
			int size = 5;
			int* a = new int[size]{ 1, 2, 3, 4, 567 };
			Assert::AreEqual(5, CountLastDigitNotRepeat(a, a + size));
			delete[] a;

			a = new int[size] { 11, 212, 33, 434, 559 };
			Assert::AreEqual(1, CountLastDigitNotRepeat(a, a + size));
			delete[] a;
		}
		
		TEST_METHOD(SumOfDigitsTest) {
			Assert::AreEqual(SumOfDigits(1), 1);
			Assert::AreEqual(SumOfDigits(12), 3);
			Assert::AreEqual(SumOfDigits(123), 6);
			Assert::AreEqual(SumOfDigits(-99), 18);
			Assert::AreEqual(SumOfDigits(-5), 5);
		}

		TEST_METHOD(MaxSumOfOddTests) {
			int size = 5;
			int* a = new int[size] { 1, 765, 3, 4, 567 };
			Assert::AreEqual(765, MaxSumOfOdd(a, a + size));
			delete[] a;

			a = new int[size] { 11, 212, 33, 434, 559 };
			Assert::AreEqual(559, MaxSumOfOdd(a, a + size));
			delete[] a;
		}
	};

	TEST_CLASS(Ex2) {
		TEST_METHOD(Test01) {
			double eps = 0.1;
			Assert::AreEqual(1.82292395, IntegralExponentialFunction(0.1, eps), eps);
		}
		TEST_METHOD(Test05) {
			double eps = 0.1;
			Assert::AreEqual(0.55977359, IntegralExponentialFunction(0.5, eps), eps);
		}
		TEST_METHOD(Test5) {
			double eps = 0.1;
			Assert::AreEqual(0.00114829, IntegralExponentialFunction(5, eps), eps);
		}

	};

	TEST_CLASS(Ex3) {
		int Factorial(int n) {
			int f = 1;
			for (size_t i = 2; i <= n; ++i) {
				f = f * i;
			}
			return f;
		}
		TEST_METHOD(Test) {
			for (int x = -50; x < 50; x++) {
				for (int n = 0; n < 10; n++) {
					Assert::AreEqual(pow(x, n) / Factorial(n), func(x, n), 0.01);
				}
			}
		}
	};
}
