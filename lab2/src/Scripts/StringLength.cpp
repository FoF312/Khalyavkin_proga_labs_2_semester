#include "../../inc/scripts/StringLength.h"

int StringLength::calculateLength(const std::string& str) {
    return recursiveLength(str, 0);
}

int StringLength::recursiveLength(const std::string& str, int index) {
    if (str[index] == '\0') {
        return 0;
    }
    return 1 + recursiveLength(str, index + 1);
}