#pragma once
#include <vector>
#include <stdexcept>
#include "../TestRunner.h"
#include "../../VectorBool/VectorBool.h"

class VectorBoolLogicalTests {
public:
    static void runAll();
    
private:
    static void testStressScenario();
    static void testRealWorldUsage();
    static void testExceptionHandling();
};