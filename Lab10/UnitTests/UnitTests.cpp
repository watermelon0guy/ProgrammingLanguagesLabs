#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(StrCmpTests) {
	public:
		TEST_METHOD(StrCmpMethod1) {
			char str1[Max_Length] = "Hello3";
			char str2[Max_Length] = "Hello2";
			Assert::AreEqual(1, StrCmp(str1, str2));
		}

		TEST_METHOD(StrCmpMethod2) {
			char str1[Max_Length] = "Hello2";
			char str2[Max_Length] = "Hello3";
			Assert::AreEqual(-1, StrCmp(str1, str2));
		}

		TEST_METHOD(StrCmpMethod3) {
			char str1[Max_Length] = "Hello";
			char str2[Max_Length] = "Hello";
			Assert::AreEqual(0, StrCmp(str1, str2));
		}
	};

	TEST_CLASS(WordCountTests) {
	public:
		TEST_METHOD(WordCountMethod1) {
			char str1[Max_Length] = "Hello World";
			Assert::AreEqual(2, WordCount(str1));
		}
		TEST_METHOD(WordCountMethod2) {
			char str1[Max_Length] = "Hello World ";
			Assert::AreEqual(2, WordCount(str1));
		}
		TEST_METHOD(WordCountMethod3) {
			char str1[Max_Length] = "HelloWorld";
			Assert::AreEqual(1, WordCount(str1));
		}
	};

	TEST_CLASS(StrChrTests) {
	public:
		TEST_METHOD(StrChrMethod1) {
			char str1[Max_Length] = "Hello World";
			char* answ = &str1[2];
			Assert::AreEqual(answ, StrChr(str1, 'l'));
		}

		TEST_METHOD(StrChrMethod2) {
			char str1[Max_Length] = "Hello World";
			char* answ = &str1[0];
			Assert::AreEqual(answ, StrChr(str1, 'H'));
		}

		TEST_METHOD(StrChrMethod3) {
			char str1[Max_Length] = "Hello World";
			char* answ = nullptr;
			Assert::AreEqual(answ, StrChr(str1, 'z'));
		}
	};

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

	TEST_CLASS(InsertStrTests) {
	public:
		TEST_METHOD(InsertStrMethod1) {
			char str1[Max_Length] = "Hello World";
			char answ[Max_Length] = "HelzZzlo World";
			InsertStr(str1, "zZz", 'l');
			for (size_t i = 0; answ[i] != '\0'; i++) {
				Assert::AreEqual(answ[i], str1[i]);
			}
		}

		TEST_METHOD(InsertStrMethod2) {
			char str1[Max_Length] = "Hello World";
			char answ[Max_Length] = "Hello zZzWorld";
			InsertStr(str1, "zZz", ' ');
			for (size_t i = 0; answ[i] != '\0'; i++) {
				Assert::AreEqual(answ[i], str1[i]);
			}
		}

		// Тест не проходит, потому что const char* при !указатель не выкидывает false
		// Хотя в главном файле аналогичная ситуация и все работает
		TEST_METHOD(InsertStrMethod3) {
			char str1[Max_Length] = "Hello World";
			char answ[Max_Length] = "Hello World";
			InsertStr(str1, "zZz", 'Z');
			for (size_t i = 0; answ[i] != '\0'; i++) {
				Assert::AreEqual(answ[i], str1[i]);
			}
		}
	};
}
