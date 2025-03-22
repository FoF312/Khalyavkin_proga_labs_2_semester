#include "../inc/scripts/Cube.h"

Cube::Cube(double s) : side(std::abs(s)) {}

double Cube::calculateSurfaceArea() const {
    return 6 * side * side;
}

double Cube::calculateVolume() const {
    return side * side * side;
}

double Cube::calculateDiagonal() const {
    return side * std::sqrt(3);
}