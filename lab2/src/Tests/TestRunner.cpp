#include "../tests/TestRunner.h"
#include "../tests/Functional/ReverseNumberFunctionalTests.h"
#include "../tests/Functional/QuickSortFunctionalTests.h"
#include "../tests/Functional/PathFinderFunctionalTests.h"
#include "../tests/Logical/ReverseNumberLogicalTests.h"
#include "../tests/Logical/QuickSortLogicalTests.h"
#include "../tests/Logical/PathFinderLogicalTests.h"

void TestRunner::runAllTests() {
    runFunctionalTests();
    runLogicalTests();
}

void TestRunner::runFunctionalTests() {
    ReverseNumberFunctionalTests::runAllTests();
    QuickSortFunctionalTests::runAllTests();
    PathFinderFunctionalTests::runAllTests();
}

void TestRunner::runLogicalTests() {
    ReverseNumberLogicalTests::runAllTests();
    QuickSortLogicalTests::runAllTests();
    PathFinderLogicalTests::runAllTests();
}