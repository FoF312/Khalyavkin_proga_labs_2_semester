// MatrixFunctionalTests.cpp
#include "Tests/Functional/MatrixFunctionalTests.h"

void MatrixFunctionalTests::runAll() {
    testConstructors();
    testElementAccess();
    testArithmeticOperations();
    testIncrementOperators();
    testDeterminant();
    testIOOperations();
}

void MatrixFunctionalTests::testConstructors() {
    // Тест конструктора по умолчанию
    Matrix<int, 2, 2> defaultMat;
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            ASSERT(defaultMat(i, j) == 0);
        }
    }
    
    // Тест конструктора копирования
    Matrix<int, 2, 2> mat1 = {{{1, 2}, {3, 4}}};
    Matrix<int, 2, 2> mat2(mat1);
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            ASSERT(mat1(i, j) == mat2(i, j));
        }
    }
}

void MatrixFunctionalTests::testElementAccess() {
    Matrix<int, 2, 2> mat;
    
    // Проверка записи и чтения
    mat(0, 0) = 10;
    ASSERT(mat(0, 0) == 10);
    
    // Проверка выхода за границы
    ASSERT_THROWS(mat(3, 3), std::out_of_range);
}

void MatrixFunctionalTests::testArithmeticOperations() {
    Matrix<int, 2, 2> mat1 = {{{1, 2}, {3, 4}}};
    Matrix<int, 2, 2> mat2 = {{{5, 6}, {7, 8}}};
    
    // Тест сложения
    auto sum = mat1 + mat2;
    ASSERT(sum(0, 0) == 6 && sum(0, 1) == 8 && sum(1, 0) == 10 && sum(1, 1) == 12);
    
    // Тест умножения
    Matrix<int, 2, 2> mat3 = {{{1, 2}, {3, 4}}};
    Matrix<int, 2, 2> mat4 = {{{2, 0}, {1, 2}}};
    auto product = mat3 * mat4;
    ASSERT(product(0, 0) == 4 && product(0, 1) == 4 && product(1, 0) == 10 && product(1, 1) == 8);
}

void MatrixFunctionalTests::testIncrementOperators() {
    Matrix<int, 2, 2> mat = {{{1, 2}, {3, 4}}};
    
    // Префиксный инкремент
    ++mat;
    ASSERT(mat(0, 0) == 2 && mat(0, 1) == 3 && mat(1, 0) == 4 && mat(1, 1) == 5);
    
    // Постфиксный инкремент
    Matrix<int, 2, 2> copy = mat++;
    ASSERT(copy(0, 0) == 2 && mat(0, 0) == 3);
}

void MatrixFunctionalTests::testDeterminant() {
    Matrix<int, 1, 1> mat1 = {{{5}}};
    ASSERT(mat1.determinant() == 5);
    
    Matrix<int, 2, 2> mat2 = {{{1, 2}, {3, 4}}};
    ASSERT(mat2.determinant() == -2);
    
    Matrix<int, 3, 3> mat3 = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    ASSERT(mat3.determinant() == 0);
}

void MatrixFunctionalTests::testIOOperations() {
    // Тест вывода
    Matrix<int, 2, 2> mat = {{{1, 2}, {3, 4}}};
    std::ostringstream oss;
    oss << mat;
    ASSERT(oss.str() == "1 2 \n3 4 \n");
    
    // Тест ввода
    std::istringstream iss("5 6 7 8");
    Matrix<int, 2, 2> inputMat;
    iss >> inputMat;
    ASSERT(inputMat(0, 0) == 5 && inputMat(0, 1) == 6);
}