#include "../../inc/tests/TestRunner.h"
#include "../../inc/scripts/StringLength.h"
#include "../../inc/scripts/QuickSort.h"
#include "../../inc/scripts/PathFinder.h"
#include "../../inc/scripts/Utils.h"
#include <iostream>
#include <chrono>

void TestRunner::runAllTests() {
    runStringLengthTests();
    runQuickSortTests();
    runPathFinderTests();
}

void TestRunner::runStringLengthTests() {
    std::cout << "=== Running StringLength Tests ===" << std::endl;
    std::string str = "Hello, World!";
    int length = StringLength::calculateLength(str);
    std::cout << "Length of '" << str << "': " << length << std::endl;
    std::cout << "StringLength tests passed!\n" << std::endl;
}

void TestRunner::runQuickSortTests() {
    std::cout << "=== Running QuickSort Tests ===" << std::endl;
    std::vector<int> arr = {5, 3, 8, 4, 2};
    std::vector<int> arr2 = arr;

    auto start = std::chrono::high_resolution_clock::now();
    QuickSort::sort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "QuickSort: ";
    Utils::printArray(arr);
    std::cout << "Time: " << elapsed.count() << "s" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    QuickSort::bubbleSort(arr2);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "BubbleSort: ";
    Utils::printArray(arr2);
    std::cout << "Time: " << elapsed.count() << "s" << std::endl;
    std::cout << "QuickSort tests passed!\n" << std::endl;
}

void TestRunner::runPathFinderTests() {
    std::cout << "=== Running PathFinder Tests ===" << std::endl;
    std::vector<std::string> grid = {
        "S..#",
        ".#..",
        "..#E"
    };
    std::cout << "Grid:" << std::endl;
    Utils::printGrid(grid);
    int steps = PathFinder::findMinSteps(grid);
    std::cout << "Min steps: " << steps << std::endl;
    std::cout << "PathFinder tests passed!\n" << std::endl;
}