#include "pch.h"
#include "CppUnitTest.h"
#include "../babichev_test_3_2/lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(RemoveChrTests) {
	public:
		TEST_METHOD(RemoveChrMethod1) {
			char str1[Max_Length] = "Hello World";
			char answ[Max_Length] = "Hllo World";
			RemoveChr(str1, 'e');
			for (size_t i = 0; answ[i] != '\0'; i++) {
				Assert::AreEqual(answ[i], str1[i]);
			}
		}

		TEST_METHOD(RemoveChrMethod2) {
			char str1[Max_Length] = "Hello World";
			char answ[Max_Length] = "Heo Word";
			RemoveChr(str1, 'l');
			for (size_t i = 0; answ[i] != '\0'; i++) {
				Assert::AreEqual(answ[i], str1[i]);
			}
		}

		TEST_METHOD(RemoveChrMethod3) {
			char str1[Max_Length] = "Hello World";
			char answ[Max_Length] = "Hello World";
			RemoveChr(str1, 'z');
			for (size_t i = 0; answ[i] != '\0'; i++) {
				Assert::AreEqual(answ[i], str1[i]);
			}
		}
	};
}
