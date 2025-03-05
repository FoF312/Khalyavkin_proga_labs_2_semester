#include "../../../inc/Tests/Functional/AppendTest.h"
#include "../../../inc/Containers/CircularDoublyLinkedList.h"
#include <cassert>
#include <iostream>

void AppendTest::run() {
    CircularDoublyLinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);

    assert(list.countEndingWith2Or4() == 0); // Ни один элемент не заканчивается на 2 или 4
    std::cout << "AppendTest passed!" << std::endl;
}