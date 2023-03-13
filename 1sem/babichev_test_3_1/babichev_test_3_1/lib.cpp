#include "lib.h"

//� ��������� ����� �������� ������������������ ����� �����.���������� ���������� ����� � �����, � ������ ������� ������������ ����� 9.
//������� ����������� � ���� ������� main, ����������� ������ � ������ � �������, ����������� ��������� ������ �����.
int Function(string name) {
	ifstream fin(name);
	if (!fin.is_open()) return 0;
	std::string s;
	int count = 0;
	bool flag = false;
	while (getline(fin, s)) {
		for (size_t i = 0; i < s.length(); i++) {
			if (s[i] == ' ' || i == s.length() - 1) {
				if (flag) count++;
				flag = false;
			}
			if (s[i] == '9') flag = true;
		}
	}
	fin.close();
	return count;
}