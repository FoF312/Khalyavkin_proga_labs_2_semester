#pragma once

#include <vector>
#include <string>

class PathFinder {
public:
    static int findMinSteps(const std::vector<std::string>& grid);
private:
    static bool isValid(int x, int y, int rows, int cols);
    static int bfs(const std::vector<std::string>& grid, int startX, int startY, int endX, int endY);
};

