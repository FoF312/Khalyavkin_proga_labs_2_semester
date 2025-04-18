#pragma once
#include <vector>
#include <stdexcept>
#include "../TestRunner.h"
#include "../../VectorBool/VectorBool.h"

class VectorBoolFunctionalTests {
public:
    static void runAll();
    
private:
    static void testBitMagic();
    static void testBoundaryConditions();
    static void testProxyBehavior();
};