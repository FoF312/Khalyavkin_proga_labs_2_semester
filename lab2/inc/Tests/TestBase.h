#pragma once
#include <iostream>
#include <cxxabi.h>

class TestBase{
public:
    virtual bool exec() = 0;

    std::string getTestName() const {
        const char* mangledName = typeid(*this).name();
        int status = 0;
        std::unique_ptr<char, void(*)(void*)> demangledName(
                abi::__cxa_demangle(mangledName, nullptr, nullptr, &status),
                std::free
        );
        return status == 0 ? demangledName.get() : mangledName;
    }
};