#pragma once

#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* dummy;  // Фиктивный элемент
    size_t size;  // Размер списка

    // Вспомогательные методы
    bool endsWithDigit(int number, int digit) const;
    int getFirstDigit(int number) const;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Основные методы
    void insert(int value);
    void remove(int value);
    void print() const;
    size_t getSize() const { return size; }
    bool isPrime(int n) const;

    // Методы для задания
    void processSequence();
    void sortByFirstDigitDescending();
    void removePrimesAndDuplicateMultiplesOf10();
};