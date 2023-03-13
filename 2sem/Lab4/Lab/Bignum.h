#pragma once
#include "Array.h"
class Bignum {
private:
    bool negative;
    Array num;

public:
    // конструкторы
    Bignum() : negative(false), num(1) {

    }
    Bignum(long long x) : negative(x < 0) {
        x = abs(x);
        do {
            num.AddEnd(x % 10);
            x /= 10;
        } while (x);
    }

    Bignum(string str) {
        size_t sz = str.size();
        if (!sz) throw invalid_argument("Empty string");
        if ((sz == 1) && !isdigit(str[0]));

        for (size_t i = sz - 1; i > 0; --i) {
            if (!isdigit(str[0])) throw invalid_argument("");
            num.AddEnd(str[i] - '0');
        }
        if (isdigit(str[0])) {
            num.AddEnd(str[0] - '0');
            negative = false;
        }
        else {
            negative = false;
            if (str[0] == '-') negative = true;
            else if (str[0] != '+') throw invalid_argument("Invalid character");
        }
    }
    Bignum(const Bignum& other) {
        negative = other.negative;
        num = other.num;
    } // копия

    // Геттеры
    int length() const {
        return num.size();
    }
    bool IsNegative() const {
        return negative;
    }

    friend ostream& operator << (ostream& out, const Bignum& arr) {
        if (arr.negative) out << "-";
        for (int i = arr.length() - 1; i >= 0; i--) {
            out << arr.num[i];
        }
    }
    friend ostream& operator >> (istream& in, const Bignum& arr) {
        string input;
        in >> input;
        arr = Bignum(input);
        return in;
    }

    Bignum& operator = (const Bignum& arr) {
        negative = arr.negative;
        num = arr.num;
        return *this;
    }
    
    int& operator [] (int i) {
        return num[num.size() - 1 - i];
    }
    int operator [] (int i) const {
        return num[num.size() - 1 - i];
    }

    bool operator == (const Bignum& other) {
        return ((negative == other.negative) && (num == other.num));
    }

    bool operator != (const Bignum& other) {
        return !(*this == other);
    }

    bool operator < (const Bignum & other) {
        if (negative == other.negative)
            return ((num < other.num) && (!negative));
    }

    bool operator > (const Bignum& other) {
        return (other < *this);
    }

    operator long long() const {
        long long ans = 0;
        int len = min(18, num.size());
        for (size_t i = 0; i < len; i++) {
            ans += num[i] * (long long)pow(10, i);
        }
        if (negative) ans = -ans;
        return ans;
    }

    operator string() const {
        string ans = string(num.size() + negative, '-');
        for (int i = negative; i < num.size(); i++) {
            ans[i] = (*this)[i - negative] + 0;
        }
        return ans;
    }

    Bignum operator + (const Bignum& arr) const;
    Bignum operator += (const Bignum& arr) {
        *this = *this + arr;
        return *this;
    }
    Bignum operator - (const Bignum& arr) {
        *this += -arr;
        return *this;
    }
    Bignum operator -= (const Bignum& arr);
    Bignum operator - () const {
        Bignum copy(*this);
        copy.negative = !negative;
        return copy;
    }
    Bignum operator ++ () {
        *this += Bignum(1);
        return *this;
    }
    Bignum operator ++ (int) {
        Bignum temp(*this);
        ++(*this);
        return temp;
    }
    Bignum operator -- () {
        *this -= Bignum(1);
        return *this;
    }
    Bignum operator -- (int) {
        Bignum temp(*this);
        --(*this);
        return temp;
    }
    Bignum operator * (int n);
    Bignum operator *= (int n);

    Bignum gcd(Bignum other);
    
};