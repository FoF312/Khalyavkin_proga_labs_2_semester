#include "../inc/TaskExecutor.h"
#include "../inc/scripts/RectangularParallelepiped.h"
#include <iostream>

void TaskExecutor::printAssignment() {
    std::cout << "=== Assignment ===" << std::endl;
    std::cout << "1. Rectangular Parallelepiped: Calculate surface area, volume, and diagonal." << std::endl;
    std::cout << "==================" << std::endl;
}

void TaskExecutor::runRectangularParallelepipedTask() {
    std::cout << "=== Rectangular Parallelepiped Task ===" << std::endl;

    double length, width, height;
    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "Enter width: ";
    std::cin >> width;
    std::cout << "Enter height: ";
    std::cin >> height;

    RectangularParallelepiped parallelepiped(length, width, height);

    std::cout << "Surface Area: " << parallelepiped.calculateSurfaceArea() << std::endl;
    std::cout << "Volume: " << parallelepiped.calculateVolume() << std::endl;
    std::cout << "Diagonal: " << parallelepiped.calculateDiagonal() << std::endl;
}