#include "../inc/scripts/PathFinder.h"
#include <queue>
#include <vector>
#include <string>

int PathFinder::findMinSteps(const std::vector<std::string>& grid) {
    if (grid.empty()) return -1;

    size_t rows = grid.size();
    size_t cols = grid[0].size();

    int startX = -1, startY = -1, endX = -1, endY = -1;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (grid[i][j] == 'S') {
                startX = static_cast<int>(i);
                startY = static_cast<int>(j);
            } else if (grid[i][j] == 'E') {
                endX = static_cast<int>(i);
                endY = static_cast<int>(j);
            }
        }
    }

    if (startX == -1 || startY == -1 || endX == -1 || endY == -1) {
        return -1; 
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    std::queue<std::pair<int, int>> q;
    q.push({startX, startY});

    std::vector<std::vector<int>> steps(rows, std::vector<int>(cols, -1));
    steps[startX][startY] = 0;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        if (x == endX && y == endY) {
            return steps[x][y];
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            
            if (nx >= 0 && nx < static_cast<int>(rows) && ny >= 0 && ny < static_cast<int>(cols) && grid[nx][ny] != '#' && steps[nx][ny] == -1) {
                steps[nx][ny] = steps[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1; 
}