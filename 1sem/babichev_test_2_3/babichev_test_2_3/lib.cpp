#include "lib.h"

//��� ������ ����� �����. ����� ����� ���������, ������������� ����� ������ ����� �������� ����������.

int Func(int* arr, int n) {
	bool flag = true;
	int sumBZ = 0;
	int* end = arr + n;
	while (flag && (arr != end)) {
		if (*arr == 0) flag = false;
		arr++;
	}
	while (!flag && (arr != end)) {
		if (*arr != 0) sumBZ += *arr;
		else flag = true;
		arr++;
	}
	return sumBZ;
}
