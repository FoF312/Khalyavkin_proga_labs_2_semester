#include "../Functional/PathFinderFunctionalTests.h"
#include "../../scripts/PathFinder.h"
#include <cassert>
#include <iostream>
#include <vector>

void PathFinderFunctionalTests::runAllTests() {
    std::cout << "=== Running Path Finder Functional Tests ===" << std::endl;

    // Тест 1: Простой путь
    std::vector<std::string> grid1 = {
        "S..#",
        ".#..",
        "..#E"
    };
    assert(PathFinder::findMinSteps(grid1) == 5);
    std::cout << "Test 1 passed: Simple path found correctly." << std::endl;

    // Тест 2: Невозможный путь
    std::vector<std::string> grid2 = {
        "S###",
        "####",
        "###E"
    };
    assert(PathFinder::findMinSteps(grid2) == -1);
    std::cout << "Test 2 passed: Impossible path handled correctly." << std::endl;

    // Тест 3: Путь без диагоналей
    std::vector<std::string> grid3 = {
        "S..",
        "...",
        "..E"
    };
    assert(PathFinder::findMinSteps(grid3) == 4);
    std::cout << "Test 3 passed: Path found correctly." << std::endl;

    std::cout << "All Path Finder Functional tests passed!\n" << std::endl;
}