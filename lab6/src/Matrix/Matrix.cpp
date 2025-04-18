#include "../../inc/Matrix/Matrix.h"

// Конструктор копирования
template <typename T, size_t N, size_t M>
Matrix<T, N, M>::Matrix(const Matrix& other) {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Конструктор из двумерного массива
template <typename T, size_t N, size_t M>
Matrix<T, N, M>::Matrix(const T (&arr)[N][M]) {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            data[i][j] = arr[i][j];
        }
    }
}

// Оператор присваивания
template <typename T, size_t N, size_t M>
Matrix<T, N, M>& Matrix<T, N, M>::operator=(const Matrix& other) {
    if (this != &other) {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

// Оператор доступа к элементам
template <typename T, size_t N, size_t M>
T& Matrix<T, N, M>::operator()(size_t i, size_t j) {
    if (i >= N || j >= M) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return data[i][j];
}

// Константный оператор доступа к элементам
template <typename T, size_t N, size_t M>
const T& Matrix<T, N, M>::operator()(size_t i, size_t j) const {
    if (i >= N || j >= M) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return data[i][j];
}

// Оператор сложения матриц
template <typename T, size_t N, size_t M>
Matrix<T, N, M> Matrix<T, N, M>::operator+(const Matrix& other) const {
    Matrix result;
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Оператор +=
template <typename T, size_t N, size_t M>
Matrix<T, N, M>& Matrix<T, N, M>::operator+=(const Matrix& other) {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

// Оператор умножения матриц
template <typename T, size_t N, size_t M>
Matrix<T, N, M> Matrix<T, N, M>::operator*(const Matrix<T, M, N>& other) const {
    Matrix<T, N, M> result;
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            result(i, j) = T();
            for (size_t k = 0; k < M; ++k) {
                result(i, j) += data[i][k] * other(k, j);
            }
        }
    }
    return result;
}

// Оператор *=
template <typename T, size_t N, size_t M>
Matrix<T, N, M>& Matrix<T, N, M>::operator*=(const Matrix<T, M, N>& other) {
    *this = *this * other;
    return *this;
}

// Префиксный ++ (увеличение всех элементов на 1)
template <typename T, size_t N, size_t M>
Matrix<T, N, M>& Matrix<T, N, M>::operator++() {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            ++data[i][j];
        }
    }
    return *this;
}

// Постфиксный ++
template <typename T, size_t N, size_t M>
Matrix<T, N, M> Matrix<T, N, M>::operator++(int) {
    Matrix temp = *this;
    ++(*this);
    return temp;
}

// Вычисление определителя
template <typename T, size_t N, size_t M>
T Matrix<T, N, M>::determinant() const {
    static_assert(N == M, "Determinant is only defined for square matrices");
    
    if constexpr (N == 1) {
        return data[0][0];
    } else if constexpr (N == 2) {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    } else if constexpr (N == 3) {
        return data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
               data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
               data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
    }
    return T();
}

// Оператор вывода
template <typename T, size_t N, size_t M>
std::ostream& operator<<(std::ostream& os, const Matrix<T, N, M>& matrix) {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            os << matrix(i, j) << ' ';
        }
        os << '\n';
    }
    return os;
}

// Оператор ввода
template <typename T, size_t N, size_t M>
std::istream& operator>>(std::istream& is, Matrix<T, N, M>& matrix) {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            is >> matrix(i, j);
        }
    }
    return is;
}

// Оператор сравнения
template <typename T, size_t N, size_t M>
bool Matrix<T, N, M>::operator==(const Matrix& other) const {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

template class Matrix<int, 1, 1>;
template class Matrix<int, 2, 2>;
template class Matrix<int, 3, 3>;
template class Matrix<double, 1, 1>;
template class Matrix<double, 2, 2>;
template class Matrix<double, 3, 3>;

template std::ostream& operator<<(std::ostream& os, const Matrix<int, 2, 2>& matrix);
template std::istream& operator>>(std::istream& is, Matrix<int, 2, 2>& matrix);