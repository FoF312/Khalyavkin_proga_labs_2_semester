#include "../../../inc/Tests/Functional/CountEndingWith2Or4Test.h"
#include "../../../inc/Containers/CircularDoublyLinkedList.h"
#include <cassert>
#include <iostream>

void CountEndingWith2Or4Test::run() {
    CircularDoublyLinkedList list;
    list.append(12);
    list.append(24);
    list.append(35);
    list.append(44);

    assert(list.countEndingWith2Or4() == 3);
    std::cout << "CountEndingWith2Or4Test passed!" << std::endl;
}