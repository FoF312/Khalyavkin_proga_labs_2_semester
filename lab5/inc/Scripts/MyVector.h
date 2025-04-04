#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <stdexcept>

class MyVector {
private:
    int* data;         // Указатель на массив данных
    size_t size_;      // Текущий размер вектора
    size_t capacity_;  // Вместимость вектора

    void resizeCapacity(size_t new_capacity);  // Внутренний метод для изменения вместимости

public:
    // Конструкторы и деструктор
    MyVector();
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);
    ~MyVector();

    // Методы
    void push_back(int value);
    void insert(size_t index, int value);
    void erase(size_t index);
    void resize(size_t new_size, int value = 0);
    void reserve(size_t new_capacity);
    void shrink_to_fit();

    // Доступ к элементам
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    int& front();
    const int& front() const;
    int& back();
    const int& back() const;

    // Информация о векторе
    size_t size() const;
    size_t capacity() const;
    bool empty() const;

    // Вспомогательные методы
    void print() const;  // Для демонстрации
};

#endif // MYVECTOR_H