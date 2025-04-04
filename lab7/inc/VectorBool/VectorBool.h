#pragma once
#include <vector>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class MyVector {
    // Обычная реализация вектора (не для bool)
};

// Специализация для bool
template <>
class MyVector<bool> {
private:
    std::vector<unsigned char> data;
    size_t boolSize = 0;

    class BoolProxy {
    private:
        MyVector<bool>& vec;
        size_t pos;
        
    public:
        BoolProxy(MyVector<bool>& v, size_t p);
        operator bool() const;
        BoolProxy& operator=(bool value);
        BoolProxy& operator=(const BoolProxy& other);
    };

public:
    // Конструкторы
    MyVector();
    explicit MyVector(size_t count, bool value = false);
    MyVector(std::initializer_list<bool> init);

    // Методы
    void push_back(bool value);
    bool get(size_t index) const;
    void set(size_t index, bool value);
    void resize(size_t newSize, bool value = false);
    void insert(size_t index, bool value);
    void erase(size_t index);
    size_t size() const;

    // Операторы
    BoolProxy operator[](size_t index);
    bool operator[](size_t index) const;

    // Вспомогательные методы
    void print(std::ostream& os) const;
};

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const MyVector<bool>& vec);

// Определение типа VectorBool как синонима для MyVector<bool>
typedef MyVector<bool> VectorBool;