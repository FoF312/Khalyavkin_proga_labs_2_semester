#pragma once

#include <cmath>

class Cube {
private:
    double side; 
public:  
    Cube(double s);
    double calculateSurfaceArea() const;
    double calculateVolume() const;
    double calculateDiagonal() const;
};
