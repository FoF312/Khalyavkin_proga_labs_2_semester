//
// Created by Антон Гломадов on 17.01.2025.
//

#include "../../inc/Containers/List.h"

void List::addNode(int t) {
    _tail->_next = new Chain(t);
    _tail = _tail->_next;
}
