#include "../../inc/tests/TestRunner.h"

std::vector<TestRunner::TestResult> TestRunner::testResults;

void TestRunner::runTest(const std::function<void()>& test, const std::string& testName) {
    try {
        test();
        testResults.push_back({testName, true, ""});
        std::cout << "[PASSED] " << testName << "\n";
    } catch (const std::exception& e) {
        testResults.push_back({testName, false, e.what()});
        std::cout << "[FAILED] " << testName << " - " << e.what() << "\n";
    } catch (...) {
        testResults.push_back({testName, false, "Unknown error"});
        std::cout << "[FAILED] " << testName << " - Unknown error\n";
    }
}

void TestRunner::printStats() {
    int passed = 0;
    int failed = 0;
    
    for (const auto& result : testResults) {
        if (result.passed) {
            passed++;
        } else {
            failed++;
        }
    }
    
    std::cout << "\n=== TEST SUMMARY ===\n";
    std::cout << "Total tests: " << (passed + failed) << "\n";
    std::cout << "Passed: " << passed << "\n";
    std::cout << "Failed: " << failed << "\n";
    
    if (failed > 0) {
        std::cout << "\nFailed tests:\n";
        for (const auto& result : testResults) {
            if (!result.passed) {
                std::cout << " - " << result.name << ": " << result.error << "\n";
            }
        }
    }
    
    std::cout << "===================\n";
}