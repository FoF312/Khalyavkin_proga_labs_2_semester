#include "../../../inc/Tests/Logical/LogicSortingTest.h"
#include "../../../inc/Containers/CircularDoublyLinkedList.h"
#include <cassert>
#include <iostream>

void LogicSortingTest::run() {
    CircularDoublyLinkedList list;
    list.append(123);
    list.append(45);
    list.append(678);

    list.sortByFirstDigitDescending();

    assert(list.get(0) == 678);
    assert(list.get(1) == 45);
    assert(list.get(2) == 123);

    std::cout << "LogicSortingTest passed!" << std::endl;
}