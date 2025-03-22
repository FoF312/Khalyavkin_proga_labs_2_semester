#include "scripts/MyVector.h"
#include "tests/TestRunner.h"
#include <iostream>

TestRunner testrunner;

void printTask() {
    std::cout << "\n=== TASK DESCRIPTION ===\n";
    std::cout << "Implement a custom vector class (MyVector) that mimics std::vector for int.\n";
    std::cout << "Supported methods: push_back, insert, erase, resize, reserve, shrink_to_fit, etc.\n";
    std::cout << "========================\n\n";
}

void DoingProgramm() {
    MyVector vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Original vector: ";
    vec.print();

    vec.insert(1, 15);
    std::cout << "After insert: ";
    vec.print();

    vec.erase(2);
    std::cout << "After erase: ";
    vec.print();

    vec.resize(5, 42);
    std::cout << "After resize: ";
    vec.print();
}

bool CurrentInput(int choice) {
    if (choice == 1 || choice == 2) {
        return true;
    }
    std::cout << "\n INPUT ERROR\n";
    std::cout << "\n Select an operating mode:\n";
    std::cout << "1. Run tests\n";
    std::cout << "2. Run Program\n";
    std::cout << "Your choice: ";
    return false;
}

bool CurrentInputTests(int type) {
    return (type == 1 || type == 2 || type == 3 || type == 0);
}

void TestMenu() {
    std::cout << "\n Select the type of tests:\n";
    std::cout << "1. All tests\n";
    std::cout << "2. Logic tests\n";
    std::cout << "3. Functional tests\n";
    std::cout << "0. Back\n";
    std::cout << "Your choice: ";
    int type;
    std::cin >> type;

    while (!CurrentInputTests(type)) {
        std::cout << "\nERROR INPUT\n";
        std::cout << "\n Select the type of tests:\n";
        std::cout << "1. All tests\n";
        std::cout << "2. Logic tests\n";
        std::cout << "3. Functional tests\n";
        std::cout << "Your choice: ";
        std::cin >> type;
    }

    if (type == 1) {
        testrunner.runAllTests();
    } else if (type == 2) {
        testrunner.runLogicalTests();
    } else if (type == 3) {
        testrunner.runFunctionalTests();
    }
}

void Menu() {
    std::cout << "\n Select an operating mode:\n";
    std::cout << "1. Run tests\n";
    std::cout << "2. Run Program\n";
    std::cout << "Your choice: ";
    int choice;
    std::cin >> choice;

    while (!CurrentInput(choice)) {
        std::cin >> choice;
    }

    if (choice == 1) {
        TestMenu();
    } else if (choice == 2) {
        DoingProgramm();
    }
}

int main() {
    printTask();
    Menu();
    return 0;
}