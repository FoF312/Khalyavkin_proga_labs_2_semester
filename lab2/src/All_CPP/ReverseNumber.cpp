#include "../inc/scripts/ReverseNumber.h"

long long ReverseNumber::reverse(long long number) {
    return reverseHelper(number, 0);
}

long long ReverseNumber::reverseHelper(long long number, long long reversed) {
    if (number == 0) {
        return reversed;
    }
    return reverseHelper(number / 10, reversed * 10 + number % 10);
}