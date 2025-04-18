#include "../inc/Tests/Functional/VectorBoolFunctionalTests.h"
#include "../inc/Tests/TestRunner.h"
#include "../inc/VectorBool/VectorBool.h"
#include <cassert>

void VectorBoolFunctionalTests::runAll() {
    TestRunner::runTest(testBitMagic, "Bit magic operations");
    TestRunner::runTest(testBoundaryConditions, "Boundary conditions");
    TestRunner::runTest(testProxyBehavior, "Proxy object behavior");
}

void VectorBoolFunctionalTests::testBitMagic() {
    VectorBool vec;
    // Проверяем, что биты действительно упаковываются
    for (int i = 0; i < 16; ++i) {
        vec.push_back(i % 3 == 0);
    }
    
    // Проверяем несколько значений
    assert(vec[0] == true);
    assert(vec[1] == false);
    assert(vec[3] == true);
    assert(vec[15] == false);
    
    // Меняем биты в середине байта
    vec[4] = true;
    vec[5] = vec[4];
    assert(vec[5] == true);
}

void VectorBoolFunctionalTests::testBoundaryConditions() {
    VectorBool vec(8, true);
    // Граничные условия внутри байта
    vec[7] = false;
    assert(vec[6] == true && vec[7] == false);
    
    // Переход между байтами
    vec.push_back(false);
    assert(vec.size() == 9);
    assert(vec[8] == false);
    
    // Изменение последнего бита
    vec[8] = true;
    assert(vec[8] == true);
}

void VectorBoolFunctionalTests::testProxyBehavior() {
    VectorBool vec = {true, false, true};
    
    // Проверяем работу прокси-объекта
    bool value1 = vec[1]; // operator bool()
    assert(value1 == false);
    
    vec[1] = true; // operator=
    assert(vec[1] == true);
    
    // Каскадное присваивание
    vec[0] = vec[1] = false;
    assert(vec[0] == false && vec[1] == false);
}