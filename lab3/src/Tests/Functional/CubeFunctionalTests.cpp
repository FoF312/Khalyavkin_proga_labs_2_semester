#include "../Functional/CubeFunctionalTests.h"
#include "../../scripts/Cube.h"
#include <cassert>
#include <iostream>

void CubeFunctionalTests::runAllTests() {
    std::cout << "=== Running Cube Functional Tests ===" << std::endl;

    // Тест 1: Площадь поверхности
    Cube cube1(2);
    assert(cube1.calculateSurfaceArea() == 24);
    std::cout << "Test 1 passed: Surface area calculation is correct." << std::endl;

    // Тест 2: Объем
    assert(cube1.calculateVolume() == 8);
    std::cout << "Test 2 passed: Volume calculation is correct." << std::endl;

    // Тест 3: Длина диагонали
    assert(cube1.calculateDiagonal() == 2 * std::sqrt(3));
    std::cout << "Test 3 passed: Diagonal calculation is correct." << std::endl;

    std::cout << "All Cube Functional tests passed!\n" << std::endl;
}