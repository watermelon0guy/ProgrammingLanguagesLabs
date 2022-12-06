#include "lib.h"

int WordCount(string str) {
    if (!str.length())
        throw - 1;

    int i = 0;
    while (str[i] == ' ') i++;

    if (i == str.length())
        throw - 2;

    int count = 1;
    for (int j = i + 1; j < str.length(); j++)
        if ((str[j] != ' ') && (str[j - 1] == ' '))
            count++;
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
