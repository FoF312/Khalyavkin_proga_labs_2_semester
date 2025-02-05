#pragma once

#include <cstdio>
#include "Chain.h"

class List {
private:
    Chain*  _head = nullptr;
    Chain*  _tail = nullptr;
    size_t _size = 0;
public:
    void addNode(int t);
    size_t getSize() {return _size;};
};
