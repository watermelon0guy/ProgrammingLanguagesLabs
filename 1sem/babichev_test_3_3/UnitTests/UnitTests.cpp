#include "pch.h"
#include "CppUnitTest.h"
#include "../babichev_test_3_3/lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests) {
	public:
		TEST_METHOD(TestMethod1) {
			string str1 = "123 193";
			string str2 = "123 wow193";
			InsertWord(str1, '9', "wow");
			Assert::AreEqual(str2, str1);
		}
		TEST_METHOD(TestMethod2) {
			string str1 = "9123 193";
			string str2 = "wow9123 193";
			InsertWord(str1, '9', "wow");
			Assert::AreEqual(str2, str1);
		}
		TEST_METHOD(TestMethod3) {
			string str1 = "123 9193";
			string str2 = "123 wow9193";
			InsertWord(str1, '9', "wow");
			Assert::AreEqual(str2, str1);
		}
		TEST_METHOD(TestMethod4) {
			string str1 = "123 1539";
			string str2 = "123 wow1539";
			InsertWord(str1, '9', "wow");
			Assert::AreEqual(str2, str1);
		}
		TEST_METHOD(TestMethod5) {
			string str1 = "193";
			string str2 = "wow193";
			InsertWord(str1, '9', "wow");
			Assert::AreEqual(str2, str1);
		}
	};
}
