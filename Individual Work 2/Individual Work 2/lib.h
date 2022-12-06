#pragma once
// ���������, ��� � ������� ��� ����� ������� ���� ������������� ���������.
template<typename T>
bool ThreeInRow(T* arr, int length) {
	if (length < 3) return true;
	for (int i = 1; i < length - 1; i++) {
		if (arr[i - 1] > 0 && arr[i] > 0 && arr[i + 1] > 0) return false;
	}
	return true;
}

// ������� �� ������� ��� ��������, ������������� �� ������� �������� ��������.
template<typename T>
void DeleteBeforeZero(T*& arr, int& length) {
	int beforeZero = 0;
	int i = 0;
	for (; arr[i] != 0 && i < length; i++, beforeZero++);
	if (beforeZero == length) return;
	int newLength = length - beforeZero;
	T* arrNew = new T[newLength];

	for (; i < length; i++) {
		arrNew[i - beforeZero] = arr[i];
	}
	delete[] arr;
	arr = arrNew;
	length = newLength;
}

//������� ����������� �������, ���������� ������������� �������� ������� �� �� ������.
template<typename T>
void MinusToPlus(T* arr, int length) {
	if (length == 0) return;
	if (*arr < 0) *arr *= -1;
	MinusToPlus(++arr, --length);
}

//����� ����� ������������� ��������� ����� ��������� �������, ���������� ������ ������
template<typename T>
T SumPosEl4(T** m, int rows) {
	T sum = 0;
	for (int row = rows / 2; row < rows; row++) {
		for (int col = rows - row - 1; col <= row; col++) {
			if (m[row][col] > 0) sum += m[row][col];
		}
	}
	return sum;
}

//��������� ������, ������ ������� �������� ����� �������������
//�������� ��������������� ������ ������� �������� ��������� ��������
template<typename T>
T* VectorFromMaxs(T** m, int rows, int cols, T num) {
	T* v = new T[rows];
	for (size_t row = 0; row < rows; row++) {
		int col = 0;
		T max = 0; // ���� ��������� �� �����, �� ��������� 0
				   // ������� ������ ��������, �� ��� � �� ��������, ��� �����������
		for (; col < cols; col++) {
			if (m[row][col] < num) max = m[row][col];
		}
		for (; col < cols; col++) {
			if (max > m[row][col] && m[row][col] < num) max = m[row][col];
		}
		v[row] = max;
	}
	return v;
}