#include "scripts/PathFinder.h"
#include <queue>
#include <vector>
#include <climits>

bool PathFinder::isValid(int x, int y, int rows, int cols) {
    return x >= 0 && y >= 0 && x < rows && y < cols;
}

int PathFinder::bfs(const std::vector<std::string>& grid, int startX, int startY, int endX, int endY) {
    size_t rows = grid.size(); // Используем size_t
    size_t cols = grid[0].size(); // Используем size_t

    std::vector<std::vector<int>> dist(rows, std::vector<int>(cols, INT_MAX));
    std::queue<std::pair<int, int>> q;

    dist[startX][startY] = 0;
    q.push({startX, startY});

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        if (x == endX && y == endY) {
            return dist[x][y];
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny, static_cast<int>(rows), static_cast<int>(cols)) && grid[nx][ny] != '#' && dist[nx][ny] == INT_MAX) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int PathFinder::findMinSteps(const std::vector<std::string>& grid) {
    int startX = -1, startY = -1;
    int endX = -1, endY = -1;

    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[i].size(); j++) {
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

    return bfs(grid, startX, startY, endX, endY);
}