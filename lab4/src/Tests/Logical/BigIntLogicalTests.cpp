#include "Logical/BigIntLogicalTests.h"
#include "../../inc/Scripts/BigInt.h"
#include <iostream>
#include <sstream>
#include <cassert>

void BigIntLogicalTests::runAllTests() {
    std::cout << "\n=== Running Logical Tests ===" << std::endl;

    // Тест ввода и вывода
    {
        std::stringstream input("12345");
        BigInt num;
        input >> num;
        std::stringstream output;
        output << num;
        assert(output.str() == "12345");
        std::cout << "Test 1 passed: Input and output operators." << std::endl;
    }

    // Тест сложения с большими числами
    {
        BigInt a("99999999999999999999");
        BigInt b("1");
        BigInt result = a + b;
        assert(result.to_string() == "100000000000000000000");
        std::cout << "Test 2 passed: Addition with large numbers." << std::endl;
    }

    // Тест умножения с большими числами
    {
        BigInt a("123456789");
        BigInt b("987654321");
        BigInt result = a * b;
        assert(result.to_string() == "121932631112635269");
        std::cout << "Test 3 passed: Multiplication with large numbers." << std::endl;
    }

    std::cout << "All logical tests passed!\n" << std::endl;
}