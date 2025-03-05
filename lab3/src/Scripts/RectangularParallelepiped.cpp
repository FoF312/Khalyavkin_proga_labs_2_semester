#include "../inc/scripts/RectangularParallelepiped.h"

// Конструктор
RectangularParallelepiped::RectangularParallelepiped(double l, double w, double h)
    : length(std::abs(l)), width(std::abs(w)), height(std::abs(h)) {}

// Площадь поверхности
double RectangularParallelepiped::calculateSurfaceArea() const {
    return 2 * (length * width + width * height + height * length);
}

// Объем
double RectangularParallelepiped::calculateVolume() const {
    return length * width * height;
}

// Длина диагонали
double RectangularParallelepiped::calculateDiagonal() const {
    return std::sqrt(length * length + width * width + height * height);
}