#include "../Functional/QuickSortFunctionalTests.h"
#include "../../scripts/QuickSort.h"
#include <cassert>
#include <iostream>
#include <vector>

void QuickSortFunctionalTests::runAllTests() {
    std::cout << "=== Running QuickSort Functional Tests ===" << std::endl;

    // Тест 1: Обычный массив
    std::vector<int> arr1 = {5, 3, 8, 4, 2};
    QuickSort::sort(arr1);
    assert(arr1 == std::vector<int>({2, 3, 4, 5, 8}));
    std::cout << "Test 1 passed: Regular array sorted correctly." << std::endl;

    // Тест 2: Массив с дубликатами
    std::vector<int> arr2 = {5, 3, 8, 4, 2, 5, 3};
    QuickSort::sort(arr2);
    assert(arr2 == std::vector<int>({2, 3, 3, 4, 5, 5, 8}));
    std::cout << "Test 2 passed: Array with duplicates sorted correctly." << std::endl;

    // Тест 3: Уже отсортированный массив
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    QuickSort::sort(arr3);
    assert(arr3 == std::vector<int>({1, 2, 3, 4, 5}));
    std::cout << "Test 3 passed: Already sorted array remains sorted." << std::endl;

    std::cout << "All QuickSort Functional tests passed!\n" << std::endl;
}