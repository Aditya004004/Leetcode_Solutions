class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;

    bool dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n)
            return false;

        if (grid[r][c] == 1 || visited[r][c])
            return true;

        visited[r][c] = true;

        bool closed = true;

        if (r == 0 || c == 0 || r == m - 1 || c == n - 1)
            closed = false;

        bool up = dfs(grid, r - 1, c);
        bool down = dfs(grid, r + 1, c);
        bool left = dfs(grid, r, c - 1);
        bool right = dfs(grid, r, c + 1);

        return closed && up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (dfs(grid, i, j))
                        count++;
                }
            }
        }

        return count;
    }
};