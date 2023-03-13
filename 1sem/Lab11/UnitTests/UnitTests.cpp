#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab/lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(WordCountTests) {
	public:
		TEST_METHOD(TestMethod1) {
			string str = "bla    bla      bla";
			Assert::AreEqual(3, WordCount(str));
		}
		TEST_METHOD(TestMethod2) {
			string str = "      bla    bla      bla       ";
			Assert::AreEqual(3, WordCount(str));
		}
		TEST_METHOD(TestMethod3) {
			string str = "";
			Assert::AreEqual(0, WordCount(str));
		}
	};

	TEST_CLASS(DeleteCharTests) {
	public:
		TEST_METHOD(TestMethod1) {
			string str = " bla bla bla ";
			string strAnsw = " ba ba ba ";
			DeleteChar(str, 'l');
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					  // и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
		TEST_METHOD(TestMethod2) {
			string str = "      bla bla bla     ";
			string strAnsw = "      la la la     ";
			DeleteChar(str, 'b');
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					  // и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
		TEST_METHOD(TestMethod3) {
			string str = "      bla bla bla     ";
			string strAnsw = "      bla bla bla     ";
			DeleteChar(str, 'z');
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					  // и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
	};

	TEST_CLASS(InsertSubStrTests) {
	public:
		TEST_METHOD(TestMethod1) {
			string str = "bru bru bru";
			string strAnsw = "bruhhh bru bru";
			InsertSubStr(str, "hhh", 'u');
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					  // и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
		TEST_METHOD(TestMethod2) {
			string str = "bru bru bru";
			string strAnsw = "bru bru bru";
			InsertSubStr(str, "hhh", 'z');
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					  // и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
		TEST_METHOD(TestMethod3) {
			string str = "   bru    bruh    bru  ";
			string strAnsw = "   bru    bruhhhh    bru  ";
			InsertSubStr(str, "hhh", 'h');
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					// и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
	};

	TEST_CLASS(DeleteLongestWordTests) {
	public:
		TEST_METHOD(TestMethod1) {
			string str = "bru bruh bru";
			string strAnsw = "bru  bru";
			DeleteLongestWord(str);
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					  // и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
		TEST_METHOD(TestMethod2) {
			string str = "bru bru bru";
			string strAnsw = " bru bru";
			DeleteLongestWord(str);
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					  // и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
		TEST_METHOD(TestMethod3) {
			string str = "bru bru bru bruh";
			string strAnsw = "bru bru bru ";
			DeleteLongestWord(str);
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					// и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
	};

	TEST_CLASS(ReplaceEvenWordsTests) {
	public:
		TEST_METHOD(TestMethod1) {
			string str = "bru bruh bru";
			string strAnsw = "bru hHh bru";
			ReplaceEvenWords(str, "hHh");
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					// и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
		TEST_METHOD(TestMethod2) {
			string str = "bru bruh bru task";
			string strAnsw = "bru hHh bru hHh";
			ReplaceEvenWords(str, "hHh");
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					// и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
		TEST_METHOD(TestMethod3) {
			string str = "    bru     bruh     bru     task";
			string strAnsw = "    bru     hHh     bru     hHh";
			ReplaceEvenWords(str, "hHh");
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					// и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
	};

	TEST_CLASS(ReverseOddWordsTests) {
	public:
		TEST_METHOD(TestMethod1) {
			string str = "bru bruh bru";
			string strAnsw = "urb bruh urb";
			ReverseOddWords(str);
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					// и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
		TEST_METHOD(TestMethod2) {
			string str = "bru";
			string strAnsw = "urb";
			ReverseOddWords(str);
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					// и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
		TEST_METHOD(TestMethod3) {
			string str = "     bru      bruh    bru     ";
			string strAnsw = "     urb      bruh    urb     ";
			ReverseOddWords(str);
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					// и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
	};

	TEST_CLASS(BlanksCorrectionTests) {
	public:
		TEST_METHOD(TestMethod1) {
			string str = "bru   bruh   bru   ";
			string strAnsw = "bru bruh bru";
			BlanksCorrection(str);
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					// и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
		TEST_METHOD(TestMethod2) {
			string str = "    bru    bruh   bru   ";
			string strAnsw = "bru bruh bru";
			BlanksCorrection(str);
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					// и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
		TEST_METHOD(TestMethod3) {
			string str = "    bru,    bruh??? wtf???   bru!   ";
			string strAnsw = "bru, bruh??? wtf??? bru!";
			BlanksCorrection(str);
			Assert::AreEqual(strAnsw.length(), str.length());
			for (size_t i = 0; i < str.length(); i++) {
				try { // если вдруг функция не уменьшила строку до нужной длины,
					// и мы выйдем за пределы индексации
					Assert::AreEqual(strAnsw[i], str[i]);
				}
				catch (const std::exception&) {
					Assert::IsFalse(true);
				}
			}
		}
	};
}
