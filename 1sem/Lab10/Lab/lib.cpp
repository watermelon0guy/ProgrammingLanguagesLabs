#include "lib.h"

int StrCmp(const char* str1, const char* str2) {
	while (*str1 == *str2 && *str1 && *str2) {
		str1++;
		str2++;
	}
	if (*str1 > *str2)
		return 1;
	else if (*str1 < *str2)
		return -1;
	return 0;
}

int WordCount(const char* str)
{
	int count = 0;
	char prevChar = 'a';
	while (*str != '\0') {
		if (*str == ' ' && prevChar != ' ') {
			count++;
		}
		prevChar = *str;
		str++;
	}
	return (prevChar != ' ' ? ++count : count);
}

const char* StrChr(const char* str, char c) {
	while (*str != '\0') {
		if (*str == c) {
			return str;
		}
		str++;
	}
	return nullptr;
}

void RemoveChr(char* str, char c) {
	char *p, *q;

	for (p = q = str; *p != '\0'; *p++ = *q++)
		while (*q == c)
			q++;
}

int LenStr(const char* str) {
	int count = 0;
	while (*str != '\0') {
		count++; str++;
	}
	return count;
}

void InsertStr(char* str, const char* substr, char c) {
	if (LenStr(str) + LenStr(substr) + 2 > 256) throw str; // эх, без проверки один проход
	char temp[Max_Length] = "";
	const char* insertPoint = StrChr(str, c);
	if (!insertPoint) return;
	insertPoint++;
	char* insertPointTemp1 = const_cast<char*>(insertPoint);
	char* insertPointTemp2 = const_cast<char*>(insertPoint);
	char secondPart[Max_Length] = "";
	//strcpy(secondPart, insertPoint);
	for (size_t i = 0; *insertPointTemp1 != '\0'; i++, insertPointTemp1++) {
		secondPart[i] = *insertPointTemp1;
	}

	while (*substr != '\0') {
		*insertPointTemp2 = *substr;
		insertPointTemp2++; substr++;
	}

	//strcat(insertPoint, secondPart);
	for (size_t i = 0; secondPart[i] != '\0'; i++, insertPointTemp2++) {
		*insertPointTemp2 = secondPart[i];
	}
}
