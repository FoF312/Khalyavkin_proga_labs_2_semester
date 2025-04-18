#include "../tests/TestRunner.h"
#include "../tests/Functional/MyVectorFunctionalTests.h"
#include "../tests/Logical/MyVectorLogicalTests.h"

void TestRunner::runAllTests() {
    runFunctionalTests();
    runLogicalTests();
}

void TestRunner::runFunctionalTests() {
    MyVectorFunctionalTests::runAllTests();
}

void TestRunner::runLogicalTests() {
    MyVectorLogicalTests::runAllTests();
}