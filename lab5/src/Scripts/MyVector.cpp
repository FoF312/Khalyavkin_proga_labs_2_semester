#include "../inc/scripts/MyVector.h"
#include <algorithm>

// Конструктор по умолчанию
MyVector::MyVector() : data(nullptr), size_(0), capacity_(0) {}

// Конструктор копирования
MyVector::MyVector(const MyVector& other) : size_(other.size_), capacity_(other.capacity_) {
    data = new int[capacity_];
    std::copy(other.data, other.data + size_, data);
}

// Оператор присваивания копированием
MyVector& MyVector::operator=(const MyVector& other) {
    if (this != &other) {
        delete[] data;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data = new int[capacity_];
        std::copy(other.data, other.data + size_, data);
    }
    return *this;
}

// Деструктор
MyVector::~MyVector() {
    delete[] data;
}

// Изменение вместимости
void MyVector::resizeCapacity(size_t new_capacity) {
    if (new_capacity < size_) {
        size_ = new_capacity;
    }
    int* new_data = new int[new_capacity];
    std::copy(data, data + size_, new_data);
    delete[] data;
    data = new_data;
    capacity_ = new_capacity;
}

// Добавление элемента в конец
void MyVector::push_back(int value) {
    if (size_ >= capacity_) {
        resizeCapacity(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    data[size_++] = value;
}

// Вставка элемента по индексу
void MyVector::insert(size_t index, int value) {
    if (index > size_) {
        throw std::out_of_range("Index out of range");
    }
    if (size_ >= capacity_) {
        resizeCapacity(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    for (size_t i = size_; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size_++;
}

// Удаление элемента по индексу
void MyVector::erase(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size_ - 1; ++i) {
        data[i] = data[i + 1];
    }
    size_--;
}

// Изменение размера вектора
void MyVector::resize(size_t new_size, int value) {
    if (new_size > capacity_) {
        resizeCapacity(new_size);
    }
    if (new_size > size_) {
        std::fill(data + size_, data + new_size, value);
    }
    size_ = new_size;
}

// Резервирование памяти
void MyVector::reserve(size_t new_capacity) {
    if (new_capacity > capacity_) {
        resizeCapacity(new_capacity);
    }
}

// Освобождение неиспользуемой памяти
void MyVector::shrink_to_fit() {
    if (size_ < capacity_) {
        resizeCapacity(size_);
    }
}

// Доступ к элементам
int& MyVector::operator[](size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const int& MyVector::operator[](size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

int& MyVector::front() {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return data[0];
}

const int& MyVector::front() const {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return data[0];
}

int& MyVector::back() {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return data[size_ - 1];
}

const int& MyVector::back() const {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return data[size_ - 1];
}

// Информация о векторе
size_t MyVector::size() const {
    return size_;
}

size_t MyVector::capacity() const {
    return capacity_;
}

bool MyVector::empty() const {
    return size_ == 0;
}

// Вспомогательный метод для демонстрации
void MyVector::print() const {
    for (size_t i = 0; i < size_; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}