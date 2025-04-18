#pragma once
#include <functional>
#include <string>
#include <iostream>
#include <vector>

class TestRunner {
public:
    static void runTest(const std::function<void()>& test, const std::string& testName);
    
    template<typename TestClass>
    static void runTestClass(void (TestClass::*testMethod)(), const std::string& className) {
        try {
            TestClass testInstance;
            (testInstance.*testMethod)();
            std::cout << "[PASSED] " << className << "\n";
        } catch (const std::exception& e) {
            std::cout << "[FAILED] " << className << " - " << e.what() << "\n";
        } catch (...) {
            std::cout << "[FAILED] " << className << " - Unknown error\n";
        }
    }

    static void printStats();
    
private:
    struct TestResult {
        std::string name;
        bool passed;
        std::string error;
    };
    
    static std::vector<TestResult> testResults;
};