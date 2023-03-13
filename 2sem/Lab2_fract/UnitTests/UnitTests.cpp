#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/Fract.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests) {
	public:
		TEST_METHOD(DefaultConstructor) {
			Fract fr;
			Assert::AreEqual(1, fr.getDenom());
			Assert::AreEqual(0, fr.getNumen());
		}

		TEST_METHOD(SimpleConstructor) {
			Fract fr = Fract(1,2);
			Assert::AreEqual(2, fr.getDenom());
			Assert::AreEqual(1, fr.getNumen());
		}

		TEST_METHOD(PlusTest) {
			Fract fr1 = Fract(1, 2);
			Fract fr2 = Fract(3, 4);
			Fract fr = fr1 + fr2;
			Assert::AreEqual(10, fr.getNumen());
			Assert::AreEqual(8, fr.getDenom());
		}

		TEST_METHOD(MinusTest) {
			Fract fr1 = Fract(1, 2);
			Fract fr2 = Fract(3, 4);
			Fract fr = fr2 - fr1;
			Assert::AreEqual(10, fr.getNumen());
			Assert::AreEqual(8, fr.getDenom());
		}
	};
}
