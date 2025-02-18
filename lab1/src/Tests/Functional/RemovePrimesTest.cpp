#include "../../../inc/Tests/Functional/RemovePrimesTest.h"
#include "../../../inc/Containers/CircularDoublyLinkedList.h"
#include <cassert>
#include <iostream>

void RemovePrimesTest::run() {
    CircularDoublyLinkedList list;
    list.append(7);  // Простое число
    list.append(10); // Кратное 10
    list.append(13); // Простое число
    list.append(20); // Кратное 10

    list.removePrimesAndDuplicateMultiplesOf10();

    assert(list.countEndingWith2Or4() == 0); // Ни один элемент не заканчивается на 2 или 4
    std::cout << "RemovePrimesTest passed!" << std::endl;
}