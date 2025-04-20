#include "../inc/Tests/Logical/VectorBoolLogicalTests.h"
#include "../inc/Tests/TestRunner.h"
#include "../inc/VectorBool/VectorBool.h"
#include <cassert>

void VectorBoolLogicalTests::runAll() {
    TestRunner::runTest(testStressScenario, "Stress scenario");
    TestRunner::runTest(testRealWorldUsage, "Real-world usage simulation");
    TestRunner::runTest(testExceptionHandling, "Exception handling");
}

void VectorBoolLogicalTests::testStressScenario() {
    VectorBool vec;
    const int ITERATIONS = 1000;
    
    // Чередуем добавление, вставку и удаление
    for (int i = 0; i < ITERATIONS; ++i) {
        vec.push_back(i % 2 == 0);
        if (i % 5 == 0 && vec.size() > 0) {
            vec.insert(i % vec.size(), i % 3 == 0);
        }
        if (i % 7 == 0 && vec.size() > 0) {
            vec.erase(i % vec.size());
        }
    }
    
    // Проверяем целостность данных
    assert(vec.size() >= ITERATIONS / 2); 
    for (size_t i = 0; i < vec.size(); ++i) {        
        bool val = vec[i];
        (void)val; 
    }
}

void VectorBoolLogicalTests::testRealWorldUsage() {
    // Симуляция реального использования - фильтр четных чисел
    VectorBool evenFilter;
    const int NUMBERS = 50;
    
    for (int i = 0; i < NUMBERS; ++i) {
        evenFilter.push_back(i % 2 == 0);
    }
    
    int evenCount = 0;
    for (int i = 0; i < NUMBERS; ++i) {
        if (evenFilter[i]) {
            evenCount++;
        }
    }
    
    assert(evenCount == NUMBERS / 2);
    
    // Сохраняем размер перед операциями
    size_t originalSize = evenFilter.size();
    
    evenFilter[30] = false;
    evenFilter.insert(10, true);
    evenFilter.erase(15);
    
    // Проверяем, что размер изменился на 1 (insert увеличивает на 1, erase уменьшает на 1)
    assert(evenFilter.size() == originalSize);
}

void VectorBoolLogicalTests::testExceptionHandling() {
    VectorBool vec;
    vec.push_back(true);
    vec.push_back(false);
    vec.push_back(true);
    
    // Проверяем исключения при неверных индексах
    bool caught = false;
    try {
        vec.insert(10, true);
    } catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);
    
    caught = false;
    try {
        vec.erase(10);
    } catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);
    
    // Проверяем исключения при доступе к несуществующим элементам через оператор []
    caught = false;
    try {
        bool val = vec[10];
        (void)val; // Предотвращаем предупреждение о неиспользуемой переменной
    } catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);
    
    // Проверяем, что после исключений состояние не изменилось
    assert(vec.size() == 3);
    assert(vec[0] == true && vec[1] == false && vec[2] == true);
}