#pragma once
#include "../../Matrix/Matrix.h"
#include "../TestMacros.h"

class MatrixLogicalTests {
public:
    static void runAll();
    
private:
    static void testMatrixProperties();
    static void testEdgeCases();
    static void testTypeSafety();
};