#include "../../inc/tests/TestRunner.h"
#include "../../inc/tests/Functional/StringLengthFunctionalTests.h"
#include "../../inc/tests/Functional/QuickSortFunctionalTests.h"
#include "../../inc/tests/Functional/PathFinderFunctionalTests.h"
#include "../../inc/tests/Logical/StringLengthLogicalTests.h"
#include "../../inc/tests/Logical/QuickSortLogicalTests.h"
#include "../../inc/tests/Logical/PathFinderLogicalTests.h"

void TestRunner::runAllTests() {
    runFunctionalTests();
    runLogicalTests();
}

void TestRunner::runFunctionalTests() {
    StringLengthFunctionalTests::runAllTests();
    QuickSortFunctionalTests::runAllTests();
    PathFinderFunctionalTests::runAllTests();
}

void TestRunner::runLogicalTests() {
    StringLengthLogicalTests::runAllTests();
    QuickSortLogicalTests::runAllTests();
    PathFinderLogicalTests::runAllTests();
}