#include "../../../inc/tests/Logical/QuickSortLogicalTests.h"
#include "../../../inc/scripts/QuickSort.h"
#include "../../../inc/scripts/Utils.h"
#include <cassert>
#include <iostream>

void QuickSortLogicalTests::runAllTests() {
    std::cout << "=== Running QuickSort Logical Tests ===" << std::endl;

    // Тест 1: Проверка сортировки массива с дубликатами
    std::vector<int> arrWithDuplicates = {5, 3, 8, 4, 2, 5, 3};
    QuickSort::sort(arrWithDuplicates);
    assert((arrWithDuplicates == std::vector<int>{2, 3, 3, 4, 5, 5, 8}));
    std::cout << "Test 1 passed: Sorting with duplicates works correctly." << std::endl;

    // Тест 2: Проверка сортировки уже отсортированного массива
    std::vector<int> sortedArr = {1, 2, 3, 4, 5};
    QuickSort::sort(sortedArr);
    assert((sortedArr == std::vector<int>{1, 2, 3, 4, 5}));
    std::cout << "Test 2 passed: Sorting already sorted array works correctly." << std::endl;

    std::cout << "All QuickSort Logical tests passed!\n" << std::endl;
}