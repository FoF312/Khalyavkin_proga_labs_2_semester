#pragma once

#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <climits>

class PathFinder {
public:
    static int findMinSteps(const std::vector<std::string>& grid);

private:
    static void findStartAndEnd(const std::vector<std::string>& grid, std::pair<int, int>& start, std::pair<int, int>& end);
    static void dfs(const std::vector<std::string>& grid, int x, int y, int endX, int endY, 
                   int steps, std::vector<std::vector<bool>>& visited, int& minSteps);
};