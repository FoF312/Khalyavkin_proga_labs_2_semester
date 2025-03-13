#include "../inc/TaskExecutor.h"
#include "../inc/scripts/Cube.h"
#include <iostream>

void TaskExecutor::printAssignment() {
    std::cout << "=== Assignment ===" << std::endl;
    std::cout << "1. Cube: Calculate surface area, volume, and diagonal." << std::endl;
    std::cout << "==================" << std::endl;
}

void TaskExecutor::runCubeTask() {
    std::cout << "=== Cube Task ===" << std::endl;

    double side;
    std::cout << "Enter the side length of the cube: ";
    std::cin >> side;

    Cube cube(side);

    std::cout << "Surface Area: " << cube.calculateSurfaceArea() << std::endl;
    std::cout << "Volume: " << cube.calculateVolume() << std::endl;
    std::cout << "Diagonal: " << cube.calculateDiagonal() << std::endl;
}