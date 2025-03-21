#include "../inc/tests/Logical/DoublyLinkedListLogicalTests.h"
#include "../../inc/scripts/DoublyLinkedList.h"
#include <cassert>
#include <iostream>

void DoublyLinkedListLogicalTests::runAllTests() {
    std::cout << "\n=== Running Logical Tests ===" << std::endl;

    // Тест 1: Обработка последовательности с >= 3 числами, оканчивающимися на 2 или 4
    {
        DoublyLinkedList list;
        list.insert(12);  
        list.insert(34);  
        list.insert(56);  
        list.insert(22);  
        list.processSequence();

        assert(list.getSize() == 4);
        std::cout << "Test 1 passed: Process sequence with >= 3 numbers ending with 2 or 4." << std::endl;
    }

    // Тест 2: Обработка последовательности с < 3 числами, оканчивающимися на 2 или 4
    {
        DoublyLinkedList list;
        list.insert(12);  
        list.insert(35);  
        list.insert(7);   
        list.insert(20);  
        list.processSequence();

        assert(list.getSize() == 4);  
        std::cout << "Test 2 passed: Process sequence with < 3 numbers ending with 2 or 4." << std::endl;
    }

    // Тест 3: Обработка пустой последовательности
    {
        DoublyLinkedList list;
        list.processSequence();

        assert(list.getSize() == 0);
        std::cout << "Test 3 passed: Process empty sequence." << std::endl;
    }

    std::cout << "All logical tests passed!\n" << std::endl;
}