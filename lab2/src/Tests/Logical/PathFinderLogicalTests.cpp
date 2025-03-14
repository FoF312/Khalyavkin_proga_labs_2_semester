#include "../Logical/PathFinderLogicalTests.h"
#include "../../scripts/PathFinder.h"
#include <cassert>
#include <iostream>
#include <vector>

void PathFinderLogicalTests::runAllTests() {
    std::cout << "=== Running Path Finder Logical Tests ===" << std::endl;

    // Тест 1: Нулевое поле
    std::vector<std::string> grid1 = {};
    assert(PathFinder::findMinSteps(grid1) == -1);
    std::cout << "Test 1 passed: Empty grid handled correctly." << std::endl;

    // Тест 2: Поле без начальной или конечной точки
    std::vector<std::string> grid2 = {
        "....",
        "....",
        "...."
    };
    assert(PathFinder::findMinSteps(grid2) == -1);
    std::cout << "Test 2 passed: Grid without start or end handled correctly." << std::endl;

    // Тест 3: Большое поле
    std::vector<std::string> grid3 = {
        "S.........",
        "..........",
        "..........",
        "..........",
        "..........",
        "..........",
        "..........",
        "..........",
        "..........",
        ".........E"
    };
    assert(PathFinder::findMinSteps(grid3) == 18);
    std::cout << "Test 3 passed: Large grid handled correctly." << std::endl;

    std::cout << "All Path Finder Logical tests passed!\n" << std::endl;
}