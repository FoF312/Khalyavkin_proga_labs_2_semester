#pragma once
#include "Matrix/Matrix.h"
#include "../TestMacros.h"
#include <sstream>

class MatrixFunctionalTests {
public:
    static void runAll();
    
private:
    static void testConstructors();
    static void testElementAccess();
    static void testArithmeticOperations();
    static void testIncrementOperators();
    static void testDeterminant();
    static void testIOOperations();
};