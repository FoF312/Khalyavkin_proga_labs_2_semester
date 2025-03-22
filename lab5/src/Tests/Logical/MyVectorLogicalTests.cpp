#include "../inc/tests/Logical/MyVectorLogicalTests.h"
#include "../../inc/scripts/MyVector.h"
#include <cassert>
#include <iostream>

void MyVectorLogicalTests::runAllTests() {
    std::cout << "\n=== Running Logical Tests ===" << std::endl;

    // Тест 1: Копирование и присваивание
    {
        MyVector vec1;
        vec1.push_back(10);
        vec1.push_back(20);

        MyVector vec2 = vec1;  // Конструктор копирования
        assert(vec2.size() == 2);
        assert(vec2[0] == 10);
        assert(vec2[1] == 20);

        MyVector vec3;
        vec3 = vec1;  // Оператор присваивания
        assert(vec3.size() == 2);
        assert(vec3[0] == 10);
        assert(vec3[1] == 20);

        std::cout << "Test 1 passed: Copy constructor and assignment operator." << std::endl;
    }

    // Тест 2: Комплексная работа с вектором
    {
        MyVector vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.insert(1, 15);
        vec.erase(0);
        vec.resize(5, 42);

        assert(vec.size() == 5);
        assert(vec[0] == 15);
        assert(vec[4] == 42);
        std::cout << "Test 2 passed: Complex vector operations." << std::endl;
    }

    std::cout << "All logical tests passed!\n" << std::endl;
}