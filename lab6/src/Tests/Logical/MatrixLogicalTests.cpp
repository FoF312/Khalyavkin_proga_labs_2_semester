#include "Tests/Logical/MatrixLogicalTests.h"

void MatrixLogicalTests::runAll() {
    testMatrixProperties();
    testEdgeCases();
    testTypeSafety();
}

void MatrixLogicalTests::testMatrixProperties() {
    // Ассоциативность сложения
    Matrix<int, 2, 2> m1 = {{{1, 2}, {3, 4}}};
    Matrix<int, 2, 2> m2 = {{{5, 6}, {7, 8}}};
    Matrix<int, 2, 2> m3 = {{{9, 10}, {11, 12}}};
    
    ASSERT((m1 + m2) + m3 == m1 + (m2 + m3));
    
    // Дистрибутивность умножения
    ASSERT(m1 * (m2 + m3) == m1 * m2 + m1 * m3);
}

void MatrixLogicalTests::testEdgeCases() {
    // Тест с нулевой матрицей
    Matrix<int, 2, 2> zero;
    Matrix<int, 2, 2> mat = {{{1, 2}, {3, 4}}};
    
    ASSERT(mat + zero == mat);
    ASSERT(mat * zero == zero);
    
    // Тест с единичной матрицей
    Matrix<int, 2, 2> identity = {{{1, 0}, {0, 1}}};
    ASSERT(mat * identity == mat);
}

void MatrixLogicalTests::testTypeSafety() {
    // Проверка работы с double
    Matrix<double, 2, 2> mat = {{{1.5, 2.5}, {3.5, 4.5}}};
    ASSERT(mat.determinant() == (1.5*4.5 - 2.5*3.5));
}