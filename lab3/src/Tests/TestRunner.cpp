#include "../tests/TestRunner.h"
#include "../tests/Functional/CubeFunctionalTests.h"
#include "../tests/Logical/CubeLogicalTests.h"

void TestRunner::runAllTests() {
    runFunctionalTests();
    runLogicalTests();
}

void TestRunner::runFunctionalTests() {
    CubeFunctionalTests::runAllTests();
}

void TestRunner::runLogicalTests() {
    CubeLogicalTests::runAllTests();
}