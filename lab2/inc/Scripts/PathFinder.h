#pragma once

#include <vector>
#include <string>

class PathFinder {
public:
    int findMinSteps(const std::vector<std::string>& grid);
private:
    bool isValid(int x, int y, int rows, int cols);
    int findPath(const std::vector<std::string>& grid, 
                 std::vector<std::vector<bool>>& visited,
                 int x, int y, int endX, int endY);
};

