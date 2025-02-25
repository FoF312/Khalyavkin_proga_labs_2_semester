#include "../../../inc/tests/Functional/StringLengthFunctionalTests.h"
#include "../../../inc/scripts/StringLength.h"
#include <cassert>
#include <iostream>

void StringLengthFunctionalTests::runAllTests() {
    std::cout << "=== Running StringLength Functional Tests ===" << std::endl;

    // Тест 1: Пустая строка
    std::string emptyStr = "";
    assert(StringLength::calculateLength(emptyStr) == 0);
    std::cout << "Test 1 passed: Empty string length is 0." << std::endl;

    // Тест 2: Обычная строка
    std::string str = "Hello, World!";
    assert(StringLength::calculateLength(str) == 13);
    std::cout << "Test 2 passed: Length of 'Hello, World!' is 13." << std::endl;

    // Тест 3: Строка с пробелами
    std::string strWithSpaces = "   ";
    assert(StringLength::calculateLength(strWithSpaces) == 3);
    std::cout << "Test 3 passed: Length of '   ' is 3." << std::endl;

    // Тест 4: Строка с символами
    std::string strWithSymbols = "!@#$%^&*()";
    assert(StringLength::calculateLength(strWithSymbols) == 10);
    std::cout << "Test 4 passed: Length of '!@#$%^&*()' is 10." << std::endl;

    std::cout << "All StringLength Functional tests passed!\n" << std::endl;
}