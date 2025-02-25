#include "../../../inc/tests/Logical/StringLengthLogicalTests.h"
#include "../../../inc/scripts/StringLength.h"
#include <cassert>
#include <iostream>

void StringLengthLogicalTests::runAllTests() {
    std::cout << "=== Running StringLength Logical Tests ===" << std::endl;

    // Тест 1: Рекурсия работает корректно
    std::string str = "Recursion";
    assert(StringLength::calculateLength(str) == 9);
    std::cout << "Test 1 passed: Recursion works correctly." << std::endl;

    // Тест 2: Обработка длинной строки
    std::string longStr(100, 'a');
    assert(StringLength::calculateLength(longStr) == 100);
    std::cout << "Test 2 passed: Long string handled correctly." << std::endl;

    // Тест 3: Обработка строки с нулевым символом
    std::string strWithNull = "Hello\0World";
    assert(StringLength::calculateLength(strWithNull) == 5);
    std::cout << "Test 3 passed: String with null character handled correctly." << std::endl;

    std::cout << "All StringLength Logical tests passed!\n" << std::endl;
}