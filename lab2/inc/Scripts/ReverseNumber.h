#pragma once

#include <string>

class ReverseNumber {
public:
    static long long reverse(long long number);

private:
    static long long reverseHelper(long long number, long long reversed);
};
