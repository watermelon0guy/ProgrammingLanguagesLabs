#include "lib.h"

//Строка содержит слова, разделенные одним или несколькими пробелами.Используя строки std::string,
//Вставить заданное слово перед первым словом, которое содержит заданную букву.
void InsertWord(string& str, char c, string word) {
	size_t charPos = str.find(c);
	size_t insertPos = str.rfind(' ', charPos) + 1;
	str.insert(insertPos, word);
}
