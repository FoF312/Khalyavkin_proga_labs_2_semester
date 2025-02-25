#include "../../../inc/tests/Logical/PathFinderLogicalTests.h"
#include "../../../inc/scripts/PathFinder.h"
#include "../../../inc/scripts/Utils.h"
#include <cassert>
#include <iostream>

void PathFinderLogicalTests::runAllTests() {
    std::cout << "=== Running PathFinder Logical Tests ===" << std::endl;

    // Тест 1: Проверка корректности BFS
    std::vector<std::string> grid1 = {
        "S..#",
        ".#..",
        "..#E"
    };
    assert(PathFinder::findMinSteps(grid1) == 4);
    std::cout << "Test 1 passed: BFS works correctly." << std::endl;

    // Тест 2: Проверка обработки невозможного пути
    std::vector<std::string> grid2 = {
        "S###",
        "####",
        "###E"
    };
    assert(PathFinder::findMinSteps(grid2) == -1);
    std::cout << "Test 2 passed: Impossible path handled correctly." << std::endl;

    // Тест 3: Проверка обработки большого поля
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

    std::cout << "All PathFinder Logical tests passed!\n" << std::endl;
}