#include "../Logical/ReverseNumberLogicalTests.h"
#include "../../scripts/ReverseNumber.h"
#include <cassert>
#include <iostream>

void ReverseNumberLogicalTests::runAllTests() {
    std::cout << "=== Running Reverse Number Logical Tests ===" << std::endl;

    // Тест 1: Нулевое значение
    assert(ReverseNumber::reverse(0) == 0);
    std::cout << "Test 1 passed: Zero reversed correctly." << std::endl;

    // Тест 2: Отрицательное число (должно быть обработано как положительное)
    assert(ReverseNumber::reverse(-123) == -321);
    std::cout << "Test 2 passed: Negative number reversed correctly." << std::endl;

    // Тест 3: Большое число
    assert(ReverseNumber::reverse(123456789) == 987654321);
    std::cout << "Test 3 passed: Large number reversed correctly." << std::endl;

    std::cout << "All Reverse Number Logical tests passed!\n" << std::endl;
}