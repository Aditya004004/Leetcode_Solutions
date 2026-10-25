class Solution {
public:
    int m, n;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void bfs(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dr[k];
                int ny = y + dc[k];

                if (nx >= 0 && ny >= 0 &&
                    nx < m && ny < n &&
                    grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0)
                bfs(grid, i, 0);

            if (grid[i][n - 1] == 0)
                bfs(grid, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0)
                bfs(grid, 0, j);

            if (grid[m - 1][j] == 0)
                bfs(grid, m - 1, j);
        }
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }

        return count;
    }
};