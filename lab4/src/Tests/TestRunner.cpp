#include "TestRunner.h"
#include "tests/Functional/BigIntFunctionalTests.h"
#include "tests/Logical/BigIntLogicalTests.h"

void TestRunner::runAllTests() {
    runFunctionalTests();
    runLogicalTests();
}

void TestRunner::runFunctionalTests() {
    BigIntFunctionalTests::runAllTests();
}

void TestRunner::runLogicalTests() {
    BigIntLogicalTests::runAllTests();
}