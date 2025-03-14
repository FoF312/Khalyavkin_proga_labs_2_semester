#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

class BigInt {
private:
    std::vector<int> digits; 
    bool isNegative;        

    // Вспомогательные методы
    void removeLeadingZeros();
    void normalize();
    BigInt subtractAbsolute(const BigInt& other) const; // Вычитание абсолютных значений
    BigInt addAbsolute(const BigInt& other) const;      // Сложение абсолютных значений

public:
    // Конструкторы
    BigInt();
    BigInt(const std::string& number);
    BigInt(int64_t number);

    // Конструктор копирования
    BigInt(const BigInt& other);

    // Оператор присваивания
    BigInt& operator=(const BigInt& other);

    // Унарный минус
    BigInt operator-() const;

    // Арифметические операторы
    BigInt operator+(const BigInt& other) const;
    BigInt& operator+=(const BigInt& other);

    BigInt operator-(const BigInt& other) const;
    BigInt& operator-=(const BigInt& other);

    BigInt operator*(const BigInt& other) const;
    BigInt& operator*=(const BigInt& other);

    // Операторы сравнения
    bool operator<(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;

    // Преобразование в строку
    std::string to_string() const;

    // Операторы ввода и вывода
    friend std::ostream& operator<<(std::ostream& os, const BigInt& num);
    friend std::istream& operator>>(std::istream& is, BigInt& num);
};

