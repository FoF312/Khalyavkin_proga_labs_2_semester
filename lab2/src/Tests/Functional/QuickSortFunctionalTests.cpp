#include "../../../inc/tests/Functional/QuickSortFunctionalTests.h"
#include "../../../inc/scripts/QuickSort.h"
#include "../../../inc/scripts/Utils.h"
#include <cassert>
#include <iostream>

void QuickSortFunctionalTests::runAllTests() {
    std::cout << "=== Running QuickSort Functional Tests ===" << std::endl;

    // Тест 1: Сортировка массива
    std::vector<int> arr = {5, 3, 8, 4, 2};
    std::vector<int> sortedArr = {2, 3, 4, 5, 8};

    QuickSort::sort(arr);
    assert(arr == sortedArr);
    std::cout << "Test 1 passed: Array sorted correctly." << std::endl;

    // Тест 2: Пустой массив
    std::vector<int> emptyArr = {};
    QuickSort::sort(emptyArr);
    assert(emptyArr.empty());
    std::cout << "Test 2 passed: Empty array remains empty." << std::endl;

    // Тест 3: Массив из одного элемента
    std::vector<int> singleElementArr = {42};
    QuickSort::sort(singleElementArr);
    assert(singleElementArr == std::vector<int>{42});
    std::cout << "Test 3 passed: Single-element array remains unchanged." << std::endl;

    // Тест 4: Массив с дубликатами
    std::vector<int> arrWithDuplicates = {5, 3, 8, 4, 2, 5, 3};
    std::vector<int> sortedArrWithDuplicates = {2, 3, 3, 4, 5, 5, 8};

    QuickSort::sort(arrWithDuplicates);
    assert(arrWithDuplicates == sortedArrWithDuplicates);
    std::cout << "Test 4 passed: Array with duplicates sorted correctly." << std::endl;

    std::cout << "All QuickSort Functional tests passed!\n" << std::endl;
}