#include "../inc/TestRunner.h"
#include <iostream>
#include "Tests/Functional/AppendTest.h"
#include "Tests/Functional/RemovePrimesTest.h"
#include "Tests/Functional/SortTest.h"
#include "Tests/Functional/CountEndingWith2Or4Test.h"
#include "Tests/Logical/LogicAppendTest.h"
#include "Tests/Logical/LogicRemovePrimesTest.h"
#include "Tests/Logical/LogicSortingTest.h"

// Запуск всех тестов
void TestRunner::runAllTests() {
    runFunctionalTests();
    runLogicalTests();
    std::cout << "All tests passed!" << std::endl;
}

// Запуск всех функциональных тестов
void TestRunner::runFunctionalTests() {
    runAppendTest();
    runRemovePrimesTest();
    runSortTest();
    runCountEndingWith2Or4Test();
    std::cout << "All functional tests passed!" << std::endl;
}

// Запуск всех логических тестов
void TestRunner::runLogicalTests() {
    runLogicAppendTest();
    runLogicRemovePrimesTest();
    runLogicSortingTest();
    std::cout << "All logical tests passed!" << std::endl;
}

// Запуск отдельных тестов
void TestRunner::runAppendTest() {
    AppendTest appendTest;
    appendTest.run();
}

void TestRunner::runRemovePrimesTest() {
    RemovePrimesTest removePrimesTest;
    removePrimesTest.run();
}

void TestRunner::runSortTest() {
    SortTest sortTest;
    sortTest.run();
}

void TestRunner::runCountEndingWith2Or4Test() {
    CountEndingWith2Or4Test countTest;
    countTest.run();
}

void TestRunner::runLogicAppendTest() {
    LogicAppendTest logicAppendTest;
    logicAppendTest.run();
}

void TestRunner::runLogicRemovePrimesTest() {
    LogicRemovePrimesTest logicRemovePrimesTest;
    logicRemovePrimesTest.run();
}

void TestRunner::runLogicSortingTest() {
    LogicSortingTest logicSortingTest;
    logicSortingTest.run();
}