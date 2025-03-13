#include "../Logical/CubeLogicalTests.h"
#include "../../inc/TaskExecutor.h"
#include <iostream>
#include <sstream>
#include <cassert>

void CubeLogicalTests::runAllTests() {
    std::cout << "=== Running Cube Logical Tests ===" << std::endl;

    // Тест 1: Корректный ввод пользователя
    {
        std::stringstream input("5\n"); // Пользователь вводит 5
        std::stringstream output;
        std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
        std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

        TaskExecutor::runCubeTask();

        std::cin.rdbuf(oldCin);
        std::cout.rdbuf(oldCout);

        std::string expectedOutput = 
            "=== Cube Task ===\n"
            "Enter the side length of the cube: "
            "Surface Area: 150\n"
            "Volume: 125\n"
            "Diagonal: 8.66025\n";
        assert(output.str() == expectedOutput);
        std::cout << "Test 1 passed: Correct user input handled correctly." << std::endl;
    }

    // Тест 2: Некорректный ввод пользователя (отрицательное число)
    {
        std::stringstream input("-3\n"); // Пользователь вводит -3
        std::stringstream output;
        std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
        std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

        TaskExecutor::runCubeTask();

        std::cin.rdbuf(oldCin);
        std::cout.rdbuf(oldCout);

        std::string expectedOutput = 
            "=== Cube Task ===\n"
            "Enter the side length of the cube: "
            "Surface Area: 54\n"
            "Volume: 27\n"
            "Diagonal: 5.19615\n";
        assert(output.str() == expectedOutput);
        std::cout << "Test 2 passed: Negative input handled correctly." << std::endl;
    }

    // Тест 3: Некорректный ввод пользователя (нулевое значение)
    {
        std::stringstream input("0\n"); // Пользователь вводит 0
        std::stringstream output;
        std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
        std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

        TaskExecutor::runCubeTask();

        std::cin.rdbuf(oldCin);
        std::cout.rdbuf(oldCout);

        std::string expectedOutput = 
            "=== Cube Task ===\n"
            "Enter the side length of the cube: "
            "Surface Area: 0\n"
            "Volume: 0\n"
            "Diagonal: 0\n";
        assert(output.str() == expectedOutput);
        std::cout << "Test 3 passed: Zero input handled correctly." << std::endl;
    }

    std::cout << "All Cube Logical tests passed!\n" << std::endl;
}