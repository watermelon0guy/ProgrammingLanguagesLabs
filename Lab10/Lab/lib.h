#pragma once

const int Max_Length = 256;

int StrCmp(const char* str1, const char* str2);

int WordCount(const char* str);

const char* StrChr(const char* str, char c);

void RemoveChr(char* str, char c);

int LenStr(const char* str);

void InsertStr(char* str, const char* substr, char c);
