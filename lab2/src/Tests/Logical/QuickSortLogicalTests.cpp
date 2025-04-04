#include "../Logical/QuickSortLogicalTests.h"
#include "../../scripts/QuickSort.h"
#include <cassert>
#include <iostream>
#include <vector>

void QuickSortLogicalTests::runAllTests() {
    std::cout << "=== Running QuickSort Logical Tests ===" << std::endl;

    // Тест 1: Пустой массив
    std::vector<int> arr1 = {};
    QuickSort::sort(arr1);
    assert(arr1.empty());
    std::cout << "Test 1 passed: Empty array remains empty." << std::endl;

    // Тест 2: Массив из одного элемента
    std::vector<int> arr2 = {42};
    QuickSort::sort(arr2);
    assert(arr2 == std::vector<int>({42}));
    std::cout << "Test 2 passed: Single-element array remains unchanged." << std::endl;

    // Тест 3: Большой массив
    std::vector<int> arr3 = {9, 7, 5, 3, 1, 2, 4, 6, 8};
    QuickSort::sort(arr3);
    assert(arr3 == std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    std::cout << "Test 3 passed: Large array sorted correctly." << std::endl;

    std::cout << "All QuickSort Logical tests passed!\n" << std::endl;
}