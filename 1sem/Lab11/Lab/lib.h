#pragma once
#include <string>

using namespace std;

int WordCount(string str);

void DeleteChar(string& str, char c);

void InsertSubStr(string& str, string sub, char c);

void DeleteLongestWord(string& str);

void ReplaceEvenWords(string& str, string newWord);

void ReverseOddWords(string& str);

void BlanksCorrection(string& str);
