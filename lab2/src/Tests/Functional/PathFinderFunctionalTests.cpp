#include "../../../inc/tests/Functional/PathFinderFunctionalTests.h"
#include "../../../inc/scripts/PathFinder.h"
#include "../../../inc/scripts/Utils.h"
#include <cassert>
#include <iostream>

void PathFinderFunctionalTests::runAllTests() {
    std::cout << "=== Running PathFinder Functional Tests ===" << std::endl;

    // Тест 1: Простой путь
    std::vector<std::string> grid1 = {
        "S..#",
        ".#..",
        "..#E"
    };
    assert(PathFinder::findMinSteps(grid1) == 4);
    std::cout << "Test 1 passed: Minimum steps for grid1 is 4." << std::endl;

    // Тест 2: Невозможный путь
    std::vector<std::string> grid2 = {
        "S###",
        "####",
        "###E"
    };
    assert(PathFinder::findMinSteps(grid2) == -1);
    std::cout << "Test 2 passed: No path found for grid2." << std::endl;

    // Тест 3: Путь по диагонали
    std::vector<std::string> grid3 = {
        "S..",
        "...",
        "..E"
    };
    assert(PathFinder::findMinSteps(grid3) == 2);
    std::cout << "Test 3 passed: Minimum steps for grid3 is 2." << std::endl;

    // Тест 4: Большое поле
    std::vector<std::string> grid4 = {
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
    assert(PathFinder::findMinSteps(grid4) == 18);
    std::cout << "Test 4 passed: Minimum steps for grid4 is 18." << std::endl;

    std::cout << "All PathFinder Functional tests passed!\n" << std::endl;
}