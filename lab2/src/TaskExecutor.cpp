#include "../inc/TaskExecutor.h"
#include "../inc/scripts/StringLength.h"
#include "../inc/scripts/QuickSort.h"
#include "../inc/scripts/PathFinder.h"
#include <iostream>

void TaskExecutor::printAssignment() {
    std::cout << "=== Assignment ===" << std::endl;
    std::cout << "1. String Length: Calculate the length of a string." << std::endl;
    std::cout << "2. QuickSort: Sort an array using the QuickSort algorithm." << std::endl;
    std::cout << "3. Path Finder: Find the minimum steps to reach the end in a grid." << std::endl;
    std::cout << "==================" << std::endl;
}

void TaskExecutor::runStringLengthTask() {
    std::cout << "=== String Length Task ===" << std::endl;
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    std::cout << "Length of the string: " << StringLength::calculateLength(input) << std::endl;
}

void TaskExecutor::runQuickSortTask() {
    std::cout << "=== QuickSort Task ===" << std::endl;
    std::vector<int> arr;
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        arr.push_back(element);
    }
    QuickSort::sort(arr);
    std::cout << "Sorted array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void TaskExecutor::runPathFinderTask() {
    std::cout << "=== Path Finder Task ===" << std::endl;
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;
    std::vector<std::string> grid(rows);
    std::cin.ignore(); // Очистка буфера ввода
    std::cout << "Enter the grid (each row on a new line): " << std::endl;
    for (int i = 0; i < rows; ++i) {
        std::getline(std::cin, grid[i]);
    }
    int steps = PathFinder::findMinSteps(grid);
    if (steps == -1) {
        std::cout << "No path found!" << std::endl;
    } else {
        std::cout << "Minimum steps to reach the end: " << steps << std::endl;
    }
}