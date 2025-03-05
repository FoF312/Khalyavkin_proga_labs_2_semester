#include "../Functional/RectangularParallelepipedFunctionalTests.h"
#include "../../scripts/RectangularParallelepiped.h"
#include <cassert>
#include <iostream>

void RectangularParallelepipedFunctionalTests::runAllTests() {
    std::cout << "=== Running Rectangular Parallelepiped Functional Tests ===" << std::endl;

    // Тест 1: Площадь поверхности
    RectangularParallelepiped rp1(2, 3, 4);
    assert(rp1.calculateSurfaceArea() == 52);
    std::cout << "Test 1 passed: Surface area calculation is correct." << std::endl;

    // Тест 2: Объем
    assert(rp1.calculateVolume() == 24);
    std::cout << "Test 2 passed: Volume calculation is correct." << std::endl;

    // Тест 3: Длина диагонали
    assert(rp1.calculateDiagonal() == std::sqrt(29));
    std::cout << "Test 3 passed: Diagonal calculation is correct." << std::endl;

    std::cout << "All Rectangular Parallelepiped Functional tests passed!\n" << std::endl;
}