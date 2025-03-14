#pragma once

#include <vector>
#include <string>
#include <queue>
#include <utility>

class PathFinder {
public:
    static int findMinSteps(const std::vector<std::string>& grid);

private:
    static void findStartAndEnd(const std::vector<std::string>& grid, std::pair<int, int>& start, std::pair<int, int>& end);
};