#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class BigInt {
private:
    std::vector<int> digits; 
    bool isNegative;       
    void removeLeadingZeros();
    void normalize();

public:
    BigInt();
    BigInt(const std::string& number);
    BigInt(int64_t number);
    BigInt(const BigInt& other);
    BigInt& operator=(const BigInt& other);
    ~BigInt() = default;
    BigInt operator+(const BigInt& other) const;
    BigInt& operator+=(const BigInt& other);

    BigInt operator*(const BigInt& other) const;
    BigInt& operator*=(const BigInt& other);

    bool operator<(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;

    std::string to_string() const;

    friend std::ostream& operator<<(std::ostream& os, const BigInt& num);
    friend std::istream& operator>>(std::istream& is, BigInt& num);
};

#endif // BIGINT_H