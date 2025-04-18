#include "../inc/VectorBool/VectorBool.h"
#include <iostream>

// Реализация BoolProxy
MyVector<bool>::BoolProxy::BoolProxy(MyVector<bool>& v, size_t p) : vec(v), pos(p) {}

MyVector<bool>::BoolProxy::operator bool() const {
    return vec.get(pos);
}

MyVector<bool>::BoolProxy& MyVector<bool>::BoolProxy::operator=(bool value) {
    vec.set(pos, value);
    return *this;
}

MyVector<bool>::BoolProxy& MyVector<bool>::BoolProxy::operator=(const BoolProxy& other) {
    bool value = static_cast<bool>(other);
    vec.set(pos, value);
    return *this;
}

// Конструкторы
MyVector<bool>::MyVector() : boolSize(0) {}

MyVector<bool>::MyVector(size_t count, bool value) : boolSize(0) {
    resize(count, value);
}

MyVector<bool>::MyVector(std::initializer_list<bool> init) : boolSize(0) {
    for (bool value : init) {
        push_back(value);
    }
}

// Основные методы
void MyVector<bool>::push_back(bool value) {
    // Проверяем, нужно ли добавить новый байт
    if (boolSize % 8 == 0) {
        data.push_back(0);
    }
    
    // Устанавливаем значение бита
    set(boolSize, value);
    
    // Увеличиваем размер
    boolSize++;
}

bool MyVector<bool>::get(size_t index) const {
    if (index >= boolSize) {
        throw std::out_of_range("Index out of range");
    }
    
    size_t byteIndex = index / 8;
    size_t bitIndex = index % 8;
    
    // Проверяем, что байт существует
    if (byteIndex >= data.size()) {
        return false;
    }
    
    // Получаем значение бита
    return (data[byteIndex] >> bitIndex) & 1;
}

void MyVector<bool>::set(size_t index, bool value) {
    if (index >= boolSize) {
        throw std::out_of_range("Index out of range");
    }
    
    size_t byteIndex = index / 8;
    size_t bitIndex = index % 8;
    
    // Проверяем, что байт существует
    if (byteIndex >= data.size()) {
        data.resize(byteIndex + 1, 0);
    }
    
    // Устанавливаем значение бита
    if (value) {
        data[byteIndex] |= (1 << bitIndex);
    } else {
        data[byteIndex] &= ~(1 << bitIndex);
    }
}

void MyVector<bool>::resize(size_t newSize, bool value) {
    size_t oldSize = boolSize;
    boolSize = newSize;
    size_t requiredBytes = (newSize + 7) / 8;
    
    // Изменяем размер вектора байтов
    if (requiredBytes > data.size()) {
        data.resize(requiredBytes, value ? 0xFF : 0x00);
    }
    
    // Инициализируем новые биты значением value
    if (newSize > oldSize) {
        for (size_t i = oldSize; i < newSize; ++i) {
            set(i, value);
        }
    }
}

void MyVector<bool>::insert(size_t index, bool value) {
    if (index > boolSize) {
        throw std::out_of_range("Index out of range");
    }
    
    if (index == boolSize) {
        push_back(value);
        return;
    }
    
    // Проверяем, нужно ли добавить новый байт
    if ((boolSize + 1) % 8 == 0) {
        data.push_back(0);
    }
    
    // Увеличиваем размер вектора
    boolSize++;
    
    // Сдвигаем элементы вправо
    for (size_t i = boolSize - 1; i > index; --i) {
        set(i, get(i - 1));
    }
    
    // Вставляем новый элемент
    set(index, value);
}

void MyVector<bool>::erase(size_t index) {
    if (index >= boolSize) {
        throw std::out_of_range("Index out of range");
    }
    
    // Сдвигаем элементы влево
    for (size_t i = index; i < boolSize - 1; ++i) {
        set(i, get(i + 1));
    }
    
    // Уменьшаем размер вектора
    boolSize--;
    
    // Если размер стал кратен 8 и не равен 0, удаляем последний байт
    if (boolSize % 8 == 0 && boolSize > 0 && !data.empty()) {
        data.pop_back();
    }
}

size_t MyVector<bool>::size() const {
    return boolSize;
}

// Операторы
MyVector<bool>::BoolProxy MyVector<bool>::operator[](size_t index) {
    if (index >= boolSize) {
        throw std::out_of_range("Index out of range");
    }
    return BoolProxy(*this, index);
}

bool MyVector<bool>::operator[](size_t index) const {
    return get(index);
}

// Вспомогательные методы
void MyVector<bool>::print(std::ostream& os) const {
    os << "[";
    for (size_t i = 0; i < boolSize; ++i) {
        os << (get(i) ? "1" : "0");
        if (i != boolSize - 1) {
            os << ", ";
        }
    }
    os << "]";
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const MyVector<bool>& vec) {
    vec.print(os);
    return os;
}