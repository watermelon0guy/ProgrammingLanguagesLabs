#include "lib1.h"

// � ������ �������� ����� ��������� ����� ������ �� ����������� ��
// ����. ����� �� �������� ����� ����� ������������ ����� ����, ����
// ����� ����� ��������� � �� ������ �� ���

// ��� ���������� ������������� ���������� ��� ��������� �� ������
// � ����� �������, ��� ������� �������� ������ � ���������
// ������� �� ������������, ������ �������
int CountLastDigitNotRepeat(int* start, int* end) {
	int counter = 0;
	for (int *pt = start; pt != end; pt++) {
		if (IsLastDigitNotRepeat(*pt)) {
			counter++;
		}
	}
	return counter;
}

bool IsLastDigitNotRepeat(int number) {
	number = abs(number);
	int lastDigit = number % 10;
	number /= 10;
	while (number > 0) {
		if (number % 10 == lastDigit)
			return false;
		number /= 10;
	}
	return true;
}

// ������� �� ������������, ������ �������
int MaxSumOfOdd(int* start, int* end) {
	int num = 0;
	int maxSum = 0;
	int currSum;
	for (int* pt = start; pt != end; pt++) {
		if (*pt % 2 == 0) continue;
		currSum = SumOfDigits(*pt);
		if (currSum > maxSum) {
			maxSum = currSum;
			num = *pt;
		}
	}
	return num;
}

int SumOfDigits(int number) {
	number = abs(number);
	int sum = 0;
	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}
	return sum;
}
