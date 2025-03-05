#ifndef TESTRUNNER_H
#define TESTRUNNER_H

class TestRunner {
public:
    // Запуск всех тестов
    void runAllTests();

    // Запуск всех функциональных тестов
    void runFunctionalTests();

    // Запуск всех логических тестов
    void runLogicalTests();

    // Запуск отдельных тестов
    void runAppendTest();
    void runRemovePrimesTest();
    void runSortTest();
    void runCountEndingWith2Or4Test();
    void runLogicAppendTest();
    void runLogicRemovePrimesTest();
    void runLogicSortingTest();
};

#endif // TESTRUNNER_H