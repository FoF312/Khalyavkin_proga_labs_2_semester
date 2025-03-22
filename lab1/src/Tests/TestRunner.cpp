#include "../../inc/TestRunner.h"
#include "../../inc/Tests/Functional/DoublyLinkedListFunctionalTests.h"
#include "../../inc/Tests/Logical/DoublyLinkedListLogicalTests.h"

void TestRunner::runAllTests() {
    runFunctionalTests();
    runLogicalTests();
}

void TestRunner::runFunctionalTests() {
    DoublyLinkedListFunctionalTests::runAllTests();
}

void TestRunner::runLogicalTests() {
    DoublyLinkedListLogicalTests::runAllTests();
}