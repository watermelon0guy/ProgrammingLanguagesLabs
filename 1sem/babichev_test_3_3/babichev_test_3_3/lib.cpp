#include "lib.h"

//������ �������� �����, ����������� ����� ��� ����������� ���������.��������� ������ std::string,
//�������� �������� ����� ����� ������ ������, ������� �������� �������� �����.
void InsertWord(string& str, char c, string word) {
	size_t charPos = str.find(c);
	size_t insertPos = str.rfind(' ', charPos) + 1;
	str.insert(insertPos, word);
}
