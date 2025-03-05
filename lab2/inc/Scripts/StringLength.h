#pragma once

#include <string>

class StringLength {
public:
    static int calculateLength(const std::string& str);
private:
    static int recursiveLength(const std::string& str, int index);
};

