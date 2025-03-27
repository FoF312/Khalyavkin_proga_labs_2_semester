#include "../inc/tests/Functional/MyVectorFunctionalTests.h"
#include "../../inc/scripts/MyVector.h"
#include <cassert>
#include <iostream>

void MyVectorFunctionalTests::runAllTests() {
    std::cout << "\n=== Running Functional Tests ===" << std::endl;

    // Тест 1: Конструктор и size
    {
        MyVector vec;
        assert(vec.size() == 0);
        assert(vec.empty());
        std::cout << "Test 1 passed: Constructor and size." << std::endl;
    }

    // Тест 2: push_back и operator[]
    {
        MyVector vec;
        vec.push_back(10);
        vec.push_back(20);
        assert(vec.size() == 2);
        assert(vec[0] == 10);
        assert(vec[1] == 20);
        std::cout << "Test 2 passed: push_back and operator[]." << std::endl;
    }

    // Тест 3: insert и erase
    {
        MyVector vec;
        vec.push_back(10);
        vec.push_back(30);
        vec.insert(1, 20);
        assert(vec.size() == 3);
        assert(vec[1] == 20);
        vec.erase(1);
        assert(vec.size() == 2);
        assert(vec[1] == 30);
        std::cout << "Test 3 passed: insert and erase." << std::endl;
    }

    // Тест 4: resize и reserve
    {
        MyVector vec;
        vec.reserve(10);
        assert(vec.capacity() == 10);
        vec.resize(5, 42);
        assert(vec.size() == 5);
        assert(vec[4] == 42);
        std::cout << "Test 4 passed: resize and reserve." << std::endl;
    }

    std::cout << "All functional tests passed!\n" << std::endl;
}