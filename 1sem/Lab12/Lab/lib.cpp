#include "lib.h"

//��� ��������� ����, ��������� �� �����. ���������, ������� ��� � �����
//����������� ������ ����� ���������� ��������.
void CountChars(string name) {
	ifstream fin(name);
	if (!fin.is_open()) return;
	std::string s;
	int cnt[26] = {};
	while (getline(fin, s)) {
		for (int i = 'a'; i <= 'z'; i++) {
			cnt[i - 'a'] += std::count(s.begin(), s.end(), i) + std::count(s.begin(), s.end(), i-32);
		}
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] != 0) {
			std::cout << "Char " << char(i + 'a') << " " << cnt[i] << std::endl;
		}
	}
	fin.close();
}

//��� ��������� ����, ��������� �� �����.������� ����� ������� ������ � �����.
void LongestString(string name) {
	ifstream fin(name);
	if (!fin.is_open()) return;
	std::string s;
	string longestStr = "";
	while (getline(fin, s)) {
		if (s.length() > longestStr.length()) longestStr = s;
	}
	cout << longestStr << endl;
	fin.close();
}

//��� ��������� ����, ���������� ������ ����.����� � ������ ���������
//���������.������ ����� ���� ������.��������� ���������� ���� � ������
//������ �����.
int WordCount(string str) { // �� ������� ����
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

void WordCountInStrings(string name) {
	ifstream fin(name);
	if (!fin.is_open()) return;
	std::string s;
	size_t i = 1;
	while (getline(fin, s)) {
		cout << i << ": " << WordCount(s) << endl;
		i++;
	}
	fin.close();
}

//��� ��������� ����, ���������� ������ ����. ����� � ������ ���������
//���������.������� �� ����� �������� �����
void DeleteWords(string name, string word) {
	ifstream fin(name);
	string tempName = "deleteWords.txt";
	ofstream fout(tempName);
	if (!fin.is_open()) return;
	if (!fout.is_open()) return;
	std::string s;
	while (getline(fin, s)) {
		size_t pos = 0;
		while ((pos = s.find(word)) != string::npos) {
			s.replace(pos, word.length(), "");
		}
		fout << s << endl;
	}
	fin.close();
	fout.close();
	remove(name.c_str());
	rename(tempName.c_str(), name.c_str());
}

//��� ��������� ����, ���������� ������ ��������.������������� ������ � �����.
void NumberLines(string name) {
	ifstream fin(name);
	string tempName = "numberLines.txt";
	ofstream fout(tempName);
	if (!fin.is_open()) return;
	if (!fout.is_open()) return;
	std::string s;
	size_t i = 1;
	while (getline(fin, s)) {
		fout << to_string(i) + ") " + s << endl;
		i++;
	}
	fin.close();
	fout.close();
	remove(name.c_str());
	rename(tempName.c_str(), name.c_str());
}

//��� ��������� ����, ���������� ������ ����.����� � ������ ���������
//���������.�������� ��� ��������� ��������� ����� � �������� ����� �� �����
//���������
void ReplaceWithCount(string name, string word) {
	ifstream fin(name);
	string tempName = "replaceWithCount.txt";
	ofstream fout(tempName);
	if (!fin.is_open()) return;
	if (!fout.is_open()) return;
	std::string s;
	size_t i = 1;
	while (getline(fin, s)) {
		size_t pos = 0;
		while ((pos = s.find(word)) != string::npos) {
			s.replace(pos, word.length(), to_string(i));
			i++;
		}
		fout << s << endl;
	}
	fin.close();
	fout.close();
	remove(name.c_str());
	rename(tempName.c_str(), name.c_str());
}