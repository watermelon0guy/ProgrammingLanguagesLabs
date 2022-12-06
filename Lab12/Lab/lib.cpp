#include "lib.h"

//Дан текстовый файл, состоящий из строк. Посчитать, сколько раз в файле
//встречается каждая буква латинского алфавита.
void CountChars(std::string name) {
	std::ifstream fin(name);
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
}