#pragma once
#include <iostream>
#include <stdexcept>

#define ASSERT(condition) \
    if (!(condition)) { \
        std::cerr << "Assertion failed: " << #condition << std::endl; \
        throw std::runtime_error("Test failed"); \
    }

#define ASSERT_THROWS(expression, exception_type) \
    try { \
        expression; \
        std::cerr << "Expected exception " << #exception_type << " but none was thrown" << std::endl; \
        throw std::runtime_error("Test failed"); \
    } catch (const exception_type&) { \
        /* Exception caught as expected */ \
    } 