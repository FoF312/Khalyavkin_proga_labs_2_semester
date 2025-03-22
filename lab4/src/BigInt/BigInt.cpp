#include "BigInt.h"
#include <stdexcept>
#include <algorithm>

// Удаление ведущих нулей
void BigInt::removeLeadingZeros() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
    if (digits.empty()) {
        digits.push_back(0);
    }
}

// Нормализация числа
void BigInt::normalize() {
    removeLeadingZeros();
    if (digits.size() == 1 && digits[0] == 0) {
        isNegative = false;
    }
}

// Конструктор по умолчанию
BigInt::BigInt() : isNegative(false) {
    digits.push_back(0);
}

// Конструктор из строки
BigInt::BigInt(const std::string& number) {
    if (number.empty()) {
        throw std::invalid_argument("Empty string");
    }
    size_t start = 0;
    if (number[0] == '-') {
        isNegative = true;
        start = 1;
    } else {
        isNegative = false;
    }
    for (size_t i = start; i < number.size(); ++i) {
        if (!isdigit(number[i])) {
            throw std::invalid_argument("Invalid character in number");
        }
        digits.push_back(number[i] - '0');
    }
    std::reverse(digits.begin(), digits.end());
    normalize();
}

// Конструктор из числа
BigInt::BigInt(int64_t number) {
    if (number < 0) {
        isNegative = true;
        number = -number;
    } else {
        isNegative = false;
    }
    if (number == 0) {
        digits.push_back(0);
    }
    while (number > 0) {
        digits.push_back(number % 10);
        number /= 10;
    }
}

// Конструктор копирования
BigInt::BigInt(const BigInt& other) : digits(other.digits), isNegative(other.isNegative) {}

// Оператор присваивания
BigInt& BigInt::operator=(const BigInt& other) {
    if (this != &other) {
        digits = other.digits;
        isNegative = other.isNegative;
    }
    return *this;
}

// Оператор сложения
BigInt BigInt::operator+(const BigInt& other) const {
    if (isNegative != other.isNegative) {
        throw std::runtime_error("Addition of numbers with different signs is not supported");
    }
    BigInt result;
    result.digits.clear();
    int carry = 0;
    size_t maxSize = std::max(digits.size(), other.digits.size());
    for (size_t i = 0; i < maxSize || carry; ++i) {
        int sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];
        result.digits.push_back(sum % 10);
        carry = sum / 10;
    }
    result.isNegative = isNegative;
    result.normalize();
    return result;
}

// Оператор умножения
BigInt BigInt::operator*(const BigInt& other) const {
    BigInt result;
    result.digits.resize(digits.size() + other.digits.size(), 0);
    for (size_t i = 0; i < digits.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < other.digits.size() || carry; ++j) {
            int product = result.digits[i + j] + digits[i] * (j < other.digits.size() ? other.digits[j] : 0) + carry;
            result.digits[i + j] = product % 10;
            carry = product / 10;
        }
    }
    result.isNegative = isNegative != other.isNegative;
    result.normalize();
    return result;
}

// Операторы сравнения
bool BigInt::operator<(const BigInt& other) const {
    if (isNegative != other.isNegative) {
        return isNegative;
    }
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    return false;
}

bool BigInt::operator>(const BigInt& other) const {
    return other < *this;
}

bool BigInt::operator==(const BigInt& other) const {
    return digits == other.digits && isNegative == other.isNegative;
}

bool BigInt::operator!=(const BigInt& other) const {
    return !(*this == other);
}

// Преобразование в строку
std::string BigInt::to_string() const {
    std::string result;
    if (isNegative) {
        result += '-';
    }
    for (int i = digits.size() - 1; i >= 0; --i) {
        result += std::to_string(digits[i]);
    }
    return result;
}

// Операторы ввода и вывода
std::ostream& operator<<(std::ostream& os, const BigInt& num) {
    os << num.to_string();
    return os;
}

std::istream& operator>>(std::istream& is, BigInt& num) {
    std::string input;
    is >> input;
    num = BigInt(input);
    return is;
}