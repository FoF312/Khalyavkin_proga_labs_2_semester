#ifndef CUBE_H
#define CUBE_H

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

#endif // CUBE_H