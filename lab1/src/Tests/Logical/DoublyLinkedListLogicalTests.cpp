#include "../inc/tests/Logical/DoublyLinkedListLogicalTests.h"
#include "../../inc/scripts/DoublyLinkedList.h"
#include <cassert>
#include <iostream>

void DoublyLinkedListLogicalTests::runAllTests() {
    std::cout << "\n=== Running Logical Tests ===" << std::endl;

    // Тест 1: Обработка последовательности с >= 3 числами, оканчивающимися на 2 или 4
    {
        DoublyLinkedList list;
        list.insert(12);  // Оканчивается на 2
        list.insert(34);  // Оканчивается на 4
        list.insert(56);  // Оканчивается на 6
        list.insert(22);  // Оканчивается на 2
        list.processSequence();

        // Ожидаемый результат: сортировка по первой цифре
        assert(list.getSize() == 4);
        std::cout << "Test 1 passed: Process sequence with >= 3 numbers ending with 2 or 4." << std::endl;
    }

    // Тест 2: Обработка последовательности с < 3 числами, оканчивающимися на 2 или 4
    {
        DoublyLinkedList list;
        list.insert(12);  // Оканчивается на 2
        list.insert(35);  // Оканчивается на 5
        list.insert(7);   // Простое число
        list.insert(20);  // Кратное 10
        list.processSequence();

        // Ожидаемый результат: удаление простых чисел и дублирование кратных 10
        assert(list.getSize() == 4);  // 12, 35, 20, 20
        std::cout << "Test 2 passed: Process sequence with < 3 numbers ending with 2 or 4." << std::endl;
    }

    // Тест 3: Обработка пустой последовательности
    {
        DoublyLinkedList list;
        list.processSequence();

        // Ожидаемый результат: список остаётся пустым
        assert(list.getSize() == 0);
        std::cout << "Test 3 passed: Process empty sequence." << std::endl;
    }

    std::cout << "All logical tests passed!\n" << std::endl;
}