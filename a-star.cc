#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <algorithm>

struct Node {
    int x, y;
    double g, h;
    Node* parent;
    Node(int x, int y, double g, double h, Node* parent = nullptr)
        : x(x), y(y), g(g), h(h), parent(parent) {}
    double f() const { return g + h; }
};

struct CompareNode {
    bool operator()(const Node* a, const Node* b) const {
        return a->f() > b->f();
    }
};

double heuristic(int x1, int y1, int x2, int y2) {
    // Euclidean distance
    return std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

std::vector<std::pair<int, int>> get_neighbors(int x, int y, int rows, int cols, const std::vector<std::vector<int>>& grid) {
    std::vector<std::pair<int, int>> neighbors;
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 0)
            neighbors.emplace_back(nx, ny);
    }
    return neighbors;
}

std::vector<std::pair<int, int>> a_star(
    const std::vector<std::vector<int>>& grid,
    std::pair<int, int> start,
    std::pair<int, int> goal
) {
    int rows = grid.size(), cols = grid[0].size();
    std::priority_queue<Node*, std::vector<Node*>, CompareNode> open_set;
    std::unordered_map<int, Node*> all_nodes;
    auto hash = [cols](int x, int y) { return x * cols + y; };

    Node* start_node = new Node(start.first, start.second, 0, heuristic(start.first, start.second, goal.first, goal.second));
    open_set.push(start_node);
    all_nodes[hash(start.first, start.second)] = start_node;

    std::vector<std::vector<bool>> closed(rows, std::vector<bool>(cols, false));

    while (!open_set.empty()) {
        Node* current = open_set.top();
        open_set.pop();

        if (current->x == goal.first && current->y == goal.second) {
            std::vector<std::pair<int, int>> path;
            while (current) {
                path.emplace_back(current->x, current->y);
                current = current->parent;
            }
            std::reverse(path.begin(), path.end());
            for (auto& kv : all_nodes) delete kv.second;
            return path;
        }

        closed[current->x][current->y] = true;

        for (auto& neighbor : get_neighbors(current->x, current->y, rows, cols, grid)) {
            int nx = neighbor.first, ny = neighbor.second;
            if (closed[nx][ny]) continue;
            double tentative_g = current->g + 1;
            int hkey = hash(nx, ny);
            if (!all_nodes.count(hkey) || tentative_g < all_nodes[hkey]->g) {
                Node* neighbor_node = new Node(nx, ny, tentative_g, heuristic(nx, ny, goal.first, goal.second), current);
                open_set.push(neighbor_node);
                all_nodes[hkey] = neighbor_node;
            }
        }
    }
    for (auto& kv : all_nodes) delete kv.second;
    return {};
}

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };
    std::pair<int, int> start = {0, 0};
    std::pair<int, int> goal = {4, 4};
    auto path = a_star(grid, start, goal);
    if (!path.empty()) {
        std::cout << "Path found:\n";
        for (auto& p : path)
            std::cout << "(" << p.first << "," << p.second << ") ";
        std::cout << std::endl;
    } else {
        std::cout << "No path found.\n";
    }
    return 0;
}