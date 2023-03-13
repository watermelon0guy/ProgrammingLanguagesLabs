#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(HyperbolaTest) {
	public:
		TEST_METHOD(TestZero) {
			try {
				Assert::AreEqual(0., hyperbola(0.));
				Assert::Fail(L"Zero division");
			}
			catch (int) {
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(TestPositive) {
			for (double i = 1; i <= 100; i++)
				Assert::AreEqual(1. / i, hyperbola(i), 0.0001);
		}
		TEST_METHOD(TestNegative) {
			for (double i = -1; i >= -100; i--)
				Assert::AreEqual(1. / i, hyperbola(i), 0.0001);
		}
	};
	TEST_CLASS(NoDTest) {
	public:
		TEST_METHOD(TestZero) {
			for (int i = -50; i <= 50; i++) {
				Assert::AreEqual(nodRecursion(0, i), abs(i));
				Assert::AreEqual(nod(i, 0), abs(i));
				Assert::AreEqual(nodRecursion(i, 0), abs(i));
				Assert::AreEqual(nod(0, i), abs(i));
			}
		}
		TEST_METHOD(TestPositive) {
			Assert::AreEqual(nodRecursion(66, 27), 3);
			Assert::AreEqual(nod(66, 27), 3);
		}
		TEST_METHOD(TestNegative) {
			Assert::AreEqual(nodRecursion(-66, 27), 3);
			Assert::AreEqual(nod(66, -27), 3);
			Assert::AreEqual(nodRecursion(-66, -27), 3);
			Assert::AreEqual(nod(-66, -27), 3);
		}
	};
	TEST_CLASS(PowRecussionTest) {
	public:
		TEST_METHOD(TestPowZero) {
			for (double x = -5.5; x <= 5.5; x++)
				Assert::AreEqual(powRecusrsion(x, 0), 1.);
		}
		TEST_METHOD(TestPowPositive) {
			for (double n = 1; n <= 10; n++)
				Assert::AreEqual(powRecusrsion(0.5, n), pow(0.5, n));
		}
		TEST_METHOD(TestPowNegative) {
			for (double n = -1; n >= -10; n--)
				Assert::AreEqual(powRecusrsion(0.5, n), pow(0.5, n));
		}
	};
}
