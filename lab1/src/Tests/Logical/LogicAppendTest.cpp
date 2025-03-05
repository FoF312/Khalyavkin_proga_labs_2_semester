#include "../../../inc/Tests/Logical/LogicAppendTest.h"
#include "../../../inc/Containers/CircularDoublyLinkedList.h"
#include <cassert>
#include <iostream>

void LogicAppendTest::run() {
    CircularDoublyLinkedList list;
    list.append(5);
    list.append(10);

    assert(list.get(0) == 5);
    assert(list.get(1) == 10);

    std::cout << "LogicAppendTest passed!" << std::endl;
}