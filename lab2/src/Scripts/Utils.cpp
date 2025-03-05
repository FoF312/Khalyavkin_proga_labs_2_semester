#include "../../inc/scripts/Utils.h"
#include <iostream>

void Utils::printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void Utils::printGrid(const std::vector<std::string>& grid) {
    for (const std::string& row : grid) {
        std::cout << row << std::endl;
    }
}