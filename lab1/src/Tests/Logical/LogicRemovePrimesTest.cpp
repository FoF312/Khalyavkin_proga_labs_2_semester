#include "../../../inc/Tests/Logical/LogicRemovePrimesTest.h"
#include "../../../inc/Containers/CircularDoublyLinkedList.h"
#include <cassert>
#include <iostream>

void LogicRemovePrimesTest::run() {
    CircularDoublyLinkedList list;
    list.append(7);  // Простое число
    list.append(10); // Кратное 10
    list.append(13); // Простое число

    list.removePrimesAndDuplicateMultiplesOf10();

    assert(list.get(0) == 10);
    assert(list.get(1) == 10); // Дубликат

    std::cout << "LogicRemovePrimesTest passed!" << std::endl;
}