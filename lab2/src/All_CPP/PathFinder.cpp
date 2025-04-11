#include "../inc/scripts/PathFinder.h"

int PathFinder::findMinSteps(const std::vector<std::string>& grid) {
    if (grid.empty()) return -1;

    int rows = grid.size();
    int cols = grid[0].size();

    std::pair<int, int> start, end;
    findStartAndEnd(grid, start, end);
    
    if (start.first == -1 || end.first == -1 || 
        grid[start.first][start.second] == '#' || 
        grid[end.first][end.second] == '#') {
        return -1;
    }

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    int minSteps = INT_MAX;
    
    dfs(grid, start.first, start.second, end.first, end.second, 0, visited, minSteps);
    
    return minSteps == INT_MAX ? -1 : minSteps;
}

void PathFinder::dfs(const std::vector<std::string>& grid, int x, int y, int endX, int endY, 
                    int steps, std::vector<std::vector<bool>>& visited, int& minSteps) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == '#' || visited[x][y]) {
        return;
    }
    
    if (x == endX && y == endY) {
        minSteps = std::min(minSteps, steps);
        return;
    }
    
    visited[x][y] = true;
    
    // Рекурсивно проверяем все направления
    dfs(grid, x - 1, y, endX, endY, steps + 1, visited, minSteps); // вверх
    dfs(grid, x + 1, y, endX, endY, steps + 1, visited, minSteps); // вниз
    dfs(grid, x, y - 1, endX, endY, steps + 1, visited, minSteps); // влево
    dfs(grid, x, y + 1, endX, endY, steps + 1, visited, minSteps); // вправо
    
    visited[x][y] = false; // откат для бэктрекинга
}

void PathFinder::findStartAndEnd(const std::vector<std::string>& grid, std::pair<int, int>& start, std::pair<int, int>& end) {
    bool foundStart = false, foundEnd = false;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == 'S') {
                start = {i, j};
                foundStart = true;
            } else if (grid[i][j] == 'E') {
                end = {i, j};
                foundEnd = true;
            }
        }
    }
    if (!foundStart || !foundEnd) {
        start = end = {-1, -1};
    }
}