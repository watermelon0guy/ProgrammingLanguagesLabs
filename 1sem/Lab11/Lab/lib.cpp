#include "lib.h"

// Все закоментированные далее функции, работают идентично текущим
// Просто убрал лишние счетчики и считаю некоторые вещи численно

int WordCount(string str) {
	if (!str.length()) return 0;
	int count = 0;
	size_t i = 0;
	for (; i < str.length() && str[i] == ' '; i++);
	while (i < str.length()) {
		if (str[i] == ' ') {
			count++;
			for (; i < str.length() && str[i] == ' '; i++);
		}
		else i++;
	}
	if (str[str.length() - 1] != ' ') count++;
	return count;
}

void DeleteChar(string& str, char c) {
	while (str.find(c) != string::npos)
		str.erase(str.begin() + str.find(c));
}

void InsertSubStr(string& str, string sub, char c) {
	size_t ind = str.find(c);
	if (ind != string::npos)
		str.insert(ind + 1, sub);
}

// Дана строка, состоящая из слов, разделенных одним или несколькими пробелами.
// Найти самое длинное слово(первое, если их несколько) и удалить его из строки.
void DeleteLongestWord(string& str) {
	/*int maxLength = 0, currentLength = 0;
	int maxStartPos = 0, currentStartPos = 0;
	for (size_t i = 0; i <= str.length(); i++) {
		if (str[i] == ' ' || i == str.length() - 1) {
			if (i == str.length() - 1) currentLength++;
			if (currentLength > maxLength) {
				maxStartPos = currentStartPos;
				maxLength = currentLength;
			}
			currentStartPos = i + 1;
			currentLength = 0;
		}
		else
			currentLength++;
	}
	str.replace(maxStartPos, maxLength, "");*/
	int maxLength = 0;
	int maxStartPos = 0, currentStartPos = 0;
	for (size_t i = 0; i <= str.length(); i++) {
		if (str[i] == ' ' || i == str.length() - 1) {
			int currentLength = i - currentStartPos + ((i == str.length() - 1) ? 1 : 0);
			if (currentLength > maxLength) {
				maxStartPos = currentStartPos;
				maxLength = currentLength;
			}
			currentStartPos = i + 1;
		}
	}
	str.replace(maxStartPos, maxLength, "");
}



//Дана строка, состоящая из слов, разделенных одним или несколькими пробелами.
//Заменить в строке каждое четное слово заданным словом.
void ReplaceEvenWords(string& str, string newWord) {
	/*int currentLength = 0;
	bool flag = false;
	size_t i = 0;
	for (; i < str.length() && str[i] == ' '; i++);
	int currentStartPos = i;
	while (i <= str.length()) {
		if (str[i] == ' ' || i == str.length() - 1) {
			if (i == str.length() - 1) currentLength++;
			if (flag) {
				str.replace(currentStartPos, currentLength, newWord);
				i = currentStartPos + newWord.length();
				flag = false;
			} else
				flag = true;
			for (; i < str.length() && str[i] == ' '; i++);
			currentStartPos = i;
			currentLength = 1;
		} else
			currentLength++;
		i++;
	}*/
	bool flag = false;
	size_t i = 0;
	for (; i < str.length() && str[i] == ' '; i++);
	int currentStartPos = i;
	while (i <= str.length()) {
		if (str[i] == ' ' || i == str.length() - 1) {
			if (flag) {
				int currentLength = i - currentStartPos + ((i == str.length() - 1) ? 1 : 0);
				str.replace(currentStartPos, currentLength, newWord);
				i = currentStartPos + newWord.length();
				flag = false;
			}
			else
				flag = true;
			for (; i < str.length() && str[i] == ' '; i++);
			currentStartPos = i;
		}
		i++;
	}
}

//Дана строка, состоящая из слов, разделенных одним или несколькими пробелами.
//Каждое нечетное слово записать в строке в обратном порядке(перевернуть слово).
void ReverseOddWords(string& str) {
	/*int currentLength = 0;
	bool flag = true;
	size_t i = 0;
	for (; i < str.length() && str[i] == ' '; i++);
	int currentStartPos = i;
	for (; i <= str.length(); i++) {
		if (str[i] == ' ' || i == str.length() - 1) {
			if (i == str.length() - 1) currentLength++;
			if (flag) {
				for (size_t rI = 0; rI < currentLength / 2; rI++) {
					swap(str[rI + currentStartPos], str[currentStartPos + currentLength - rI - 1]);
				}
				flag = false;
			}
			else
				flag = true;
			for (; i < str.length() && str[i] == ' '; i++);
			currentStartPos = i;
			currentLength = 1;
		}
		else
			currentLength++;
	}*/
	bool flag = true;
	size_t i = 0;
	for (; i < str.length() && str[i] == ' '; i++);
	int currentStartPos = i;
	for (; i <= str.length(); i++) {
		if (str[i] == ' ' || i == str.length() - 1) {
			if (flag) {
				int currentLength = (i - currentStartPos) - ((i == str.length() - 1) ? 0 : 1);
				for (size_t rI = 0; rI < (i - currentStartPos) / 2; rI++) {
					swap(str[rI + currentStartPos], str[currentStartPos - rI + currentLength]);
				}
				flag = false;
			}
			else
				flag = true;
			for (; i < str.length() && str[i] == ' '; i++);
			currentStartPos = i;
		}
	}
}

//Дана строка, состоящая из слов, разделенных одним или несколькими пробелами и
//знаками препинания. Выполнить корректировку расстановки пробелов – между
//словами должно быть по одному пробелу(лишние убрать), после знака препинания
//должен быть 1 пробел(добавить отсутствующие или удалить лишние).
void BlanksCorrection(string& str) {
	size_t i = 0;
	for (; i < str.length() && str[i] != ' '; i++);
	int currentStartPos = i;
	while (i <= str.length()) {
		if ((i >= str.length()) || str[i] != ' ') {
			str.replace(currentStartPos, i - currentStartPos, (i >= str.length() || currentStartPos == 0) ? "" : " ");
			i = currentStartPos + 1;
			for (; i < str.length() && str[i] != ' '; i++);
			currentStartPos = i;
		}
		else {
			i++;
		}
	}
}

