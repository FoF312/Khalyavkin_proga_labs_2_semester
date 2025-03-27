#pragma once
#include <iostream>
#include "Functional/MatrixFunctionalTests.h"
#include "Logical/MatrixLogicalTests.h"

class TestRunner {
public:
    void runAllTests() {
        std::cout << "=== RUNNING ALL TESTS ===" << std::endl;
        runFunctionalTests();
        runLogicalTests();
        std::cout << "ALL TESTS PASSED!" << std::endl;
    }
    
    void runFunctionalTests() {
        std::cout << "=== RUNNING FUNCTIONAL TESTS ===" << std::endl;
        MatrixFunctionalTests::runAll();
        std::cout << "FUNCTIONAL TESTS PASSED!" << std::endl;
    }
    
    void runLogicalTests() {
        std::cout << "=== RUNNING LOGICAL TESTS ===" << std::endl;
        MatrixLogicalTests::runAll();
        std::cout << "LOGICAL TESTS PASSED!" << std::endl;
    }
};