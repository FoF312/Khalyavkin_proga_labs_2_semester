#include "../tests/TestRunner.h"
#include "../tests/Functional/RectangularParallelepipedFunctionalTests.h"
#include "../tests/Logical/RectangularParallelepipedLogicalTests.h"

void TestRunner::runAllTests() {
    runFunctionalTests();
    runLogicalTests();
}

void TestRunner::runFunctionalTests() {
    RectangularParallelepipedFunctionalTests::runAllTests();
}

void TestRunner::runLogicalTests() {
    RectangularParallelepipedLogicalTests::runAllTests();
}