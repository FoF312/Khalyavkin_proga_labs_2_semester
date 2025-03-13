#include "tests/TestRunner.h"
#include "TaskExecutor.h"
#include <iostream>

TestRunner testrunner;

void printTask() {
    std::cout << "=== Assignment ===" << std::endl;
    std::cout << "1. Cube: Calculate surface area, volume, and diagonal." << std::endl;
    std::cout << "==================" << std::endl;
}

void DoingProgramm() {
    TaskExecutor::runCubeTask();
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