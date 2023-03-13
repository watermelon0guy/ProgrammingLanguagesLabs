#pragma once
#include <iostream>

class Fract {
private:
	int numen, denom;
	void fixSigns() {
		if (denom < 0) {
			numen *= -1; denom *= -1;
		}
	}
public:
	Fract() : numen(0), denom(1) {}
	Fract(int a, int b = 1) :numen(a) {
		denom = (b != 0) ? b : 1;
		fixSigns();
	}

	int getNumen() { return numen; }
	int getDenom() { return denom; }

	void setNumen(int x) { numen = x; }
	void setDenom(int x) { denom = x; }

	Fract operator + (const Fract& other) {
		Fract temp;
		temp.denom = this->denom * other.denom;
		temp.numen = this->denom * other.numen + other.denom * this->numen;
		temp.fixSigns();
		return temp;
	}

	Fract operator - (const Fract& other) {
		Fract temp;
		temp.denom = this->denom * other.denom;
		temp.numen = this->denom * other.numen - other.denom * this->numen;
		temp.fixSigns();
		return temp;
	}

	Fract operator * (const Fract& other) {
		Fract temp;
		temp.denom = this->denom * other.denom;
		temp.numen = this->numen * other.numen;
		temp.fixSigns();
		return temp;
	}

	Fract operator / (const Fract& other) {
		Fract temp;
		temp.denom = this->denom * other.numen;
		temp.numen = this->numen * other.denom;
		temp.fixSigns();
		return temp;
	}
	
	bool operator == (const Fract& other) const {
		if ((denom == other.denom) && (numen == other.numen))
			return true;
		else
			return false;
	}

	bool operator < (const Fract & other) const {
		if (numen * other.denom < other.numen * denom)
			return true;
		else
			return false;
	}

	bool operator > (const Fract& other) const {
		if (other < *this)
			return true;
		else
			return false;
	}

	bool operator >= (const Fract& other) {
		if (other > *this || other == *this)
			return true;
		else
			return false;
	}

	bool operator <= (const Fract& other) {
		if (other < *this || other == *this)
			return true;
		else
			return false;
	}

	friend std::ostream& operator << (std::ostream& os, const Fract& fr) {
		os << fr.numen << " / " << fr.denom;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, Fract& fr) {
		std::cout << "Enter numenator\n";
		is >> fr.numen;
		std::cout << "Enter denomenator\n";
		is >> fr.denom;
		fr.fixSigns();
		return is;
	}
};
