#include "../inc/Tests/TestRunner.h"

void TestRunner::runFunctionalTests() {
    std::cout << "\n--- Starting Functional Tests ---\n";
    MatrixFunctionalTests::runAll();
    std::cout << "--- Functional Tests Completed ---\n";
}

void TestRunner::runLogicalTests() {
    std::cout << "\n--- Starting Logical Tests ---\n";
    MatrixLogicalTests::runAll();
    std::cout << "--- Logical Tests Completed ---\n";
}

