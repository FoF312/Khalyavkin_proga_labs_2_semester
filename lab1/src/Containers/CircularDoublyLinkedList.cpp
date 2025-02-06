#include "../inc/Containers/CircularDoublyLinkedList.h"
#include <iostream>
#include <algorithm>
#include <cmath>

Node::Node(int val) : data(val), next(nullptr), prev(nullptr) {}

CircularDoublyLinkedList::CircularDoublyLinkedList() {
    dummy = new Node(0);
    dummy->next = dummy;
    dummy->prev = dummy;
}

CircularDoublyLinkedList::~CircularDoublyLinkedList() {
    clear();
    delete dummy;
}

void CircularDoublyLinkedList::append(int data) {
    if (data <= 0) {
        std::cout << "Only natural numbers are allowed. Skipping " << data << std::endl;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = dummy;
    newNode->prev = dummy->prev;
    dummy->prev->next = newNode;
    dummy->prev = newNode;
}

void CircularDoublyLinkedList::display() {
    Node* current = dummy->next;
    if (current == dummy) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    while (current != dummy) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "dummy" << std::endl;
}

int CircularDoublyLinkedList::countEndingWith2Or4() {
    int count = 0;
    Node* current = dummy->next;
    while (current != dummy) {
        int lastDigit = current->data % 10;
        if (lastDigit == 2 || lastDigit == 4) {
            count++;
        }
        current = current->next;
    }
    return count;
}

void CircularDoublyLinkedList::sortByFirstDigitDescending() {
    std::vector<Node*> nodes;
    Node* current = dummy->next;
    while (current != dummy) {
        nodes.push_back(current);
        current = current->next;
    }

    std::sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
        std::string strA = std::to_string(a->data);
        std::string strB = std::to_string(b->data);
        return strA[0] > strB[0];
    });

    // Rebuild the list with sorted nodes
    dummy->next = dummy;
    dummy->prev = dummy;
    for (Node* node : nodes) {
        node->prev = dummy->prev;
        node->next = dummy;
        dummy->prev->next = node;
        dummy->prev = node;
    }
}

bool CircularDoublyLinkedList::isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void CircularDoublyLinkedList::removePrimesAndDuplicateMultiplesOf10() {
    Node* current = dummy->next;
    std::vector<int> multiplesOf10;

    while (current != dummy) {
        Node* nextNode = current->next;

        if (isPrime(current->data)) {
            removeNode(current);
        }
        else if (current->data % 10 == 0) {
            multiplesOf10.push_back(current->data);
        }
        current = nextNode;
    }

    for (int multiple : multiplesOf10) {
        append(multiple);
    }
}

void CircularDoublyLinkedList::removeNode(Node* node) {
    Node* prevNode = node->prev;
    Node* nextNode = node->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete node;
}

void CircularDoublyLinkedList::clear() {
    Node* current = dummy->next;
    while (current != dummy) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    dummy->next = dummy;
    dummy->prev = dummy;
}