#include "../inc/scripts/PathFinder.h"

int PathFinder::findMinSteps(const std::vector<std::string>& grid) {
    if (grid.empty()) return -1;

    int rows = grid.size();
    int cols = grid[0].size();

    std::pair<int, int> start, end;
    findStartAndEnd(grid, start, end);
    
    // Проверяем, что начальная и конечная точки найдены и достижимы
    if (start.first == -1 || end.first == -1 || 
        grid[start.first][start.second] == '#' || 
        grid[end.first][end.second] == '#') {
        return -1;
    }

    // Направления для движения (только вверх, вниз, влево, вправо)
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    // Очередь для BFS
    std::queue<std::pair<int, int>> q;
    q.push(start);

    // Массив для хранения количества шагов
    std::vector<std::vector<int>> steps(rows, std::vector<int>(cols, -1));
    steps[start.first][start.second] = 0;

    // BFS
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        // Если достигли конечной точки
        if (x == end.first && y == end.second) {
            return steps[x][y];
        }

        // Проверяем все возможные направления
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Проверяем, что новая позиция в пределах сетки и не является стеной
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] != '#' && steps[nx][ny] == -1) {
                steps[nx][ny] = steps[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1; // Путь не найден
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
        start = end = {-1, -1};  // Установка недопустимых координат
    }
}