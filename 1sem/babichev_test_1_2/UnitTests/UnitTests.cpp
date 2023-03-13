#include "pch.h"
#include "CppUnitTest.h"
#include "../babichev_test_1_2/lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(Test)
		{
			int number = 123;
			leftDig(number, 3);
			Assert::AreEqual(number, 3123);

			number = -123;
			leftDig(number, 4);
			Assert::AreEqual(number, -4123);

			number = 12355;
			leftDig(number, 3);
			Assert::AreEqual(number, 312355);

			number = -222;
			leftDig(number, 3);
			Assert::AreEqual(number, -3222);
		}
	};
}
