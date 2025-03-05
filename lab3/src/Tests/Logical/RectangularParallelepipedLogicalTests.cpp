#include "../Logical/RectangularParallelepipedLogicalTests.h"
#include "../../scripts/RectangularParallelepiped.h"
#include <cassert>
#include <iostream>

void RectangularParallelepipedLogicalTests::runAllTests() {
    std::cout << "=== Running Rectangular Parallelepiped Logical Tests ===" << std::endl;

    // Тест 1: Нулевые значения
    RectangularParallelepiped rp1(0, 0, 0);
    assert(rp1.calculateSurfaceArea() == 0);
    assert(rp1.calculateVolume() == 0);
    assert(rp1.calculateDiagonal() == 0);
    std::cout << "Test 1 passed: Zero values handled correctly." << std::endl;

    // Тест 2: Отрицательные значения (должны быть обработаны как положительные)
    RectangularParallelepiped rp2(-2, -3, -4);
    assert(rp2.calculateSurfaceArea() == 52);
    assert(rp2.calculateVolume() == 24);
    assert(rp2.calculateDiagonal() == std::sqrt(29));
    std::cout << "Test 2 passed: Negative values handled correctly." << std::endl;

    // Тест 3: Большие значения
    RectangularParallelepiped rp3(100, 200, 300);
    assert(rp3.calculateSurfaceArea() == 220000);
    assert(rp3.calculateVolume() == 6000000);
    assert(rp3.calculateDiagonal() == std::sqrt(100 * 100 + 200 * 200 + 300 * 300));
    std::cout << "Test 3 passed: Large values handled correctly." << std::endl;

    std::cout << "All Rectangular Parallelepiped Logical tests passed!\n" << std::endl;
}