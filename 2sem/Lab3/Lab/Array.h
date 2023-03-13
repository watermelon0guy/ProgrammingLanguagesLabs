#pragma once
#include <ostream>
#include <iostream>
using namespace std;

class Array {
private:
	int n;
	int* values;
public:
	Array() { //����������� �� ���������
		n = 0;
		values = nullptr;
		cout << "Null array created\n";
	} 
	Array(int _n, int x = 0) { //����������� � �����������
		if (_n < 0) throw 1;
		delete[] values;
		values = nullptr;
		n = _n;
		if (n) {
			values = new int[n];
			for (size_t i = 0; i < n; i++) {
				values[i] = x;
			}
		}
		cout << "Array created with usual constructor\n";
	}
	Array(const Array& other) { //����������� �����
		n = other.n;
		if (n) {
			values = new int[n]; // ��������� ������
			for (size_t i = 0; i < n; i++) {
				values[i] = other.values[i];
			}
		}
		else
			values = nullptr;
		cout << "Array was copied";
	}
	Array(initializer_list<int> list) {
		n = (int)list.size();
		if (n) {
			values = new int[n]; // ��������� ������
			for (size_t i = 0; i < n; i++) {
				values[i] = *(list.begin() + i);
			}
		}
		else
			values = nullptr;
		cout << "Array was made with syntax sugar";
	}
	~Array() { // ����������
		if (values) {
			delete[] values;
		}
		cout << "Array deleted\n";
	}
	// ������
	int size() const { return n; }

	// ������������� �������
	friend ostream& operator << (ostream& out, const Array& arr) {
		for (size_t i = 0; i < arr.n; i++) {
			out << arr.values[i] << " ";
		}
		out << endl;
	}
	friend istream& operator >> (istream& in, Array& arr) {
		in >> arr.n;
		if (arr.n < 0) throw exception("������������ ������");
		if (arr.n) {
			arr.values = new int[arr.n];
			for (size_t i = 0; i < arr.n; i++) {
				in >> arr.values[i];
			}
		}
	}

	// ���������� ����������

	//����������
	Array operator + (const Array& arr) {
		if (n != arr.n)
			throw exception("������� ������");
		for (size_t i = 0; i < arr.n; i++) {
			values[i] += arr.values[i];
		}
		return *this;
	}
	Array operator += (const Array& arr) {
		Array res(*this);
		res += arr;
		return res;
	}
	Array operator + (const int x) {
		Array res(n, x);
		res += *this;
		return res;
	}
	Array& operator = (const Array& arr) {
		if (this != &arr) {
			n = arr.n;
			int* new_data = new int[n];
			for (size_t i = 0; i < n; i++) {
				new_data[i] = arr.values[i];
			}
			delete[] values;
			values = new_data;
		}
		return *this;
	}
	// �������������
	bool operator == (const Array& arr) {
		if (n != arr.n) return false;
		for (size_t i = 0; i < n; i++) {
			if (arr.values[i] != values[i]) return false;
		}
		return true;
	}
	// ����������
	int& operator [] (int i) {
		return values[i];
	}
	int operator [] (int i) const {
		return values[i];
	}

	// ������
	int SearchPlace(int x) {
		for (size_t i = 0; i < n; i++) {
			if (values[i] == x)
				return values[i];
		}
	}

	void IncSize(int m);

	void AddEnd(int x);

	void InsPlace(int x, int pos);


};