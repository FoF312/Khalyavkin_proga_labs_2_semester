#include "../Functional/ReverseNumberFunctionalTests.h"
#include "../../scripts/ReverseNumber.h"
#include <cassert>
#include <iostream>

void ReverseNumberFunctionalTests::runAllTests() {
    std::cout << "=== Running Reverse Number Functional Tests ===" << std::endl;

    // Тест 1: Положительное число
    assert(ReverseNumber::reverse(12345) == 54321);
    std::cout << "Test 1 passed: Positive number reversed correctly." << std::endl;

    // Тест 2: Число с нулями на конце
    assert(ReverseNumber::reverse(1000) == 1);
    std::cout << "Test 2 passed: Number with trailing zeros reversed correctly." << std::endl;

    // Тест 3: Однозначное число
    assert(ReverseNumber::reverse(7) == 7);
    std::cout << "Test 3 passed: Single-digit number reversed correctly." << std::endl;

    std::cout << "All Reverse Number Functional tests passed!\n" << std::endl;
}