#include "../inc/scripts/DoublyLinkedList.h"
#include <algorithm>
#include <vector>

// Конструктор
DoublyLinkedList::DoublyLinkedList() : size(0) {
    dummy = new Node(-1);  // Фиктивный элемент
    dummy->next = dummy;
    dummy->prev = dummy;
}

// Деструктор
DoublyLinkedList::~DoublyLinkedList() {
    Node* current = dummy->next;
    while (current != dummy) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    delete dummy;
}

// Вставка элемента
void DoublyLinkedList::insert(int value) {
    Node* newNode = new Node(value);
    newNode->next = dummy;
    newNode->prev = dummy->prev;
    dummy->prev->next = newNode;
    dummy->prev = newNode;
    size++;
}

// Удаление элемента
void DoublyLinkedList::remove(int value) {
    Node* current = dummy->next;
    while (current != dummy) {
        if (current->data == value) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            size--;
            return;
        }
        current = current->next;
    }
}

// Вывод списка
void DoublyLinkedList::print() const {
    Node* current = dummy->next;
    while (current != dummy) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Проверка на простое число
bool DoublyLinkedList::isPrime(int n) const {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Проверка, заканчивается ли число на цифру
bool DoublyLinkedList::endsWithDigit(int number, int digit) const {
    return (number % 10) == digit;
}

// Получение первой цифры числа
int DoublyLinkedList::getFirstDigit(int number) const {
    while (number >= 10) {
        number /= 10;
    }
    return number;
}

// Сортировка по первой цифре по убыванию
void DoublyLinkedList::sortByFirstDigitDescending() {
    if (size < 2) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = dummy->next;
        while (current->next != dummy) {
            if (getFirstDigit(current->data) < getFirstDigit(current->next->data)) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Удаление простых чисел и дублирование чисел, кратных 10
void DoublyLinkedList::removePrimesAndDuplicateMultiplesOf10() {
    std::vector<int> toRemove;
    std::vector<int> toDuplicate;
    
    // Сначала найдем все числа для обработки
    Node* current = dummy->next;
    while (current != dummy) {
        if (isPrime(current->data)) {
            toRemove.push_back(current->data);
        } else if (current->data % 10 == 0) {
            toDuplicate.push_back(current->data);
        }
        current = current->next;
    }
    
    // Удалим простые числа
    for (int value : toRemove) {
        remove(value);
    }
    
    // Дублируем числа, кратные 10
    for (int value : toDuplicate) {
        insert(value);
    }
}

// Обработка последовательности
void DoublyLinkedList::processSequence() {
    int count = 0;
    Node* current = dummy->next;
    while (current != dummy) {
        if (endsWithDigit(current->data, 2) || endsWithDigit(current->data, 4)) {
            count++;
        }
        current = current->next;
    }

    if (count >= 3) {
        sortByFirstDigitDescending();
    } else {
        removePrimesAndDuplicateMultiplesOf10();
    }
}