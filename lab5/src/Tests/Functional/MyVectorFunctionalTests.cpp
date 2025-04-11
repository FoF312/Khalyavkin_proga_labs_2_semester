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

    // Тест 5: Конструктор копирования и оператор присваивания
    {
        MyVector vec1;
        vec1.push_back(1);
        vec1.push_back(2);
        vec1.push_back(3);

        MyVector vec2(vec1);  // Конструктор копирования
        assert(vec2.size() == vec1.size());
        assert(vec2[0] == 1 && vec2[1] == 2 && vec2[2] == 3);

        MyVector vec3;
        vec3 = vec1;  // Оператор присваивания
        assert(vec3.size() == vec1.size());
        assert(vec3[0] == 1 && vec3[1] == 2 && vec3[2] == 3);
        std::cout << "Test 5 passed: Copy constructor and assignment operator." << std::endl;
    }

    // Тест 6: front() и back()
    {
        MyVector vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        assert(vec.front() == 10);
        assert(vec.back() == 30);

        const MyVector const_vec = vec;
        assert(const_vec.front() == 10);
        assert(const_vec.back() == 30);
        std::cout << "Test 6 passed: front() and back()." << std::endl;
    }

    // Тест 7: shrink_to_fit()
    {
        MyVector vec;
        vec.reserve(100);
        vec.push_back(1);
        vec.push_back(2);
        assert(vec.capacity() == 100);
        vec.shrink_to_fit();
        assert(vec.capacity() == 2);
        assert(vec.size() == 2);
        std::cout << "Test 7 passed: shrink_to_fit()." << std::endl;
    }

    // Тест 8: Константные версии операторов
    {
        MyVector vec;
        vec.push_back(1);
        vec.push_back(2);
        const MyVector const_vec = vec;
        assert(const_vec[0] == 1);
        assert(const_vec[1] == 2);
        std::cout << "Test 8 passed: Const operators." << std::endl;
    }

    std::cout << "All functional tests passed!\n" << std::endl;
}