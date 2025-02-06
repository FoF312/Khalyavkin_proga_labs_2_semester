#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

#include "Node.h"
#include <vector>
#include <string>

class CircularDoublyLinkedList {
public:
    Node* dummy;

    CircularDoublyLinkedList();
    ~CircularDoublyLinkedList();

    void append(int data);
    void display();
    int countEndingWith2Or4();
    void sortByFirstDigitDescending();
    void removePrimesAndDuplicateMultiplesOf10();

private:
    bool isPrime(int n);
    void removeNode(Node* node);
    void clear();
};

#endif // CIRCULARDOUBLYLINKEDLIST_H