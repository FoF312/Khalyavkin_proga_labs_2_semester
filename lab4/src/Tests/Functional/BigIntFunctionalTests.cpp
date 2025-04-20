#include "Functional/BigIntFunctionalTests.h"
#include "../../inc/scripts/BigInt.h"
#include <cassert>
#include <iostream>

void BigIntFunctionalTests::runAllTests() {
    std::cout << "\n=== Running Functional Tests ===" << std::endl;

    // Тест конструктора из строки
    {
        BigInt num("12345");
        assert(num.to_string() == "12345");
        std::cout << "Test 1 passed: Constructor from string." << std::endl;
    }

    // Тест сложения
    {
        BigInt a("123");
        BigInt b("456");
        BigInt result = a + b;
        assert(result.to_string() == "579");
        std::cout << "Test 2 passed: Addition." << std::endl;
    }

    // Тест умножения
    {
        BigInt a("123");
        BigInt b("456");
        BigInt result = a * b;
        assert(result.to_string() == "56088");
        std::cout << "Test 3 passed: Multiplication." << std::endl;
    }

    // Тест сравнения
    {
        BigInt a("123");
        BigInt b("456");
        assert(a < b);
        assert(b > a);
        assert(a != b);
        std::cout << "Test 4 passed: Comparison operators." << std::endl;
    }

    std::cout << "All functional tests passed!\n" << std::endl;
}