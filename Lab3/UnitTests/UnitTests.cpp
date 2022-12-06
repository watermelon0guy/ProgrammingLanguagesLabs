#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../Lab3/lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(checkBitTest)
		{
			Assert::IsTrue(checkBit(5, 1));
			Assert::IsFalse(checkBit(5, 2));
			Assert::IsTrue(checkBit(7, 3));
			Assert::IsFalse(checkBit(-20, 1));
		}
		TEST_METHOD(setBitTest)
		{
			int number = 5;
			setBit(number, 2, 1);
			Assert::AreEqual(number, (int)7);
			setBit(number, 2, 0);
			Assert::AreEqual(number, (int)5);
		}
		TEST_METHOD(expTeylorTest)
		{
			Assert::AreEqual(expTeylor(5, 0.0001), exp(5), 0.001);
			Assert::AreEqual(expTeylor(6, 0.0001), exp(6), 0.001);
			Assert::AreEqual(expTeylor(12, 0.0001), exp(12), 0.001);
			Assert::AreEqual(expTeylor(-10, 0.00001), exp(-10), 0.001);
		}
		TEST_METHOD(sinTeylorTest)
		{
			Assert::AreEqual(sinTeylor(5, 0.0001), sin(5), 0.001);
			Assert::AreEqual(sinTeylor(6, 0.0001), sin(6), 0.001);
			Assert::AreEqual(sinTeylor(300, 0.0001), sin(300), 0.001);
			Assert::AreEqual(sinTeylor(-30, 0.0001), sin(-30), 0.001);
		}
	};
}
