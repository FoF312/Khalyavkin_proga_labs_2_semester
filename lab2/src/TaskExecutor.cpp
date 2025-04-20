#include "../inc/TaskExecutor.h"
#include "../inc/scripts/ReverseNumber.h"
#include "../inc/scripts/QuickSort.h"
#include "../inc/scripts/PathFinder.h"
#include <iostream>
#include <vector>

void TaskExecutor::printAssignment() {
    std::cout << "=== Assignment ===" << std::endl;
    std::cout << "1. Reverse a number using recursion." << std::endl;
    std::cout << "2. Implement QuickSort and compare with Bubble Sort." << std::endl;
    std::cout << "3. Find the minimum steps to move from 'S' to 'E' in a grid." << std::endl;
    std::cout << "==================" << std::endl;
}

void TaskExecutor::runReverseNumberTask() {
    std::cout << "=== Reverse Number Task ===" << std::endl;

    long long number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    long long reversed = ReverseNumber::reverse(number);
    std::cout << "Reversed number: " << reversed << std::endl;
}

void TaskExecutor::runQuickSortTask() {
    std::cout << "=== QuickSort Task ===" << std::endl;

    std::vector<int> arr = {5, 3, 8, 4, 2};
    std::cout << "Original array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    QuickSort::sort(arr);
    std::cout << "Sorted array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void TaskExecutor::runPathFinderTask() {
    std::cout << "=== Path Finder Task ===" << std::endl;

    std::vector<std::string> grid = {
        "S..#",
        ".#..",
        "..#E"
    };

    int steps = PathFinder::findMinSteps(grid);
    if (steps == -1) {
        std::cout << "No path found!" << std::endl;
    } else {
        std::cout << "Minimum steps: " << steps << std::endl;
    }
}