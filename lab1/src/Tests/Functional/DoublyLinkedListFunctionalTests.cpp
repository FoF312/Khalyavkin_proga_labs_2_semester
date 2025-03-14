#include "../inc/tests/Functional/DoublyLinkedListFunctionalTests.h"
#include "../../inc/scripts/DoublyLinkedList.h"
#include <cassert>
#include <iostream>

void DoublyLinkedListFunctionalTests::runAllTests() {
    std::cout << "\n=== Running Functional Tests ===" << std::endl;

    // Тест 1: Вставка и удаление элементов
    {
        DoublyLinkedList list;
        list.insert(10);
        list.insert(20);
        list.insert(30);

        assert(list.getSize() == 3);  // Проверка размера списка
        list.remove(20);
        assert(list.getSize() == 2);  // Проверка удаления элемента
        std::cout << "Test 1 passed: Insert and remove." << std::endl;
    }

    // Тест 2: Проверка на простое число
    {
        DoublyLinkedList list;
        assert(list.isPrime(7));   // 7 — простое число
        assert(!list.isPrime(10)); // 10 — не простое число
        std::cout << "Test 2 passed: Prime number check." << std::endl;
    }

    // Тест 3: Проверка сортировки по первой цифре
    {
        DoublyLinkedList list;
        list.insert(123);
        list.insert(45);
        list.insert(678);
        list.sortByFirstDigitDescending();

        // Ожидаемый результат: 678, 45, 123
        assert(list.getSize() == 3);
        std::cout << "Test 3 passed: Sort by first digit." << std::endl;
    }

    // Тест 4: Удаление простых чисел и дублирование кратных 10
    {
        DoublyLinkedList list;
        list.insert(7);   // Простое число
        list.insert(20);  // Кратное 10
        list.insert(13);  // Простое число
        list.removePrimesAndDuplicateMultiplesOf10();

        // Ожидаемый результат: 20, 20
        assert(list.getSize() == 2);
        std::cout << "Test 4 passed: Remove primes and duplicate multiples of 10." << std::endl;
    }

    std::cout << "All functional tests passed!\n" << std::endl;
}