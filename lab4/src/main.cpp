#include "scripts/BigInt.h"
#include "tests/TestRunner.h"
#include <iostream>

TestRunner testrunner;

void printTask() {
    std::cout << "=== Assignment ===" << std::endl;
    std::cout << "1. BigInt: Perform operations with large integers." << std::endl;
    std::cout << "==================" << std::endl;
}

void DoingProgramm() {
    std::cout << "\n=== BigInt Operations ===" << std::endl;

    std::string num1Str, num2Str;
    std::cout << "Enter the first number: ";
    std::cin >> num1Str;
    std::cout << "Enter the second number: ";
    std::cin >> num2Str;

    BigInt num1(num1Str);
    BigInt num2(num2Str);

    std::cout << "\nResults:" << std::endl;
    std::cout << "Sum: " << num1 + num2 << std::endl;
    std::cout << "Product: " << num1 * num2 << std::endl;
    std::cout << "Comparison (num1 < num2): " << (num1 < num2 ? "true" : "false") << std::endl;
    std::cout << "Comparison (num1 == num2): " << (num1 == num2 ? "true" : "false") << std::endl;
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