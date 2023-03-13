#include "lib.h"

//¬ текстовом файле записана последовательность целых чисел.ќпределить количество чисел в файле, в записи которых присутствует цифра 9.
//–ешение представить в виде функции main, выполн€ющей работу с файлом и функции, выполн€ющей обработку целого числа.
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