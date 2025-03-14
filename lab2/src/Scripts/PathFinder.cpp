#include "../../inc/scripts/PathFinder.h"
#include <queue>
#include <vector>
#include <climits>

bool PathFinder::isValid(int x, int y, int rows, int cols) {
    return x >= 0 && y >= 0 && x < rows && y < cols;
}

int PathFinder::findPath(const std::vector<std::string>& grid, 
                        std::vector<std::vector<bool>>& visited,
                        int x, int y, int endX, int endY) {
    // Базовые случаи
    if (!isValid(x, y, static_cast<int>(grid.size()), 
                static_cast<int>(grid[0].size())) || 
        grid[x][y] == '#' || visited[x][y]) {
        return INT_MAX;
    }
    
    if (x == endX && y == endY) {
        return 0;
    }

    visited[x][y] = true;
    
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    int minSteps = INT_MAX;
    
    for (int i = 0; i < 8; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        
        int steps = findPath(grid, visited, nextX, nextY, endX, endY);
        if (steps != INT_MAX) {
            minSteps = std::min(minSteps, steps + 1);
        }
    }
    
    visited[x][y] = false;  // backtracking
    return minSteps;
}

int PathFinder::findMinSteps(const std::vector<std::string>& grid) {
    int startX = -1, startY = -1;
    int endX = -1, endY = -1;

    for (int i = 0; i < static_cast<int>(grid.size()); i++) {
        for (int j = 0; j < static_cast<int>(grid[i].size()); j++) {
            if (grid[i][j] == 'S') {
                startX = i;
                startY = j;
            } else if (grid[i][j] == 'E') {
                endX = i;
                endY = j;
            }
        }
    }

    if (startX == -1 || startY == -1 || endX == -1 || endY == -1) {
        return -1;
    }

    std::vector<std::vector<bool>> visited(grid.size(), 
        std::vector<bool>(grid[0].size(), false));
    
    int result = findPath(grid, visited, startX, startY, endX, endY);
    return result == INT_MAX ? -1 : result;
}