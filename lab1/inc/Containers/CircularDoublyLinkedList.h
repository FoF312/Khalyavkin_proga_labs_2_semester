#pragma once
#include <vector>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val);
};

class CircularDoublyLinkedList {
private:
    Node* dummy;
    bool isPrime(int n);
    void removeNode(Node* node);

public:
    CircularDoublyLinkedList();
    ~CircularDoublyLinkedList();
    void append(int data);
    void display();
    int countEndingWith2Or4();
    void sortByFirstDigitDescending();
    void removePrimesAndDuplicateMultiplesOf10();
    void clear();
    int get(int index) const {
        Node* current = dummy->next;
        for(int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
};