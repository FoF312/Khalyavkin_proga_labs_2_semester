#pragma once
#include <iostream>
#include <stdexcept>

template <typename T, size_t N, size_t M>
class Matrix {
    static_assert(N <= 3 && M <= 3, "Matrix dimensions must be <= 3");

private:
    T data[N][M];

public:
    // Конструкторы
    Matrix() {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                data[i][j] = T();
            }
        }
    }
    Matrix(const Matrix& other);
    Matrix(const T (&arr)[N][M]);

    // Операторы
    Matrix& operator=(const Matrix& other);
    T& operator()(size_t i, size_t j);
    const T& operator()(size_t i, size_t j) const;
    Matrix operator+(const Matrix& other) const;
    Matrix& operator+=(const Matrix& other);
    Matrix operator*(const Matrix<T, M, N>& other) const;
    Matrix& operator*=(const Matrix<T, M, N>& other);
    Matrix& operator++(); // Префиксный ++
    Matrix operator++(int); // Постфиксный ++
    bool operator==(const Matrix& other) const;

    // Ввод/вывод
    template <typename U, size_t N1, size_t M1>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U, N1, M1>& matrix);
    template <typename U, size_t N1, size_t M1>
    friend std::istream& operator>>(std::istream& is, Matrix<U, N1, M1>& matrix);

    // Методы
    T determinant() const;
    size_t rows() const { return N; }
    size_t cols() const { return M; }
};