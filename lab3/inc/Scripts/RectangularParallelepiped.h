#ifndef RECTANGULARPARALLELEPIPED_H
#define RECTANGULARPARALLELEPIPED_H

#include <cmath>

class RectangularParallelepiped {
private:
    double length;  // Длина
    double width;   // Ширина
    double height;  // Высота

public:
    // Конструктор
    RectangularParallelepiped(double l, double w, double h);

    // Методы
    double calculateSurfaceArea() const; // Площадь поверхности
    double calculateVolume() const;      // Объем
    double calculateDiagonal() const;    // Длина диагонали
};

#endif // RECTANGULARPARALLELEPIPED_H